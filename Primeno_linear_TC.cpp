// This algorithm has linear time complexity but space complexity is large.

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define wr(i) cout<<#i<<" = "<<i<<",  ";
#define wre(i) cout<<#i<<"  =  "<<i<<endl;
#define all(v) v.begin(),v.end()
typedef long long ll;
// #define lim 1000000007
#define M 100001
ll lim=10000007;


const int N = 10000000;
int lp[N+1];
vector<int> pr;
void prime()
{
   memset(lp,0,sizeof(lp));
for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.pb(i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
}
}

int main()
{
// fast
prime();
ll n;
cin>>n;
cout<<"First "<<n<<" prime numbers are:\n";
for(int i=0;i<n;i++)cout<<pr[i]<<" ";
}
