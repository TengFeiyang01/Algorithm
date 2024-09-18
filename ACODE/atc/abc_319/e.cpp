#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    std::vector<int> P(N), T(N);
    for (int i = 1; i < N; ++i) {
    	std::cin >> P[i] >> T[i];
    }


    constexpr int L = 840;
    std::vector<i64> ans(L);
    for (int t = 0; t < L; ++t) {
    	i64 res = t;
    	res += X;
    	for (int i = 1; i < N; ++i) {
    		res += (P[i] - res % P[i]) % P[i];
    		res += T[i];
    	}
    	res += Y;
    	ans[t] = res;
    }

    int Q;
    std::cin >> Q;
    while (Q--) {
    	i64 s;
    	std::cin >> s;
    	std::cout << ans[s % L] + s - s % L << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}