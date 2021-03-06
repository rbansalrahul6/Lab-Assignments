#include <iostream>
#include <algorithm>
using namespace std;
struct process
{
	int pid;
	int arr_time;
	int burst_time;
	int wait_time;
};
bool process_sorter(const process& lhs,const process& rhs)
{
	return lhs.arr_time<rhs.arr_time;
}
int main()
{
	int n,tw=0,clk;
	double avg_wait;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	process p[n];
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>p[i].arr_time;
		cout<<"Enter burst time ";
		cin>>p[i].burst_time;
	}
	sort(p,p+n,&process_sorter);
	//calculating aerage waiting time
	clk=p[0].burst_time;
	for(int i=1;i<n;i++)
	{
		if(p[i].arr_time>clk)
			clk=p[i].arr_time;
		p[i].wait_time=clk-p[i].arr_time;
		tw+=p[i].wait_time;
		clk+=p[i].burst_time;
	}
	avg_wait=1.0*tw/n;
	//printing
	cout<<"order"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<" "<<p[i].wait_time<<endl;;
	}
	cout<<"Average waiting time "<<avg_wait<<endl;
	return 0;
}