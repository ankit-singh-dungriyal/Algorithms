// The maximum subarray problem
// This algorithm solve the above problem in O(nlogn) time
#include<bits/stdc++.h>
#define pb push_back
#define po pop_back
using namespace std;
typedef long long ll;

tuple<int,int,int> max_cross_subarray(int a[],int l,int r,int m)
{
	int left_sum=INT_MIN,right_sum=INT_MIN;
	int max_left,max_right;
	int sum=0;
	for(int i=m;i>=l;i--)
	{
		sum=sum+a[i];
		if (sum>left_sum)
		{
			left_sum=sum;
			max_left=i;
		}
	}
	sum=0;
	for(int i=m+1;i<=r;i++)
	{
		sum=sum+a[i];
		if(right_sum<sum)
		{
			right_sum=sum;
			max_right=i;
		}
	}
	int total_sum= left_sum+right_sum;
	return make_tuple(max_left,max_right,total_sum);
}

tuple<int,int,int> max_subarray(int a[],int l,int r)
{
	if(l==r)
	return make_tuple(l,r,a[l]);
	else
	{
		int left_low,left_high,left_sum,right_low,right_high,right_sum,cross_low,cross_high,cross_sum;
		int m=(l+r)/2;
		tie(left_low,left_high,left_sum)=max_subarray(a,l,m);
		tie(right_low,right_high,right_sum)=max_subarray(a,m+1,r);
		tie(cross_low,cross_high,cross_sum)=max_cross_subarray(a,l,r,m);
		if(left_sum>=right_sum&& left_sum>=cross_sum)
		return make_tuple(left_low,left_high,left_sum);
		else if(right_sum>=left_sum&& right_sum>=cross_sum)
		return make_tuple(right_low,right_high,right_sum);
		else
		return make_tuple(cross_low,cross_high,cross_sum);
	}
}

int main()
{
	int n;
	int price[100001];
	int change[100001];
	cout<<" \n Enter the no. of elements : ";
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>price[i];
	for(int i=1;i<n;i++)
	change[i]=price[i]-price[i-1];
	int left,right,sum;
	tie(left,right,sum)=max_subarray(change,1,n-1);
	cout<<"\n To maximize the profit user should buy the product in "<<left<<" day and shell it on "<<right+1<<" day.\n";
	cout<<" Maximum profit is "<<sum<<endl;
		
}
