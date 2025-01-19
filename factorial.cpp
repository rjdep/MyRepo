static const int MOD = 1000000007;
static const int MAXN = 100000;

static long long fac[MAXN+1], invFac[MAXN+1];

long long modPow(long long base, int exp) {
    long long ans = 1 % MOD;
    while (exp > 0) {
        if (exp & 1) ans = (ans*base) % MOD;
        base = (base*base) % MOD;
        exp >>= 1;
    }
    return ans;
}

void buildFactorials(int n) {
    fac[0] = 1;
    for (int i=1; i<=n; i++){
        fac[i] = (fac[i-1]*i) % MOD;
    }
    invFac[n] = modPow(fac[n], MOD-2);
    for (int i=n-1; i>=0; i--){
        invFac[i] = (invFac[i+1]*(i+1))%MOD;
    }
}

long long comb(int n, int r){
    if (r<0 || r>n) return 0;
    return fac[n] * ((invFac[r]*invFac[n-r])%MOD) % MOD;
}
