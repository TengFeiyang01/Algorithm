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
const int N = 1e5 + 13;
std::vector<int> post;
std::vector<int> ino;

std::unordered_map<int, int> left, right, pos;

int dfs(int pl, int pr, int il, int ir) {
	int root = post[pr];
	int k = pos[root];

	if (il < k) left[root] = dfs(pl, pl + k - 1 - il, il, k - 1);
	if (ir > k) right[root] = dfs(pl + k - il, pr - 1, k + 1, ir);

	return root;
}

void solve() {
    int n;
    std::cin >> n;
	post.resize(n);
	ino.resize(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> post[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> ino[i];
		pos[ino[i]] = i;
	}	
	
	int root = dfs(0, n - 1, 0, n - 1);

	std::queue<int> q;
	q.push(root);
	while (q.size()) {
		auto t = q.front();
		q.pop();
		std::cout << t << " ";
		if (left.count(t)) q.push(left[t]);
		if (right.count(t)) q.push(right[t]);
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
