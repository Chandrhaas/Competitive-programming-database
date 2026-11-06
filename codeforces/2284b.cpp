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

#ifndef ONLINE_JUDGE
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

template <typename... T>
void _print(T... args) {
    int f = 0;
    ((cerr << (f++ ? ", " : ""), __print(args)), ...);
    cerr << "]\n";
}

#define dbg(x...) do { cerr << "[" << #x << "] = ["; _print(x); } while(0)
#else
#define dbg(x...)
#endif


template <typename T>
void scanv(T &v) 
{
    for (auto &x : v)
        cin >> x;
}

template <typename T>
void printv(const T &v) 
{
    for (const auto &x : v)
        cout << x <<" " ;
    cout << endl;
}


void solve()
{
    ll n,k,i,j,c=0,f=0;

    cin>>n>>k;
    vll a(n);
    scanv(a);

    sort(all(a));

    if(k>n)
    cout<<"no"<<'\n';
    else
    {
        vll ans;
        forl(i,n-k,n)
        ans.pb(a[i]);

        forr(i,n-k-1,-1)
        ans.pb(a[i]);

        dbg(ans);

        forl(i,0,k)
        c+=ans[i];

        dbg(c);
        forl(i,k,n)
        {
            if(c <= ans[i]*(i))
            {
                f=1;
                break;
            }
            else
            c+=ans[i];
        }

        if(f==1)
        cout<<"no"<<'\n';

        else
        { 
        cout<<"yes"<<'\n';
        printv(ans);
        }

    }
    



}

int main() 
{
    fastio;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}