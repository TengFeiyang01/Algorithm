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
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
using vector = std::vector<std::vector<PII>>;
const int N = 1e5 + 13;

//树的直径
/*
  性质：
  	 1、	直径两端点一定是两个叶子节点。
  	 2、	距离任意点最远的点一定是直径的一个端点
	 3、 对于两棵树，如果第一棵树直径两端点为(u,v)，第二棵树直径两端点为(x,y)，用一条边将两棵树连接，那么新树的直径一定是u,v,x,y中的两个点。
*/

//求两次最远点
/*
	任取一点做起点，找到距离该点最远的点u
	找距离u最远的点v DFS、 BFS
*/
// 树的中心  直径上到其他店距离最短的点
//换根dp


int head[N], idx = 0;
struct e{
    int to, next, w;
}edge[N];

std::vector<int> d1(N), d2(N), up(N);
std::vector<int> p1(N), p2(N);

void add(int u, int v, int w) {
    edge[idx].to = v;
    edge[idx].next = head[u];
    edge[idx].w = w;
    head[u] = idx++;
}

int dfs_d(int u, int fa) {
	d1[u] = d2[u] = -inf;
	for (int i = head[u]; i != -1; i = edge[i].next) {
		auto[v, _, w] = edge[i];
		if (v == fa) continue;
		int d = dfs_d(v, u) + w;
		if (d >= d1[u]) {
			p2[u] = p1[u];
			p1[u] = v;
			d2[u] = d1[u];
			d1[u] = d;
		} else if (d > d2[u]) {
			d2[u] = d;
			p2[u] = v;
		}
	}
	if (d1[u] == -inf) d1[u] = d2[u] = 0;

	return d1[u];	
}

//如果p1[u] == v 说明以u为根的子树往下走最大的d经过了v 那么 d2[u] 肯定不经过v 且是最长路径 可视为从 v 到 u 再往其他地方走

void dfs_up(int u, int fa) {
	for (int i = head[u]; i != -1; i = edge[i].next) {
		auto[v, _, w] = edge[i];
		if (v == fa) continue;
		if (p1[u] == v) {
			up[v] = std::max(up[u], d2[u]) + w;
		} else {
			up[v] = std::max(up[u], d1[u]) + w;
		}
		dfs_up(v, u);
	}
}

void solve() {
	int n;
	std::cin >> n;
	memset(head, -1, sizeof head);

	//up记录往上走的最长路径

    for (int i = 1; i < n; ++i) {
	    int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);	
	}
	
	dfs_d(1, -1);
	dfs_up(1, -1);
	
	int res = inf;

	for (int i = 1; i <= n; ++i) {
		res = std::min(res, std::max(d1[i], up[i]));
	}

	std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
