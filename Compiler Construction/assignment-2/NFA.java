import java.util.*;
class NFA extends PartialNFA
{
	private static final char EPS = '$';
	private int stateCount;
	public HashMap<State,ArrayList<Edge> > graph;
	public NFA()
	{
		stateCount = 0;
		graph = new HashMap<State,ArrayList<Edge> >();  //doubt
	}
	private State createState()
	{
		stateCount+=1;
		State st = new State(stateCount);
		ArrayList<Edge> empty = new ArrayList<Edge>();
		graph.put(st,empty);
		return st;
	}
	//handler methods
	void handleChar(char t,Stack<PartialNFA> ns)
	{
		State s0 = createState();
		State s1 = createState();
		ArrayList<Edge> s0Edges = graph.get(s0);
		s0Edges.add(new Edge(t,s1));
		//check
		PartialNFA pnfa = new PartialNFA(s0,s1);
		ns.push(pnfa);
	}
	void handleConcat(Stack<PartialNFA> ns)
	{
		PartialNFA n2 = ns.peek();ns.pop();
		PartialNFA n1 = ns.peek();ns.pop();
		n1.end.isEnd = false;
		ArrayList<Edge> n1EndEdges = graph.get(n1.end);
		n1EndEdges.add(new Edge(EPS,n2.start));
		//check
		PartialNFA pnfa = new PartialNFA(n1.start,n2.end);
		ns.push(pnfa);
	}
	void handleUnion(Stack<PartialNFA> ns)
	{
		PartialNFA n2 = ns.peek();ns.pop();
		PartialNFA n1 = ns.peek();ns.pop();
		State s0 = createState();
		ArrayList<Edge> s0Edges = graph.get(s0);
		s0Edges.add(new Edge(EPS,n1.start));
		s0Edges.add(new Edge(EPS,n2.start));
		State s3 = createState();
		n1.end.isEnd = false;
		n2.end.isEnd = false;
		ArrayList<Edge> n1EndEdges = graph.get(n1.end);
		ArrayList<Edge> n2EndEdges = graph.get(n2.end);
		n1EndEdges.add(new Edge(EPS,s3));
		n2EndEdges.add(new Edge(EPS,s3));
		PartialNFA pnfa = new PartialNFA(s0,s3);
		ns.push(pnfa);
	}
	void handleKleen(Stack<PartialNFA> ns)
	{
		PartialNFA n1 = ns.peek();ns.pop();
		State s0 = createState();
		State s1 = createState();
		ArrayList<Edge> s0Edges = graph.get(s0);
		s0Edges.add(new Edge(EPS,n1.start));
		s0Edges.add(new Edge(EPS,s1));
		n1.end.isEnd = false;
		ArrayList<Edge> n1EndEdges = graph.get(n1.end);
		n1EndEdges.add(new Edge(EPS,n1.start));
		n1EndEdges.add(new Edge(EPS,s1));
		PartialNFA pnfa = new PartialNFA(s0,s1);
		ns.push(pnfa);
	}
	//constructor to make nfa from regex
	public NFA(String p)
	{
		//initialize NFA variables
		stateCount = 0;
		graph = new HashMap<State,ArrayList<Edge> >();  //doubt
		//parsing the regex
		String pf = Util.regexToPostfix(p);
		Stack<PartialNFA> ps = new Stack<PartialNFA>();
		for(int i=0;i<pf.length();i++)
		{
			switch(pf.charAt(i))
			{
				default:
					handleChar(pf.charAt(i),ps);
					break;
				case '.' :
					handleConcat(ps);
					break;
				case '|' :
					handleUnion(ps);
					break;
				case '*' :
					handleKleen(ps);
					break;
			}
		}
		PartialNFA pnfa = ps.peek();
		start = pnfa.start;
		end = pnfa.end;
	}

	//method to find eps-closure of NFA
	void addState(State s,HashSet<State> st)
	{
		if(st.contains(s))
			return;
		st.add(s);
		ArrayList<Edge> edges = graph.get(s);
		for(Edge e : edges)
		{
			char val = e.input;
			State sout = e.out;
			if(val == EPS)
				addState(sout,st);
		}
	}
	//method to simulate NFA
	boolean simulate(String q)
	{
		HashSet<State> curr = new HashSet<State>();
		addState(start,curr);
		for(int i=0;i<q.length();i++)
		{
			HashSet<State> next = new HashSet<State>();
			for(State s : curr)
			{
				ArrayList<Edge> edges = graph.get(s); //examine edges of current state
				for(Edge e : edges)
				{
					char val = e.input;
					State sout = e.out;
					if(val == q.charAt(i))
						addState(sout,next);
				}
			}
			curr = next;
		}
		//checking for any end state
		for(State s : curr)
		{
			if(s.isEnd)
				return true;
		}
		return false;
	}

	//method to display NFA
	void display()
	{
		for(Map.Entry<State,ArrayList<Edge>> entry : graph.entrySet())
		{
			State s = entry.getKey();
			ArrayList<Edge> edges = entry.getValue();
			System.out.print(s.num + "," + s.isEnd + "-> ");
			for(Edge e : edges)
			{
				System.out.print("(" + e.input + "," + e.out.num + ") ");
			}
			System.out.println();
		}
	}
}