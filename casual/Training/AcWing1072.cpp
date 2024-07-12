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

//带权直径 最大值和次大值

void solve() {
		int n, ans = 0;
		std::cin >> n;

		vector g(n);
	  for (int i = 0; i < n - 1; ++i) {
			  int a, b, c;
				std::cin >> a >> b >> c;
				a--, b--;
				g[a].eb(b, c);
				g[b].eb(a, c);
		}

		//方法一 DFS
		auto dfs = [&](auto &self, int u, int fa)->int{
				int dist = 0;		//从当前点往下走的最大长度
				int d1 = 0, d2 = 0;

				for (auto[v, w] : g[u]) {
						if (v == fa) continue;
						int d = self(self, v, u) + w;
						dist = std::max(dist, d);

						if (d >= d1) {
							  d2 = d1;
							  d1 = d;
						} else if (d > d2) {
 								d2 = d;
						}
				}
				
				ans = std::max(ans, d1 + d2);
				return dist;
		};
	
		dfs(dfs, 0, -1);
		
		std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

