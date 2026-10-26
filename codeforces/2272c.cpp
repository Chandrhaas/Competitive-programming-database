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

bool letsgo(ll k,vector<ll>& a, ll x) 
{
    int n = a.size();
    vector<ll> iso;

    for (int i = 0; i < n; i++) 
    {
        bool left = (i > 0 && a[i] - a[i - 1] <= k);
        bool right = (i + 1 < n && a[i + 1] - a[i] <= k);

        if (!left && !right) 
        {
            iso.pb(a[i]);
        }
    }

    ll need = 0;
    int m = iso.size();

    for (int i = 0; i < m; ) 
    {
        if (i + 1 < m && iso[i + 1] - iso[i] <= 2 * k) 
        {
            i += 2;
        } 
        else 
        {
            i++;
        }

        need++;
    }

    return need <= x;
}

void solve() {
    ll n,x,i,j;
    cin>>n>>x;

    vector<ll> a(n);
    scanv(a);

    ll lo = 1;
    ll hi = a[n-1] - a[0];

    while (lo < hi) 
    {
        ll mid = lo + (hi - lo) / 2;

        if(letsgo(mid, a, x)) 
        {
            hi = mid;
        } 
        else 
        {
            lo = mid + 1;
        }
    }

    cout<<lo<<'\n';
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