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
const int N = 1e6 + 13;

//树高期望值 O(log n) 枚举每个子树作为根节点 总时间复杂度期望为 O(nlog n)

struct node {
	int val;
	int lson, rson;
}tr[N];

int n, ans = 0;

bool symtry(int t1, int t2) {
	if (t1 == -1 && t1 == -1) return true;
	if (t1 == -1 || t2 == -1) return false;
	if (tr[t1].val != tr[t2].val) return false;
	return symtry(tr[t1].lson, tr[t2].rson) && symtry(tr[t1].rson, tr[t2].lson);
}

int cnt(int u) {
	if (u == -1) return 0;
	return 1 + cnt(tr[u].lson) + cnt(tr[u].rson);
}

void solve() {
	std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> tr[i].val;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> tr[i].lson >> tr[i].rson;
    }
    for (int i = 1; i <= n; ++i) {
    	if (symtry(i, i)) ans = std::max(ans, cnt(i));
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
