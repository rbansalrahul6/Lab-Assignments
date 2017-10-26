import java.util.*;
class DFA
{
	public ArrayList<Character> alphabet;
	public ArrayList<State[]> transTable;
	public Map<Set<State>,State> DFAStateSet;
	public State start;

	public DFA(){};
	public DFA(ArrayList<Character> alpha,Map<Set<State>,State> mapping,ArrayList<State[]> table,State s)
	{
		alphabet = alpha;
		DFAStateSet = mapping;
		transTable = table;
		start = s;
	}

	void simulate(String q)
	{
		State temp = start;
		for(int i=0;i<q.length();i++)
		{
			temp = transTable.get(temp.num)[alphabet.indexOf(q.charAt(i))];
		}
		if(temp.isEnd)
			System.out.println("string accepted by DFA");
		else
			System.out.println("string rejected by DFA");
	}

	void display()
	{
		System.out.println("** Transition function for DFA **");
		int stateNum = 0;
		for(State[] row : transTable)
		{
			System.out.print(stateNum + ": ");
			for(int i=0;i<row.length;i++)
				System.out.print(alphabet.get(i) + "," + row[i].num + " ");
			System.out.println();
			stateNum++;
		}
		//final states
		System.out.print("Accepting states: ");
		for(State s : DFAStateSet.values())
		{
			if(s.isEnd)
				System.out.print(s.num + " ");
		}
		System.out.println("\n");
	}
}