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
	//finding starting process
	int first=0,arr_first=arr[0],bur_first=bur[0];
	for(int i=1;i<n;i++) {
		if(arr[i]<arr_first || (arr[i]==arr_first && bur[i]<bur_first))
		{
			arr_first=arr[i];
			first=i;
			bur_first=bur[i];
		}
	}
	clk=bur_first;      //check this line
	status[first]=true;
	order[count]=first+1;
	count++;
	while(count!=n) {
		int min=9999,loc=-1;
	for(int i=0;i<n;i++) {
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
	cout<<endl;
	return 0;
}

