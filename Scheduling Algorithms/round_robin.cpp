/* assuming arrival time starts from 0
and is in sorted order*/
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
	//debug
	/*cout<<endl;
	for(int i=0;i<n;i++)
		cout<<status[i]<<" ";*/
	return 0;
}