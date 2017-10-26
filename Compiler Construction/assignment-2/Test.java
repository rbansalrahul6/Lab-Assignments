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
		nfa.display();
		String s;
		System.out.println("enter input string");
		s = sc.next();
		boolean res = nfa.simulate(s);
		if(res)
			System.out.println("accepted");
		else
			System.out.println("rejected");
	}
}