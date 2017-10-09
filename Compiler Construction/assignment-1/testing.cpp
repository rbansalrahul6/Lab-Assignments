#include <bits/stdc++.h>
#include "nfa.cpp"
using namespace std;

int main()
{
	string re;
	cout<<"enter regex\n";
	cin>>re;
	NFA nfa = compile(re);
	cout<<"nfa generated\n";
	string s;
	cout<<"enter input string\n";
	cin>>s;
	bool res = nfa.simulate(s);
	if(res)
		cout<<"accepted\n";
	else
		cout<<"rejected\n";
	return 0;
}