#include <bits/stdc++.h>
 
using i64 = long long;
constexpr i64 inf = 1e17;

void solve() {
    int N, A, B, C;
    std::cin >> N >> A >> B >> C;
    std::vector D(N, std::vector<i64>(N));
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		std::cin >> D[i][j];
    	}
    }

    std::vector<i64> dist(N, inf), rdist(N, inf);
    std::vector<bool> st(N);
    dist[0] = 0;
    
   	for (int i = 0; i < N; ++i) {
   		int t = -1;
   		for (int j = 0; j < N; ++j) {
   			if (!st[j] && (t == -1 or dist[j] < dist[t])) {
   				t = j;
   			}
   		}
   		st[t] = true;
   		for (int j = 0; j < N; ++j) {
   			dist[j] = std::min(dist[j], dist[t] + D[t][j] * A);
   		}
   	}

   	st.assign(N, false);
    rdist[N - 1] = 0;
   	for (int i = 0; i < N; ++i) {
   		int t = -1;
   		for (int j = 0; j < N; ++j) {
   			if (!st[j] && (t == -1 or rdist[j] < rdist[t])) {
   				t = j;
   			}
   		}
   		st[t] = true;
   		for (int j = 0; j < N; ++j) {
   			rdist[j] = std::min(rdist[j], rdist[t] + D[t][j] * B + C);
   		}
   	}

   	i64 ans = inf;
   	for (int i = 0; i < N; ++i) {
   		ans = std::min(ans, dist[i] + rdist[i]);
   	}
   	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}