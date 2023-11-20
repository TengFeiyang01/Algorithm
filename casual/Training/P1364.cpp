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
const int N = 1e4 + 13;

/*
树的重心的定义：
	树若以某点为根，使得该树最大子树的结点数最小，那么这个点则为该树的重心，一棵树可能有多个重心。

树的重心的性质：
	1、树上所有的点到树的重心的距离之和是最短的，如果有多个重心，那么总距离相等。
	2、插入或删除一个点，树的重心的位置最多移动一个单位。
	3、若添加一条边连接2棵树，那么新树的重心一定在原来两棵树的重心的路径上。
	当然，这题我们只需要用到第一条性质。
*/

/*
怎么求树的重心：
	定义几个数组：f[u] 表示以u为根的总距离，size[u]表示以u为根的子树的大小
（结点数，此题每个点要乘以权值，下文结点数均指此）。
	显然，ans=min(f[i],1<=i<=n)
	首先我们任意以一个点为根dfs一遍，求出以该点为根的总距离。方便起见，我们就以1为根。
接下来就是转移，对于每个u能达到的点v，有： f[v]=f[u]+size[1]−size[v]−size[v]
	怎么来的呢？试想，当根从u变为v的时候，v的子树的所有节点原本的距离要到u，
	现在只要到v了，每个结点的距离都减少1，那么总距离就减少size[v]，
	同时，以v为根的子树以外的所有节点，原本只要到u就行了，现在要到v，每个节点的路程都增加了1，
	总路程就增加了size[1]−size[v]，其中size[1]就是我们预处理出来的整棵树的大小，
	减去size[v]就是除以v为根的子树以外的结点数。
*/

struct edge {
	int to, next;
}e[N << 1];

int head[N]{0}, w[N]{0}, idx = 0, size[N]{0};
ll ans = inf * inf, f[N];

void add(int from, int to) {
	e[++idx].to = to;
	e[idx].next = head[from];
	head[from] = idx;
}

void dfs(int u, int fa, int dep) {
	size[u] = w[u];
	for (int i = head[u]; i; i = e[i].next) {
		if (e[i].to != fa) {
			dfs(e[i].to, u, dep + 1), size[u] += size[e[i].to];
		}
	}
	f[1] += dep * w[u];
}

void dp(int u, int fa) {
	for (int i = head[u]; i; i = e[i].next) {
		if (e[i].to != fa)
			f[e[i].to] = f[u] + size[1] - size[e[i].to] * 2, dp(e[i].to, u);
	}
	ans = std::min(ans, f[u]);
}

void solve() {
    int a, b, n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> w[i] >> a >> b;
    	if (a) {
    		add(a, i), add(i, a);
    	}
    	if (b) {
    		add(b, i), add(i, b);
    	}
    }
    dfs(1, 0, 0);
    dp(1, 0);

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
