#include <iostream>
using namespace std;
int heap_size;
bool isEmpty(int a[])
{
if(heap_size==0)
return true;
else
return false;
}
int parent(int i)
{
return i/2;
}
int left(int i)
{
return 2*i+1;
}
int right(int i)
{
return 2*i+2;
}
//min-heapify
void min_heapify(int a[],int n,int i)
{
int l = left(i);
int r = right(i);
int min = i;
if(l<n && a[l]<a[i])
min = l;
if(r<n && a[r]<a[min])
min=r;
	if(min!=i)
	{
	int temp = a[i];
	a[i] = a[min];
	a[min] = temp;
	min_heapify(a,n,min);
	}
}
void build_min_heap(int a[],int n)
{
heap_size=n;
for(int i=n/2;i>=0;i--)
min_heapify(a,n,i);
}
int find_min(int a[])
{
return a[0];
}
void decrease_key(int a[],int n,int i,int k)
{
	if(a[i]<k)
	{
	cout<<"error:key is big"<<endl;
	return;
	}
	a[i]=k;
	while(i<n && a[i]<a[parent(i)])
	{
	int temp = a[i];
	a[i] = a[parent(i)];
	a[parent(i)] = temp;
	i=parent(i);
	}
}
void delete_min(int a[])
{
	if(!isEmpty(a))
	{
	a[0]=a[heap_size-1];
	heap_size--;
	min_heapify(a,heap_size,0);
	}
}
void print(int a[],int n)
{
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}
//main
int main()
{
int n;
cout<<"enter size"<<endl;
cin>>n;
int a[n];
cout<<"enter elements"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];
build_min_heap(a,n);
cout<<"min heap"<<endl;
print(a,heap_size);
delete_min(a);
print(a,heap_size);
decrease_key(a,heap_size,1,-10);
print(a,heap_size);
return 0;
}
