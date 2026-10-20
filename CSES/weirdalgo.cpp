#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef string str;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

typedef pair<int, int> pi;
typedef pair<int,pair<int,int>>ppi;
typedef  priority_queue<ll>pq;
typedef  priority_queue<ll,vector<ll>,greater<ll>> mpq;
typedef  priority_queue<ppi>pqppi;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<str>vs;
typedef vector<pi> vpi;
typedef vector<vi>vvi;
typedef vector<vll>vvll;
typedef map<ll,ll>mll;
typedef map<ll,str>mls;
typedef vector<map<ll,ll>>vmll;
const int MOD=1e9+7;


template <typename T>
void scanv(T &v) {
for (auto &x : v)
cin >> x;
}

template <typename T>
void printv(const T &v) {
for (const auto &x : v)
cout << x <<" " ;
cout << endl;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


ll binexp(ll base, ll exp, ll mod = MOD){
ll result = 1;
base %= mod;
while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
}
return result;
}

vll sieve(ll n){
vector<bool> is_prime(n + 1, true);
vll primes;
is_prime[0] = is_prime[1] = false;
for (ll i = 2; i <= n; ++i) {
    if (is_prime[i]) {
        primes.pb(i);
        for (ll j = i * i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
}
return primes;
}

ll mex(vll &a) {
unordered_set<int> s(all(a));
ll mex_val = 0;
while (s.count(mex_val)) {
    ++mex_val;
}
return mex_val;
}


void solve()
{
ll n,i,j,c=0,f=0;
     cin>>n;
      cout<<n<<" ";
     while(n!=1)
     {
        if(n%2==0)
        n=n/2;
        else
        n=n*3+1;

        cout<<n<<" ";
     }
    cout<<endl;


}

int main() 
{
fastio;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

ll t=1;

while(t--){
solve();
}

    return 0;
}