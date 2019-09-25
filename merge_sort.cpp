#include<bits/stdc++.h>
#define pb push_back
#define po pop_back
using namespace std;
typedef long long ll;

void merge(ll ar[],ll p,ll q,ll r)
{

	ll n1=q-p+1,n2=r-q;
	ll L[n1+1],R[n2+1];
	L[n1]=INT_MAX;
	R[n2]=L[n1];
	
	for(int i=0;i<n1;i++)
	L[i]=ar[p+i];
	for(int i=0;i<n2;i++)
	R[i]=ar[q+i+1];
	
	ll i=0,j=0;
	
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			ar[k]=L[i];
			i++;	
		}
		else
		{
			ar[k]=R[j];
			j++;
		}
	}
	
	
}

void merge_sort(ll ar[],ll p,ll r)
{
	if(p<r)
	{
	ll q=(r+p)/2;
	merge_sort(ar,p,q);
	merge_sort(ar,q+1,r);
	merge(ar,p,q,r);
	}
}

main()
{
	ll n;
	cout<<"Enter the number of elements to be sort: ";
	cin>>n;
	ll ar[n];
	cout<<"\n Enter the elements: \n";
	for(int i=0;i<n;i++)
	cin>>ar[i];
	
	merge_sort(ar,0LL,n-1);
	for(int i=0;i<n;i++)
	cout<<ar[i]<<" ";	
	
}
