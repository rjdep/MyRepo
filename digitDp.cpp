// Photon in a double-slit !!
#include <bits/stdc++.h>
#define ffr(i, a, b) for (int i = (a); i <= (b); i++)
#define rff(i, a, b) for (int i = (a); i >= (b); i--)
#define fr(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define ppb pop_back
#define ppf push_front
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define mk make_pair
#define endl '\n'
#define MOD 1000000007
#define in insert
#define sz(x) (ll)(x).size()
#define mem(a, b) memset(a, b, sizeof(a))
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

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
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long

// #undef TRACE
// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)enum name
{
    
};
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<vi> graph;
template <class T>
void mxi(T &a, const T &b) { a = max(a, b); }
template <class T>
void mni(T &a, const T &b) { a = min(a, b); }
ld EPS = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
void show(vi arr){for(auto x: arr){cout<<x<<" ";}cout<<endl;}
ll binpow(ll a, ll b){ll res=1;while(b!=0){if(b&1)res*=a;a*=a;b>>=1;}return res;}
ll binpow(ll a, ll b, ll md){ll res=1;a%=md;if(a==0)return 0;while(b!=0){if(b&1)res*=a,res%=md;a*=a,a%=md;b>>=1;}return res%md;}
// Use mt19937_64 for 64 bit random numbers.

int dp[20][2][2][2][2][64][1<<5];

int LCM(int a,int b){
    return (a*b)/(__gcd(a,b));
}
int n;
string L,R;
int rec(int level, int tlo, int thi, int five, int flag, int rem, int mask){
    if(level==n){
        // debug(mask,rem,flag,five);
        if(!flag) return 0;
        for(int i=0; i<=4; i++){
            if(i==2) continue;
            int num = 2*i+1;
            if(mask & (1<<i)){
                if(rem%num == 0) return 0;
            }
        }
        if(mask & (1<<2)){
            if(five) return 0;
        }
        return 1;

    }
    if(dp[level][tlo][thi][five][flag][rem][mask] != -1) return dp[level][tlo][thi][five][flag][rem][mask];
    int ans = 0;
    int lo = 0, hi = 9;
    if(!tlo) lo = L[level]-'0';
    if(!thi) hi = R[level]-'0';
    for(int i=lo; i<=hi; i++){
        int ntlo = tlo || (i>L[level]-'0');
        int nthi = thi || (i<R[level]-'0');
        if(flag){
            if(i%2==0) continue;
            ans = (ans + rec(level+1,ntlo,nthi,i==5,flag,(rem*10 + i)%63,mask | (1<<(i/2))));
        }else{
            if(i==0){
                ans = (ans + rec(level+1,ntlo,nthi,five,flag,rem,mask));
            }else{
                if(i%2==0) continue;
                ans = (ans + rec(level+1,ntlo,nthi,i==5,1,(rem*10 + i)%63,mask | (1<<(i/2))));
            }
        }
    }
    return dp[level][tlo][thi][five][flag][rem][mask]=ans;
}

void solve()
{
    int l,r,k;
    cin>>l>>r>>k;
    int lo = l, hi = r;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        memset(dp,-1,sizeof(dp));
        L = to_string(lo);
        R = to_string(mid);
        int d = R.length()-L.length();
        string res = "";
        while(d--){
            res += '0';
        }
        L = res + L;
        n = R.length();
        int ser = rec(0,0,0,0,0,0,0);
        // debug(lo,mid,ser,mid,k);
        // debug(ser);
        // break;
        if(ser<k){
            lo=mid+1;
            k -= ser;
        }else{
            ans = mid;
            hi=mid-1;
        }
        // debug(lo,hi,mid,ans,ser,k);
    }
    cout<<ans<<endl;
}

void init(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

signed main()
{
    init();
    int _t, tab;
    _t=1;
    cin >> _t;
    tab = _t;
    while (_t--)
    {
        //cout<<"Case #"<<(tab -_t)<<": ";
        solve();
    }
#ifdef TRACE
    cerr << runtime();
#endif
}
