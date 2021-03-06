#include <iostream>
#include <algorithm>
using namespace std;
int tw=0;
float aw;
struct process
{
	int pid;
	int arr_time;
	int burst_time;
	int priority;          //LOW NUMBER MEANS HIGH PRIORITY
	int wait_time;
};
bool process_sorter_arr(const process& lhs,const process& rhs)
{
	return lhs.arr_time<rhs.arr_time;
}
bool process_sorter_prior(const process& lhs,const process& rhs)
{
	return lhs.priority<rhs.priority;
}
void fcfs(process p[],int n)
{
	int clk=0;
	sort(p,p+n,&process_sorter_arr);
	//calculating aerage waiting time
	clk=p[0].burst_time;
	p[0].wait_time=0;
	for(int i=1;i<n;i++)
	{
		if(p[i].arr_time>clk)
			clk=p[i].arr_time;
		p[i].wait_time=clk-p[i].arr_time;
		tw+=p[i].wait_time;
		clk+=p[i].burst_time;
	}
	aw=1.0*tw/n;
	//printing
	cout<<"order"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<" "<<p[i].wait_time<<endl;;
	}
}
void sjf(process p[],int n)
{
	int clk=0,count=0,order[n];
	bool status[n];
	for(int i=0;i<n;i++)
		status[i]=false;
	//finding starting process
	int first=0,arr_first=p[0].arr_time,bur_first=p[0].burst_time;
	for(int i=1;i<n;i++) {
		if(p[i].arr_time<arr_first || (p[i].arr_time==arr_first && p[i].burst_time<bur_first))
		{
			arr_first=p[i].arr_time;
			first=i;
			bur_first=p[i].burst_time;
		}
	}
	clk=bur_first;      //check this line
	status[first]=true;
	p[first].wait_time=0;
	order[count]=first+1;
	count++;
	while(count!=n) {
		int min=9999,loc=-1;
	for(int i=0;i<n;i++) {
		if(status[i]==false && p[i].arr_time<=clk && p[i].burst_time<min)
		{
			min=p[i].burst_time;
			loc=i;
		}
	}
	if(loc==-1)
		clk=p[count].arr_time;
	else
	{
		status[loc]=true;
		p[loc].wait_time=clk-p[loc].arr_time;
		tw+=p[loc].wait_time;
		clk+=min;
		order[count]=loc+1;
		count++;
	  }
	}
	aw=1.0*tw/n;
	//printing sequence
	cout<<"Order:"<<endl;
	for(int i=0;i<n;i++)
		cout<<order[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	process p[n];
	//int clk=0,tw=0,count=0,order[n];
	//details of processes
	for(int i=0;i<n;i++) {
		p[i].pid=i+1;
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>p[i].arr_time;
		cout<<"Enter burst time ";
		cin>>p[i].burst_time;
		cout<<"Enter priority ";
		cin>>p[i].priority;
	}
	//print exeution sequence
	//fcfs(p,n);
	//sjf(p,n);
	priority(p,n);
	//print waiting times
	cout<<"Average waiting time: "<<aw<<endl;
	return 0;
}
