#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1000100;
std::vector<int> primes;
int min_div[N + 1]{0}, A[N];
int n, a, b;

void init() {
	min_div[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (!min_div[i]) {
			primes.push_back(i);
			min_div[i] = i;
		}
		for (auto p : primes) {
			if (i * p > N) break;
			min_div[i * p] = p;
			if (i % p == 0) break;
 		}
	}
}

int get(int x) {
	int s = 0;
	for (int p = 2; p * p <= x; ++p) {
		if (x <= N) break;
		if (x % p == 0) {
			int cnt = 0;
			while (x % p == 0) {
				cnt++;
				x /= p;
			}
			s += p * cnt;
		}
	}

	while (x > 1 and x <= N) {
		int cnt = 0, p = min_div[x];
		while (x % p == 0) {
			cnt++;
			x /= p;
		}
		s += p * cnt;
	}
	if (x >= N and x > 1) {
		s += x;
	}
	return s % n + 1;
}

void solve() {
    std::cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> A[i];
    }
    init();
    std::vector<std::vector<std::array<int, 2>>> adj(n * 2 + 3);
    for (int i = 1; i <= n; ++i) {
    	int f = get(A[i]);
    	int ff = f + n + 1;
    	adj[ff].push_back({i, 1});
    	adj[i].push_back({ff, 1});
    	if (f <= n) {
    		adj[i].push_back({f, 2});
    		adj[f].push_back({i, 2});
    	}
    }

    std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, std::greater<std::array<int, 2>>> q;
    q.push({0, a});
    std::vector<int> dist(n * 2 + 3, inf);
    dist[a] = 0;
    while (q.size()) {
    	int c = q.top()[0], u = q.top()[1];
    	q.pop();
    	
    	if (u == b) {
    		std::cout << c / 2 << "\n";
    		return;
    	}
    	for (auto [v, w] : adj[u]) {
    		// int v = p[0], w = p[1];
    		if (c + w < dist[v]) {
    			dist[v] = c + w;
    			q.push({c + w, v});
    		}
    	}
    }
    std::cout << "-1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
