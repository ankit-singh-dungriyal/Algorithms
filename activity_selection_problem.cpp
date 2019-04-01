/*'n' activities are given with their start and finish times. 
We have to select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.*/
#include<bits/stdc++.h>
using namespace std;

//structure for activitiy's starting and finish time.
struct activity{
	int start;
	int end;
};

//comparision function that compare return true if next activity's 
//finish time is greater than current one.
bool compare(activity s1,activity s2)
{
	return(s1.end<s2.end);
}
void activity_selection(int n,activity s[])
{
	int i=0;

 //sorting the activities according to their finish time.
	sort(s,s+n,compare);
	cout<<"\n Activities selected : \n";
	cout<<" ("<<s[i].start<<","<<s[i].end<<")";

	for(int j=1;j<n;j++)
	{
		if(s[j].start>=s[i].end)
		{
			//printing the selected activities.
			cout<<" ("<<s[j].start<<","<<s[j].end<<")";
			i=j;
		}
	}
}

main()
{
	int n;
	cout<<"\n Enter the number of activities : ";
	cin>>n;
	activity s[n];
	cout<<"\n Enter starting and end time of activities";
	for(int i=0;i<n;i++)
	{	cout<<i+1<<" : activity: \n";
		cin>>s[i].start>>s[i].end;
	}
	
	activity_selection(n,s);
}
