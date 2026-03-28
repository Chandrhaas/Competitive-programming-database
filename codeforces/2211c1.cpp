#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef string str;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define forl(i,a,b) for( (i)=(a);i<=(b);(i)++)
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

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) 
{
    return a / gcd(a, b) * b;
}


ll binexp(ll base, ll exp, ll mod = MOD)
{
    ll result = 1;
    base %= mod;
    while (exp > 0) 
    {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}


vll sieve(ll n)
{
    vector<bool> is_prime(n + 1, true);
    vll primes;
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) 
        {
            primes.pb(i);
            for (ll j = i * i; j <= n; j += i) 
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}


struct DSU 
{
    vector<int> parent, size;
    DSU(int n) 
    {
        parent.resize(n + 1); 
        size.assign(n + 1, 1);
        iota(all(parent), 0);
    }
    int find(int v) 
    {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]); // Path compression
    }
    bool unite(int a, int b) 
    {
        a = find(a); b = find(b);
        if (a != b) 
        {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b]; // Union by size
            return true;
        }
        return false;
    }
};


ll mex(vll &a) 
{
    int n = a.size();
    vector<bool> present(n + 1, false);
    for (ll x : a) 
    {
        if (x <= n) present[x] = true;
    }
    ll mex_val = 0;
    while (present[mex_val]) ++mex_val;
    return mex_val;
}


int bsearch(vector<int>& a, int target) 
{
    int l = 0, r = (int)a.size() - 1;
    while(l <= r) 
    {
        int mid = l + (r - l) / 2;
        if(a[mid] == target) return mid; 
        else if(a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1; 
}


const int MAXN = 3e5 + 5; // Adjust based on problem constraints
ll fact[MAXN], invFact[MAXN];
void precompute_factorials() 
{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) 
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = binexp(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 1; i--) 
    {
    invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

ll nCr(int n, int r) 
{
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}


void solve()
{
    ll n,k,i,j,c=0,f=0;

    cin>>n>>k;

    vll a(n),b(n);
    scanv(a);
    scanv(b);
  set<ll>s;
    forl(i,0,n)
    {
        s.clear();
        forl(j,i-k,i-1)
        {
            s.insert(a[j]);
        }
        forl(j,i-k,i-1)
        {
            if(b[j]==-1)continue;
            else
            {
                auto it = s.find(b[j]);
                if(it==s.end())
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==1)
        break;
    }
    if(f==1)
    cout<<"NO\n";
    else
    cout<<"YES\n";

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