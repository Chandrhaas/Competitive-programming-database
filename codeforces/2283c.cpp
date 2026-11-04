
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
    ll n,i,j,c=0,f=0;

    cin >> n;

    ll ox = 0;
    forl(i,1,n+1)
    ox ^= i;


    ll p =63-__builtin_clzll(n);
    ll k =(1LL<<(p+1)) -1;
    ll m =2*k;
    ll y =ox^m;

    if(__builtin_popcountll(y) % 2 == 1)
    {
        m++;
        y = ox^m;
    }

    ll x= 0;
    ll pr= 0;

    forl(i,0,p+1)
    {
        ll cur=(y>>i)&1LL;
        ll b=cur^pr;

        if(b)
        x|=(1LL << i);

        pr= b;
    }

    vll ans(n+1,0);

    forl(i,0,p+1)
    {
        if((x >> i) & 1LL)
        ans[1LL<<i] = 1;
    }

    forl(i,1,n+1)
    cout<<ans[i]<<" ";

    cout<<'\n';
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
