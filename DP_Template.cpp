#include<bits/stdc++.h>
using namespace std;

const string s = "narek";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt; cin >> tt;

    while(tt--) {
        int n, m; cin >> n >> m;
        
        vector<string>a(n);
        for(auto &i : a) cin >> i;

        vector<vector<int>>dp(n, vector<int>(5, -1));

        auto f = [&](int index, int letter, auto &&self) -> int {
            if(index == n) return -2 * letter;   
            if(dp[index][letter] != -1) return dp[index][letter];

            int notTake = self(index + 1, letter, self);
            int take = 0, idx = letter;

            for(auto &i : a[index]) {
                if(i == s[idx]) idx = (idx + 1) % 5, take++;
                else if(i == 'n' || i == 'a' || i == 'r' || i == 'e' || i == 'k') take--;
            }
            take += self(index + 1, idx, self);
            return dp[index][letter] = max(take, notTake);
        };

        cout << f(0, 0, f) << "\n";
    }
}
