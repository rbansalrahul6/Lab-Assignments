/* assuming arrival time starts from 0
and is in sorted order*/
#include <iostream>
using namespace std;
int main() {
	int n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	int arr[n],bur[n],clk=0,tw=0,count=0,order[n];
	float aw;
	//details of processes
	for(int i=0;i<n;i++) {
		cout<<"Process: "<<i+1<<endl;
		cout<<"Enter arrival time ";
		cin>>arr[i];
		//cout<<endl;
		cout<<"Enter burst time ";
		cin>>bur[i];
		//cout<<endl;
	}
	bool status[n];
	for(int i=0;i<n;i++)
		status[i]=false;
	clk+=bur[0];
	status[0]=true;
	order[count]=1;
	count++;
	while(count!=n) {
		int min=9999,loc=-1;
	for(int i=1;i<n;i++) {
		if(status[i]==false && arr[i]<=clk && bur[i]<min)
		{
			min=bur[i];
			loc=i;
		}
	}
	if(loc==-1)
		clk=arr[count];
	else
	{
		status[loc]=true;
		tw+=(clk-arr[loc]);
		clk+=min;
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
	return 0;
}

