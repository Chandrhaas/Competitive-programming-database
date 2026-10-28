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



void solve()
{
    ll n,i,j;
    
    cin>>n;
    vll a(n);
    forl(i,0,n) 
    cin>>a[i];
    ll c=0;
    forl(i,0,n-2)
    {
        
        c+=abs(a[i]);
    }
    
    cout<<c-a[n-2]+a[n-1]<<'\n';
    
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
