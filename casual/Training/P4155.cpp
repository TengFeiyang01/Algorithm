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
const int N = 1e5 + 13;

struct war {
	int id, l, r;
	bool operator<(const war& b) const {
		return l < b.l;
	}
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<war> w(n * 2 + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> w[i].l >> w[i].r;
    	w[i].id = i;
    	if (w[i].r < w[i].l) w[i].r += m;
    }
    std::sort(w.begin() + 1, w.begin() + n + 1);
    for (int i = n + 1; i <= n * 2; ++i) {
    	w[i] = w[i - n];
    	w[i].l += m;
    	w[i].r += m;
    }

    //go[i][j] 从i出发 跳 2^j 次能跳到的位置。
    std::vector go(2 * n + 1, std::vector<int>(20));

    //init
    int ne = 0;
    for (int i = 1; i <= n * 2; ++i) {
    	while (ne <= 2 * n and w[ne].l <= w[i].r) {
    		ne++;
    	}
    	go[i][0] = ne - 1;
    }
    for (int i = 1; 1 << i <= n; ++i)
    	for (int s = 1; s <= n * 2; ++s) 
    		go[s][i] = go[go[s][i - 1]][i - 1];

    //计算时，从大到小枚举
    std::vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
        //len是当前士兵的终点。
    	int len = w[i].l + m, cur = i, ans = 1;
    	for (int j = log2(n) + 1; j >= 0; --j) {
    		int p = go[cur][j];
    		if (p and w[p].r < len) {
    			ans += 1 << j;
    			cur = p;
    		}
    	}
    	res[w[i].id] = ans + 1;
    }
    for (int i = 1; i <= n; ++i) {
    	std::cout << res[i] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
