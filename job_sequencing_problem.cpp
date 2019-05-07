/*JOB Sequencing problem.
Suppose an array of jobs is given with their respective deadline and profits.
  It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1.
  Therefore to maximize the total profit if only one job can be scheduled at a time we use this algorithm.
*/
#include <bits/stdc++.h>

using namespace std;

struct job{
    int id;
    int p;
    int d;
};

//function compares the profit of jobs.
bool comp(job a1,job a2)
{
    return( a1.p>a2.p);
}

void job_seq(job j[],int n)
{
    int t=j[0].d;
    for(int i=1;i<n;i++)
    {
        if(j[i].d>t)
        t=j[i].d;
    }    
    int b[t];
    
    //sorting the jobs descending order of profit.
    sort(j,j+n, comp);
    
    
    
    for(int i=0;i<t;i++)
    b[i]=-1;
    for(int i=0;i<n;i++)
    {
        for(int k=j[i].d-1;k>=0;k--)
        {
            if(b[k]==-1)
            {
                b[k]=j[i].id;
                break;
            }
        }
    }
    
    cout<<"\n Sequence of the jobs :\n";
    for(int i=0;i<t;i++)
    cout<<b[i]<<" ";
    
}

int main()
{
    cout<<"\n Enter the number of jobs:\n";
    int n;
    cin>>n;
    job j[n];
   cout<<"\n Enter job's deadline and profit: \n";
   for(int i=0;i<n;i++)
   {
       cout<<i+1<<" job:";
       j[i].id=i+1;
       cin>>j[i].d>>j[i].p;
   }
   
   //function to implement JSP
   job_seq(j,n);
   
   return 0;

