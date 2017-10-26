import java.util.*;
class DFAState
{
	public Set<State> stateSet;
	public int num;

	public DFAState(){};

	public DFAState(Set<State> s,int n)
	{
		stateSet = s;
		num = n;
	}
}