// O(N) using manacher algorithm.
    vector<int> manacher(string s)
    { // gives 2n-1 size manacher array. (a#c#...#d )
        string s1 = "@";
        for (auto c : s)
            s1 += c, s1 += "#";
        s1.back() = '&';
        vector<int> ans(s1.size() - 1);
        int lo = 0, hi = 0;
        for (int i = 1; i <= s1.size() - 2; i++)
        {
            if (i != 1)
                ans[i] = min(hi - i, ans[hi - i + lo]);
            while (s1[i - ans[i] - 1] == s1[i + ans[i] + 1])
                ans[i]++;
            if (i + ans[i] > hi)
                lo = i - ans[i], hi = i + ans[i];
        }
        ans.erase(begin(ans));
        for (int i = 0; i <= ans.size() - 1; i++)
            if ((i & 1) == (ans[i] & 1))
                ans[i]++;
        return ans;
    }
    string getLPS(string s)
    { // gives one of the long. palindromic substr.
        auto a = manacher(s);
        auto it = max_element(a.begin(), a.end());
        int l = *it, p;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == l)
            {
                p = i;
                break;
            }
        }
        return s.substr((p + 1) / 2 - l / 2, l);
    }
