#include <iostream>
using namespace std;
void sort(int n,int a[])
{
for(int p=0;p<n-1;p++) {
	for(int i=1;i<n-p;i++){
	if(a[i-1]>a[i]){
		int t=a[i-1];
		a[i-1]=a[i];
		a[i]=t;
		}
	}
}
}
int binary_search(int n,int a[],int k)
{
//int loc=-1;
int l=0,u=n-1,m;
while(l<=u) {
	m = (l+u)/2;
	if(a[m]==k)
	return m;
	else if(a[m]>k)
	u=m-1;
	else
	l=m+1;
	}
return -1;
}
float mean(int n,int a[])
{
float s=0.0;
for(int i=0;i<n;i++) {
	s+=a[i];
	}
return s/n;
}
int main()
{
int n;
cout<<"enter size"<<endl;
cin>>n;
int a[n];
cout<<"enter array"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];
sort(n,a);
//print
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
//search
int k;
cout<<"enter element to search"<<endl;
cin>>k;
cout<<"location is "<<binary_search(n,a,k)<<endl;
//mean
cout<<"mean of array is "<<mean(n,a)<<endl;
return 0;
}
