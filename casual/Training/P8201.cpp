#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, w[N];
// Graph
vector<int> G[N];
//Query
struct Query { int x, y, k, lca, f_lca, id; };
vector<Query> query;
namespace Tarjan_LCA {
	int fa[N];
	void init() { for (int i = 1; i <= n; ++i) fa[i] = i; }
	int find(int x) {
		if (x != fa[x]) fa[x] = find(fa[x]);
		return fa[x];
	}
	void merge(int x, int y) { fa[find(x)] = find(y); }
	//Tarjan
	vector<int> Q[N];
	int vis[N], father[N];
	void Tarjan(int x, int f) {
		vis[x] = 1, father[x] = f;
		for (int y : G[x])
			if (y != f) Tarjan(y, x), merge(y, x);
		for (int id : Q[x]) {
			Query &q = query[id];
			int y = x ^ q.x ^ q.y;
			if (vis[y])
				q.lca = find(y), q.f_lca = father[q.lca];
		}
	}
	void solve() {
		for (Query q : query)
			Q[q.x].push_back(q.id), Q[q.y].push_back(q.id);
		init();
		Tarjan(1, 0);
	}
}
//dfs1
int S[N];
void dfs1(int x, int f) {
	S[x] = S[f] ^ w[x];
	for (int y : G[x]) if (y != f) dfs1(y, x);
}
//dfs2
int vis_S[20000010];
struct Query2 { int id, W, f; };
vector<Query2> qq[N];
int ans[N];
void dfs2(int x, int f) {
	++vis_S[w[x]];
	for (Query2 q : qq[x])
		ans[q.id] += vis_S[q.W] * q.f;
		for (int y : G[x])
			if (y != f) dfs2(y, x);
	--vis_S[w[x]];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 0; i < m; ++i) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		query.push_back((Query){x, y, k, -1, -1, i});
	}
	Tarjan_LCA::solve();
	dfs1(1, 0);
	for (Query q : query) {
		int W = S[q.x] ^ S[q.y] ^ w[q.lca] ^ q.k;
		qq[q.x    ].push_back((Query2){q.id, W,  1});
		qq[q.y    ].push_back((Query2){q.id, W,  1});
		qq[q.lca  ].push_back((Query2){q.id, W, -1});
		qq[q.f_lca].push_back((Query2){q.id, W, -1});
	}
	dfs2(1, 0);
	for (int i = 0; i < m; ++i)
		puts(ans[i] > 0 ? "Yes" : "No");
	return 0;
}