#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> cnt(26), id(26);
    for (int i = 0; i < 26; ++i) id[i] = i;
    for (auto c : s) {
    	cnt[c - 'a']++;
    }
    std::ranges::sort(id, {}, [&](int i){
    	return cnt[i];
    });
    std::reverse(id.begin(), id.end());

    int maxSave = 0, k = 0;
    for (int i = 1; i <= 26; ++i) {
        if (n % i) continue;
        int save = 0;
        for (int j = 0; j < i; ++j) {
            save += std::min(cnt[id[j]], n / i);
        }
        if (save > maxSave) {
            maxSave = save;
            k = i;
        }
    }

    std::string need = "";
    int m = n / k;
    for (int i = 0; i < k; ++i) {
        if (cnt[id[i]] > m) {
            cnt[id[i]] = m;
        } else {
            char c = 'a' + id[i];
            if (m - cnt[id[i]]) {
                need += std::string(m - cnt[id[i]], c);
            }
        }
    }

    for (int i = k; i < 26; ++i) {
        cnt[id[i]] = 0;
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        auto c = s[i] - 'a';
        if (cnt[c] > 0) {
            cnt[c]--;
        } else {
            s[i] = need[j++];
        }
    }
    std::cout << n - maxSave << "\n";
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
