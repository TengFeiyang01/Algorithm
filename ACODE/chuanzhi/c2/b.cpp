#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::map<int, int> cnt;
    for (auto c : s) {
    	cnt[c]++;
    }
    std::vector<int> a;
    for (auto [k, v] : cnt) {
    	a.push_back(v);
    }
    std::sort(a.begin(), a.end(), std::greater<int>());

	i64 ans = 0, i = 0;;
    while (k) {
    	if (k >= a[i]) {
            ans += i64(a[i]) * a[i];
            k -= a[i];
        } else {
            ans += k * k;
            break;
        }
        i++;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
