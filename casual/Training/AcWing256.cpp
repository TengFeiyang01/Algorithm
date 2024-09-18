#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 6e5 + 13;

int s[N]{0};
int root[N], tr[N * 24][2], idx = 0;
int max_id[N * 24];

void insert(int i, int k, int p, int q) {
	if (k < 0) {
		max_id[q] = i;
		return;
	}
	int v = s[i] >> k & 1;
	if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
	tr[q][v] = ++idx;
	insert(i, k - 1, tr[p][v], tr[q][v]);
	max_id[q] = std::max(max_id[tr[q][0]], max_id[tr[q][1]]);
}


int query(int root, int L, int C) {
	int p = root;
	for (int i = 23; i >= 0; --i) {
		int v = C >> i & 1;
		if (max_id[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];
		else p = tr[p][v];
	}
	return C ^ s[max_id[p]];
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 23, 0, root[0]);

    for (int i = 1; i <= n; ++i) {
    	std::cin >> s[i];
    	s[i] ^= s[i - 1];
    	root[i] = ++idx;
    	insert(i, 23, root[i - 1], root[i]);
    }

    std::string op;
    while (m--) {
    	std::cin >> op;
    	int l, r, x;
    	if (op == "A") {
    		std::cin >> s[++n];
    		s[n] ^= s[n - 1];
    		root[n] = ++idx;
    		insert(n, 23, root[n - 1], root[n]);
    	} else {
    		std::cin >> l >> r >> x;
    		std::cout << query(root[r - 1], l - 1, x ^ s[n]) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
