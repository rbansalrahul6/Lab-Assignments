class State
{
	public int num;
	public boolean isEnd;
	public State() {};
	public State(int n)
	{
		num = n;
		isEnd = false;
	}
	public State(int n,boolean b)
	{
		num = n;
		isEnd = b;
	}
}