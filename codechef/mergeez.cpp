#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef string str;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define forl(i,a,b) for( (i)=(a);i<(b);(i)++)
#define forr(i,a,b) for( (i)=(a);i>(b);(i)--)

typedef pair<int, int> pi;
typedef pair<int,pair<int,int>>ppi;
typedef priority_queue<ll>pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> mpq;
typedef priority_queue<ppi>pqppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<str>vs;
typedef vector<pi> vpi;
typedef vector<vi>vvi;
typedef vector<vll>vvll;

const int MOD=1e9+7;
const ll inf = LLONG_MAX;

int find(int i, int sum, vll &c, vector<vector<int>>&dp)
{
    if(i<0 && sum==0)
    return 1;
    else if(i<0 && sum !=0)
    return 0;
    
    else if(dp[i][sum]!=-1)
    return dp[i][sum];
    
    else
    {
        int a = find(i-1,sum,c,dp);
        int b=0;
        if(sum-c[i]>=0)
        b = find(i-1,sum-c[i],c,dp);
        
    
    return dp[i][sum]= (a+b)%(998244353);
    }
}

void solve()
{
    ll n,i,j;

    cin>>n;
    vll v(n);
    
    forl(i,0,n)
    cin>>v[i];
    
    forl(i,1,n)
    v[i]=max(v[i],v[i-1]);
    
    vll ch;
    int c=1;
    
    
    forl(i,1,n)
    {
        if(v[i]!=v[i-1])
        {
            ch.pb(c);
            c=1;
        }
        else
        c++;
        
    }
    ch.pb(c);
    
    int sum = std::accumulate(ch.begin(), ch.end(), 0);
    vector<vector<int>>dp(ch.size(),vector<int>(sum+1,-1));
    forl(i,0,n)
    cout<<find(ch.size()-1,i,ch,dp)<<" ";
    cout<<1;
    cout<<'\n';   
}
int main() 
{
    fastio;
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
