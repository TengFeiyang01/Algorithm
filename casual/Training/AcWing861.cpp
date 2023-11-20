#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, n1;
int head[N], idx = 0;
struct e{
    int to, next;
}edge[N];

int match[N]{0};
int vis[N]{0};

void add(int u, int v) {
    edge[idx].to = v;
    edge[idx].next = head[u];
    head[u] = idx++;
}

bool find(int x) {
	for (int j = head[x]; j != -1; j = edge[j].next) {
		int y = edge[j].to;

		if (!vis[y]) {
			vis[y] = true;
			if (match[y] == 0 || find(match[y])) {
				match[y] = x;
				return true; 
			}
		}
	}
	return false;
}

void solve() {
    std::cin >> n >> n1 >> m;
    memset(head, -1, sizeof head);
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        add(u, v);
    }
    
    int res = 0;

    for (int i = 1; i <= n; ++i) {
    	memset(vis, false, sizeof vis);
    	if (find(i)) {
    		res++;
    	}
    }
    std::cout << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
