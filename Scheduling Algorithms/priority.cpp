#include <iostream>
#include <algorithm>
using namespace std;
struct process
{
	int pid;
	int arr_time;
	int burst_time;
	int priority;          //LOW NUMBER MEANS HIGH PRIORITY
};
bool process_sorter(const process& lhs,const process& rhs)
{
	return lhs.priority<rhs.priority;
}
int main()
{
	int n,tw=0,clk;
	double avg_wait;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	process p[n];
	cout<<"LOW NUMBER MEANS HIGH PRIORITY"<<endl;
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>p[i].arr_time;
		cout<<"Enter burst time ";
		cin>>p[i].burst_time;
		cout<<"Enter priority ";
		cin>>p[i].priority;
	}
	sort(p,p+n,&process_sorter);
	//calculating aerage waiting time
	clk=p[0].burst_time;
	for(int i=1;i<n;i++)
	{
		if(p[i].arr_time>clk)
			clk=p[i].arr_time;
		tw+=clk-p[i].arr_time;
		clk+=p[i].burst_time;
	}
	avg_wait=1.0*tw/n;
	//printing
	cout<<"order"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<" ";
	}
	cout<<endl;
	cout<<"Average waiting time "<<avg_wait<<endl;
	return 0;
}