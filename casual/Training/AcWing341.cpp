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
const int N = 1e5 + 13, M = N * 20;

int n, m;
int price[N];
int h[N], rh[N], e[M], ne[M], idx = 0;
int dmin[N], dmax[N];
bool st[N];

void add(int *h, int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa(int *d, int start, int *h, bool flag) {
	std::queue<int> q;
	memset(st, 0, sizeof st);
	if (flag) memset(d, 0x3f, sizeof dmin);

	q.push(start);
	st[start] = true;
	d[start] = price[start];

	while (q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (flag && d[j] > std::min(d[t], price[j]) || !flag && d[j] < std::max(price[j], d[t])) {
				if (flag) d[j] = std::min(d[t], price[j]);
				else d[j] = std::max(d[t], price[j]);
				if (!st[j]) {
					st[j] = true;
					q.push(j);
				}
			}
		}
	}

}

void solve() {
	std::cin >> n >> m;
	memset(h, -1, sizeof h);    
	memset(rh, -1, sizeof rh);
	for (int i = 1; i <= n; ++i) {
		std::cin >> price[i];
	}    
	while (m--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(h, a, b); add(rh, b, a);
		if (c == 2) {
			add(h, b, a);
			add(rh, a, b);
		}
	}

	spfa(dmin, 1, h, true);
	spfa(dmax, n, rh, false);

	int res = 0;
	for (int i = 1; i <= n; ++i) res = std::max(dmax[i] - dmin[i], res);

	std::cout << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
