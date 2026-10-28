#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef string str;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define forl(i,a,b) for( (i)=(a);i<(b);(i)++)
#define forr(i,a,b) for( (i)=(a);i>(b);i--)

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
    vvll grp(20);

    forl(i,0,n)
    {
        if(a[i] == 0)
            continue;
        int b = 63 - __builtin_clzll(a[i]);
        grp[b].pb(i);
    }

    forl(i,0,20)
    {
        if(grp[i].size() >= 4)
        {
            cout<<grp[i][0]+1<< " "<< grp[i][1] + 1 << " "<< grp[i][2]+1
            <<" "<<grp[i][3]+1<<'\n';
            return;
        }
    }
    
    vll idx;
    forl(i,0,n)
    {
        if(a[i] != 0)
            idx.pb(i);
    }
    ll m = idx.size();
    forl(i,0,m)
    {
        for(ll j=i+1;j<m;j++)
        {
            for(ll k=j+1;k<m;k++)
            {
                for(ll l=k+1;l<m;l++)
                {
                    ll x = a[idx[i]];
                    ll y = a[idx[j]];
                    ll z = a[idx[k]];
                    ll w = a[idx[l]];

                    if((x^y)<z &&x>(y^z) &&(y^z)<w &&y>(z^w))
                    {
                        cout<<idx[i]+1<<" "<<idx[j]+1<<" "<<idx[k]+1<<" "<<idx[l]+1<<'\n';
                        return;
                    }
                }
            }
        }
    }

    cout<<-1<<'\n';
}

int main()
{
    fastio;
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}