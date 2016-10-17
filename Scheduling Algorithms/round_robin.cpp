#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	int arr[n],bur[n],clk=0,tw=0,count=0,order[n],tq,rem[n],ta[n],wait[n];
	float aw;
	//details of processes
	for(int i=0;i<n;i++) {
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>arr[i];
		cout<<"Enter burst time ";
		cin>>bur[i];
	}
	cout<<"Enter time quantum"<<endl;
	cin>>tq;
	bool status[n];
	for(int i=0;i<n;i++) {
		rem[i]=bur[i];
		status[i]=false;
	}
	//finding first process , arrival time don't start from 0
	int first=0,arr_first=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr_first)
		{
			arr_first=arr[i];
			first=i;
		}
	}
	clk=arr_first;
		for(int i=0;count!=n;i=(i+1)%n) {
			if(status[i]==true) {
				//do nothing,move to next
				continue;
			}
			else if(arr[i]<=clk) {
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
					ta[i]=clk-arr[i];
					count++;
				}
			}
		}
	//calculating waiing times
	for(int i=0;i<n;i++)
		wait[i]=ta[i]-bur[i];
	//printing waiting times
	cout<<endl<<"waiting times: ";
	for(int i=0;i<n;i++)
		cout<<wait[i]<<" ";
	cout<<endl;
	//debug
	/*cout<<endl;
	for(int i=0;i<n;i++)
		cout<<status[i]<<" ";*/
	return 0;
}