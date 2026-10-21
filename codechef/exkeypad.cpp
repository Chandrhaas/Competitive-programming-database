#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef string str;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define forl(i,a,b) for( (i)=(a);i<(b);(i)++)
#define forr(i,a,b) for( (i)=(a);i>=(b);(i)--)

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
    ll n,d,i,j;
    cin>>n>>d;
    
    if(n==0 && d==0)
    {
        cout<<1<<'\n';
        return;
    }
    
    vll a;
    ll c =n,f=0;
    while(n!=0)
    {
        int di = n%10;
        if(di==d)
        f=1;
        a.pb(di);
        n=n/10;
    }
    if(f==0)
    {cout<<c<<'\n';
    return;
    }
    
    else
    {
        if(d!=9)
        {
        ll num =0,f=0;
        forr(i,a.size()-1,0)
        {
            if(a[i]!=d && f==0)
            cout<<a[i];
            else
            {
                if(a[i]==d && f==0)
                {
                    f=1;
                    cout<<d+1;
                }
                else
                {
                    if(d!=0)
                    cout<<0;
                    else
                    cout<<1;
                }
            }
        }
        cout<<'\n';
        }
        else
        { 
            str st = to_string(c);
            ll k=0;
            
            forl(i,0,st.size())
            {
                if((int)st[i]-48 == 9 )
                {
                    i--;
                    while(i>=0 && st[i]=='8')
                    i--;
                    if(i>=0)
                      k=i;
                    else
                    k=-1;
                    break;
                }
            }
            if(k==-1)
            {
                cout<<1;
                forl(i,0,st.size())
                cout<<0;
                cout<<'\n';
                return;
            }
            forl(i,0,st.size())
            {
                if(i<k)
                cout<<st[i];
                else if(i==k)
                cout<<(int)st[i]-48+1;
                else
                cout<<0;
            }
            cout<<'\n';
            
            
        }
    }
    
    
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
