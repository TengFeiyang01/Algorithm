#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int N = 2e6 + 13;
int x[N], y[N], c[N], sa[N], rk[N], h[N], n, m = 250;
std::string s;

void getSa() {
    for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i >= 1; i--) sa[c[x[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) y[i] = sa[i];
        for (int i = 1; i <= n; i++) c[x[y[i] + k]]++;
        for (int i = 1; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i >= 1; i--) sa[c[x[y[i] + k]]--] = y[i];

        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) y[i] = sa[i];
        for (int i = 1; i <= n; i++) c[x[y[i]]]++;
        for (int i = 1; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i >= 1; i--) sa[c[x[y[i]]]--] = y[i];

        for (int i = 1; i <= n; i++) y[i] = x[i];
        m = 0;
        for (int i = 1; i <= n; i++) {
            if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = x[sa[i - 1]];
            else x[sa[i]] = ++m;
        }
        if (n == m) break;
    }
}

struct SuffixArray {
    int n;
    std::vector<int> sa, rk, lc;
    SuffixArray(const std::string &s) {
        n = s.length();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        int k = 1;
        std::vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; ++i)
                tmp.push_back(n - k + i);
            for (auto i : sa)
                if (i >= k)
                    tmp.push_back(i - k);
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i)
                ++cnt[rk[i]];
            for (int i = 1; i < n; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            std::swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (rk[i] == 0) {
                j = 0;
            } else {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )
                    ++j;
                lc[rk[i] - 1] = j;
            }
        }
    } 

    std::vector<int> lookupAll(const std::string &t) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            auto tmp = s.substr(sa[mid]);
            if (t <= tmp) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int st = l;

        int m = t.size();
        std::vector<int> res;
        if (s.substr(sa[l], m) == t) {
            res.push_back(l);
            r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                auto tmp = s.substr(sa[mid], m);
                if (tmp <= t) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        return std::vector<int> {sa.begin() + st, sa.begin() + r + 1};
    }

    // 返回s中t匹配的索引集合 k=-1表示返回全部
    std::vector<int> lookUp(const std::string &t, int k) {
        std::vector<int> all = lookupAll(t);
        if (k < 0 || k >= all.size()) return all;
        return std::vector<int>(all.begin(), all.begin() + k);
    }
};


void getH() {
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; i++) {
        if (rk[i] == 1) continue;
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
        h[rk[i]] = k;
    }
}   

void solve() {
    std::cin >> s;
    n = s.size();
    SuffixArray suffixArray(s);
    for (int i = 0; i < n; ++i) {
        std::cout << s.substr(suffixArray.sa[i]) << "\n";
    }
    std::cout << "-----\n";

    std::string t;
    std::cin >> t;

    auto v = suffixArray.lookUp(t, 1);
    std::cout << v.size() << "\n";
    for (auto x : v) {
        std::cout << x << " ";
    }

    // s = " " + s;
    // getSa();
    // getH();
    // for (int i = 1; i <= n; i++) {
        // std::cout << sa[i] << " ";
    // }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
