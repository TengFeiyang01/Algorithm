#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> wk(n + 1), wc(n + 1), fa(n + 1), ans1;
	std::vector<bool> st(n + 1);
	std::vector<PII> p(n + 1), ans2;
	std::vector<ll> dist(n + 1, inf);

	auto get = [&](int a, int b) ->ll {
		auto[ax, ay] = p[a];
		auto[bx, by] = p[b];
		int dx = abs(ax - bx), dy = abs(ay - by);
		return (ll)(dy + dx) * (wk[a] + wk[b]);
	};

	for (int i = 1; i <= n; ++i) std::cin >> p[i].first >> p[i].second;
	for (int i = 1; i <= n; ++i) std::cin >> wc[i];
	for (int i = 1; i <= n; ++i) std::cin >> wk[i];
	


	dist[0] = 0;
	st[0] = true;
	for (int i = 1; i <= n; ++i) dist[i] = wc[i];
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int t = -1;

		for (int j = 1; j <= n; ++j) 
			if (!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		res += dist[t];
		st[t] = true;
		if (!fa[t]) ans1.push_back(t);
		else ans2.emplace_back(fa[t], t);
		for (int j = 1; j <= n; ++j)
			if (dist[j] > get(t, j)) {
				dist[j] = get(t, j);
				fa[j] = t;
			}
	}

	std::cout << res << "\n";
	std::cout << ans1.size() << "\n";
	for (int &v : ans1) std::cout << v << " ";
	std::cout << "\n" << ans2.size() << "\n";
	for (auto&[x, y] : ans2) std::cout << x << " " << y << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
