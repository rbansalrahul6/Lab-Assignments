class PartialNFA
{
	public State start;
	public State end;
	public PartialNFA() {}
	public PartialNFA(State s,State e)
	{
		start = s;
		end = e;
		end.isEnd = true;
	}
}