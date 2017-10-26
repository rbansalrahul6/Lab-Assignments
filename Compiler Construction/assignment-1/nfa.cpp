#include <bits/stdc++.h>
#include "util.cpp"
using namespace std;

class state
{
public:
	int num;
	bool is_end;

	state() {}
	state(int n)
	{
		num = n;
		is_end = false;
	}
	bool operator <(const state& rhs) const
	{
		return num < rhs.num;
	}

};

typedef pair<char,state> edge;
typedef vector<edge> trans;
const char EPS = '$';
map<state,trans> G;   //nfa graph

class NFA
{
public:
	state start,end;

	NFA() {}
	NFA(state s,state e)
	{
		start = s;
		end = e;
		end.is_end = true;
	}
/******helper method*******/
	void add_state(state s,set<state>& st)  //finds e-closure of state s
	{
		if(st.find(s)!=st.end())
			return;
		st.insert(s);
		trans t = G[s];
		trans :: iterator it;
		for(it=t.begin();it!=t.end();it++)
		{
			char c = (*it).first;
			state n = (*it).second;
			if(c == EPS)
				add_state(n,st);
		}
	}

	bool simulate(string q)
	{
		set<state> curr;
		add_state(start,curr);
		for(int i=0;i<q.length();i++)
		{
			set<state> next;
			set<state> :: iterator it;
			for(it=curr.begin();it!=curr.end();it++)
			{
				trans t = G[*it];  //examine edges of current state
				trans :: iterator ti;
				for(ti=t.begin();ti!=t.end();ti++)
				{
					char c = (*ti).first;
					state n = (*ti).second;
					if(c == q[i])
						add_state(n,next);
				}
			}
			curr = next;
		}
		set<state> :: iterator it;
		for(it=curr.begin();it!=curr.end();it++)
		{
			if((*it).num == end.num)
				return true;
		}
		return false;
	}

	void display()
	{
		map<state,trans> :: iterator it;
		for(it=G.begin();it!=G.end();it++)
		{
			cout<<(it->first).num<<"-> ";
			trans t = it->second;
			trans :: iterator i;
			for(i=t.begin();i!=t.end();i++)
			{
				cout<<"("<<(*i).first<<","<<(*i).second.num<<")"<<" ";
			}
			cout<<endl;
		}
	}
};

class Handler
{
public:
	int state_count;

	Handler()
	{
		state_count = 0;
	}

	state create_state()
	{
		state_count+=1;
		return state(state_count);
	}

	void handle_char(char t,stack<NFA>& ns)
	{
		state s0 = create_state();
		state s1 = create_state();
		G[s0].push_back(make_pair(t,s1));
		NFA nfa = NFA(s0,s1);
		ns.push(nfa);
	}

	void handle_concat(stack<NFA>& ns)
	{
		NFA n2 = ns.top();ns.pop();
		NFA n1 = ns.top();ns.pop();
		n1.end.is_end = false;
		G[n1.end].push_back(make_pair(EPS,n2.start));
		NFA nfa = NFA(n1.start,n2.end);
		ns.push(nfa);
	}

	void handle_union(stack<NFA>& ns)
	{
		NFA n2 = ns.top();ns.pop();
		NFA n1 = ns.top();ns.pop();
		state s0 = create_state();
		G[s0].push_back(make_pair(EPS,n1.start));
		G[s0].push_back(make_pair(EPS,n2.start));
		state s3 = create_state();
		G[n1.end].push_back(make_pair(EPS,s3));
		G[n2.end].push_back(make_pair(EPS,s3));
		n1.end.is_end = false;
		n2.end.is_end = false;
		NFA nfa = NFA(s0,s3);
		ns.push(nfa);
	}

	void handle_kleen(stack<NFA>& ns)
	{
		NFA n1 = ns.top();ns.pop();
		state s0 = create_state();
		state s1 = create_state();
		G[s0].push_back(make_pair(EPS,n1.start));
		G[s0].push_back(make_pair(EPS,s1));
		G[n1.end].push_back(make_pair(EPS,n1.start));
		G[n1.end].push_back(make_pair(EPS,s1));
		n1.end.is_end = false;
		NFA nfa = NFA(s0,s1);
		ns.push(nfa);
	}
};
/***************************END************************************/

/*****************************nfa generator***********************/
NFA compile(string p)
{
	string pf = regex_to_postfix(p);
	//debug check pf
	stack<NFA> ns;
	Handler handler = Handler();

	for(int i=0;i<pf.length();i++)
	{
		switch(pf[i])
		{
			default:
				handler.handle_char(pf[i],ns);
				break;
			case '.':
				handler.handle_concat(ns);
				break;
			case '|':
				handler.handle_union(ns);
				break;
			case '*':
				handler.handle_kleen(ns);
				break;
		}
	}

	//debug ns.size()==1
	return ns.top();
}

