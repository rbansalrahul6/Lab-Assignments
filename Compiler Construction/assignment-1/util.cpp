#include <bits/stdc++.h>
using namespace std;

/***************Utility functions**************/
int priority(char c)
{
	switch(c)
	{
		case '*': return 3;
		case '.': return 2;
		case '|': return 1;
		default: return 0;  //parentheses etc.
	}
}



/*****insert concetenation symbol 
Traverse the string and check two adjacent chars at a time,
following are valid combinations for inserting a dot
char1   char2
-----   -----
opnd    opnd
opnd     (
*        (
)       opnd
*****************************/

string insert_concat(string regex)
{
	string res = "";
	char c1,c2;
	int n = regex.length();
	for(int i=0;i<n;i++)
	{
		c1 = regex[i];
		if(i < n-1)
		{
			c2 = regex[i+1];
			res+=c1;
			if(c1!='('&&c2!=')' && c1!='|'&&c2!='|' && c2!='*')
			{
				res+='.';
			}
		}
	}
	res+=regex[n-1];
	return res;
}

string regex_to_postfix(string re)
{
	string res = "";
	stack<char> st;
	re = insert_concat(re) + ")";
	st.push('(');
	for(int i=0;i<re.length();i++)
	{
		if(re[i] == '(')
			st.push(re[i]);
		else if(re[i]=='*' || re[i]=='.' || re[i]=='|')
		{
			while(priority(re[i]) <= priority(st.top()))
			{
				res+=st.top();
				st.pop();
			}
			st.push(re[i]);
		}
		else if(re[i] == ')')
		{
			while(st.top()!='(')
			{
				res+=st.top();
				st.pop();
			}
			st.pop();
		}
		else
			res+=re[i];
	}
	return res;
}
/************************END******************************/
