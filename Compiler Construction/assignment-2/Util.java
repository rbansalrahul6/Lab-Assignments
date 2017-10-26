import java.util.*;

class Util
{
	public static int priority(char c)
	{
		switch(c)
		{
			case '*' : return 3;
			case '.' : return 2;
			case '|' : return 1;
			default : return 0;
		}
	}

	public static String insertConcat(String regex)
	{
	String res = "";
	char c1,c2;
	int n = regex.length();
	for(int i=0;i<n;i++)
	{
		c1 = regex.charAt(i);
		if(i < n-1)
		{
			c2 = regex.charAt(i+1);
			res+=c1;
			if(c1!='('&&c2!=')' && c1!='|'&&c2!='|' && c2!='*')
			{
				res+='.';
			}
		}
	}
	res+=regex.charAt(n-1);
	return res;
	}

	public static String regexToPostfix(String re)
	{
		String res = "";
		Stack<Character> st = new Stack<Character>();
		re = insertConcat(re) + ")";
		st.push('(');
		int n = re.length();
		char ch[] = re.toCharArray();
	for(int i=0;i<n;i++)
	{
		if(ch[i] == '(')
			st.push(ch[i]);
		else if(ch[i]=='*' || ch[i]=='.' || ch[i]=='|')
		{
			while(priority(ch[i]) <= priority(st.peek()))
			{
				res+=st.peek();
				st.pop();
			}
			st.push(ch[i]);
		}
		else if(ch[i] == ')')
		{
			while(st.peek()!='(')
			{
				res+=st.peek();
				st.pop();
			}
			st.pop();
		}
		else
			res+=ch[i];
	}
	return res;
	}
}