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

struct Node{
    Node *arr[2];
    int cnt;
    Node(){
        arr[0]=NULL;
        arr[1]=NULL;
        cnt = 0;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    void inst(string s, int num){
        Node *node=root;
        for(int i=0; i<s.length(); i++){
            int bit = s[i]-'0';
            node->cnt++;
            // node->Nend.pb(num);
            if(node->arr[bit] == NULL){
                node->arr[bit] = new Node();
            }
            node = node->arr[bit];
        }
        node->cnt++;
        // node->Nend.pb(num);
    }
    void delt(string s, int num){
        Node *node=root;
        for(int i=0; i<s.length(); i++){
            int bit = s[i]-'0';
            node->cnt--;
            // node->Nend.pop_back();
            if(node->arr[bit] == NULL){
                node->arr[bit] = new Node();
            }
            node = node->arr[bit];
        }
        node->cnt--;
        // node->Nend.pop_back();
    }
    int srh(string s){
        Node *node = root;
        for(int i=0; i<s.length(); i++){
            if(node->arr[s[i]-'0']==NULL || node->cnt<=0) return 0;
            node = node->arr[s[i]-'0'];
        }
        if(node->cnt<=0) return 0;
        return 1;
        // return node->Nend[0];
    }
};

string get1(int num){
    int msb = log2(num);
    string res = "";
    for(int i=msb; i>=0; i--){
        if(num & (1LL<<i)){
            res += '1';
        }else{
            res += '0';
        }
    }
    return res;
}

void solve()
{
    ll n; cin>>n;
    vi arr(n), brr(n);
    fr(i,n) cin>>arr[i];
    fr(i,n) cin>>brr[i];
    vector<tuple<int,string,int>> v;
    Trie trie;
    fr(i,n){
        int num = brr[i];
        string res = get1(num);
        trie.inst(res,num);
    }
    bool f = true;
    fr(i,n){
        int num = arr[i];
        string res = get1(num);
        while(res.back()=='0') res.pop_back();
        int m = res.length();
        v.pb({m,res,num});
    }
    sort(v.rbegin(),v.rend());
    // debug(v);
    // for(auto x: v){
    //     cout<<get<0>(x)<< " "<<get<1>(x)<< " "<<get<2>(x)<<endl; 
    // }
    fr(i,n){
        int ans = trie.srh(get<1>(v[i]));
        debug(ans);
        if(ans==0){
            f = false;
            break;
        }
        trie.delt(get<1>(v[i]),get<2>(v[i]));
    }

    if(f){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

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
