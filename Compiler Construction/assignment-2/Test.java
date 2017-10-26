import java.util.*;
class Test
{
	public static void main(String args[])
	{
		String re;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter regex");
		re = sc.next();
		NFA nfa = new NFA(re);
		System.out.println("NFA generated");
		String s;
		System.out.println("Enter input string");
		s = sc.next();
		boolean res = nfa.simulate(s);
		if(res)
			System.out.println("Input string accepted by NFA");
		else
			System.out.println("Input string rejected by NFA");
		System.out.println("Press 1 to generate DFA from NFA");
		int response = sc.nextInt();
		if(response == 1)
		{
			DFA dfa = nfa.toDFA();
			dfa.display();
			dfa.simulate(s);
		}
	}
}