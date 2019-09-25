#include<bits/stdc++.h>
#define pb push_back
#define po pop_back
using namespace std;
typedef long long ll;

// Insertion sort

void insert(int a[],int n)
{
	for(int j=1;j<n;j++)
	{
		int key=a[j];
		int i=j-1;
		while(i>=0 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}

main()
{
	int n,a[100001];
	cout<<"\n Enter no. of elements (integers): ";
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	insert(a,n);
}
