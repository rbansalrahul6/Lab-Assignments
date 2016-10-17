#include <iostream>
using namespace std;
struct process
{
	int pid;
	int arr_time;
	int burst_time;
	int wait_time;
};
int main()
{
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	process p[n];
	int clk=0,tw=0,count=0,order[n],tq,rem[n],ta[n],wait[n];
	float aw;
	//details of processes
	for(int i=0;i<n;i++) {
		p[i].pid=i+1;
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>p[i].arr_time;
		cout<<"Enter burst time ";
		cin>>p[i].burst_time;
	}
	cout<<"Enter time quantum"<<endl;
	cin>>tq;
	bool status[n];
	for(int i=0;i<n;i++) {
		rem[i]=p[i].burst_time;
		status[i]=false;
	}
	//finding first process , arrival time don't start from 0
	int first=0,arr_first=p[0].arr_time;
	for(int i=1;i<n;i++)
	{
		if(p[i].arr_time<arr_first)
		{
			arr_first=p[i].arr_time;
			first=i;
		}
	}
	clk=arr_first;
		for(int i=0;count!=n;i=(i+1)%n) {
			if(status[i]==true) {
				//do nothing,move to next
				continue;
			}
			else if(p[i].arr_time<=clk) {
				//debug;gantt chart
				cout<<i+1<<" ";
				//allot quantum
				if(rem[i]<tq) {
					clk+=rem[i];
					rem[i]=0;
				}
				else {
					clk+=tq;
					rem[i]-=tq;
				}
				//check for status ;last quantum alloted
				if(rem[i]==0) {
					status[i]=true;
					ta[i]=clk-p[i].arr_time;
					count++;
				}
			}
		}
	//calculating waiing times
	for(int i=0;i<n;i++)
		p[i].wait_time=ta[i]-p[i].burst_time;
	//printing waiting times
	cout<<endl<<"waiting times: ";
	for(int i=0;i<n;i++)
		cout<<p[i].wait_time<<" ";
	cout<<endl;
	//debug
	/*cout<<endl;
	for(int i=0;i<n;i++)
		cout<<status[i]<<" ";*/
	return 0;
}