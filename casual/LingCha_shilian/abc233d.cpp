#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N;
    i64 k;
    std::cin >> N >> k;
    std::unordered_map<i64, i64> cnt;
    cnt[0] = 1;
    i64 s = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
    	int x;
    	std::cin >> x;
    	s += x;
    	ans += cnt[s - k];
    	cnt[s] += 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}