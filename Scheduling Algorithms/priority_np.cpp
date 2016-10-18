#include <iostream>
using namespace std;
struct process
{
	int pid;
	int arr_time;
	int burst_time;
	int priority;
	int wait_time;
};
int main() {
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	process p[n];
	int clk=0,tw=0,count=0,order[n];
	float aw;
	//details of processes
	for(int i=0;i<n;i++) {
		p[i].pid=i+1;
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>p[i].arr_time;
		//cout<<endl;
		cout<<"Enter burst time ";
		cin>>p[i].burst_time;
		cout<<"Enter priority ";
		cin>>p[i].priority;
	}
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
	order[count]=first+1;
	count++;
	while(count!=n) {
		int min=9999,loc=-1;
	for(int i=0;i<n;i++) {
		if(status[i]==false && p[i].arr_time<=clk && p[i].priority<min)
		{
			min=p[i].priority;
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
		clk+=p[loc].burst_time;
		order[count]=loc+1;
		count++;
	  }
	}
	//print result
	aw=1.0*tw/n;
	cout<<"Total waiting time: "<<tw<<endl;
	cout<<"Average waiting time: "<<aw<<endl;
	cout<<"Order:"<<endl;
	for(int i=0;i<n;i++)
		cout<<order[i]<<" ";
	cout<<endl;
	return 0;
}

