#include<bits/stdc++.h>
using namespace std;


int main()
{

float r[10],c[10],p[10],tmp;
int n;
cout<<"\nEnter no. of process :";
cin>>n;
for(int i=0;i<n;i++)
{
cout<<"\n Enter exe time and time period of "<<(i+1)<<" job: ";
cin>>c[i]>>p[i];
}

for(int i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
	if(p[j]<p[i])
	{
	swap(p[j],p[i]);
	swap(c[j],p[i]);
	}
}
}
for(int i=0;i<n;i++)
cout<<p[i]<<" ";
cout<<endl;
int j;
for(int i=1;i<n;i++)
{
j=0;
r[j]=c[i];
r[j+1]=c[i];
for(int k=1;k<=i;k++)
r[j+1]+=ceil((r[j]/p[i-k]))*c[i-k];

while(r[j]!=r[j+1]&&r[j+1]<=p[i])
{j++;
r[j+1]=c[i];
for(int k=1;k<=i;k++)
r[j+1]+=ceil((r[j]/p[i-k]))*c[i-k];
}
cout<<"\nmax response time : "<<r[j+1];
if(r[j]==r[j+1])
cout<<"\n Schedulable ";
else
cout<<"\n Cannot schedule";
}
return 0;
}
