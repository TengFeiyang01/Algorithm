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
const int N = 1e5 + 13;

void solve(int n) {
	std::vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sum	+= a[i];
	}
	std::vector<bool> st(n, 0);
	std::sort(all(a), std::greater<int>());

	int length = a[0];

	std::function<bool(int, int, int)> dfs = [&](int u, int cur, int start) -> bool {
		if (u * length == sum) return true;
		if (cur == length) return dfs(u + 1, 0, 0);

		//搜索顺序剪枝 从start开始枚举
		for (int i = start; i < n; ++i) {
			if (st[i] || cur + a[i] > length) continue;	//可行性剪枝
				
			st[i] = true;
			if (dfs(u, cur + a[i], i + 1)) return true;
			st[i] = false;
y
			//头尾剪枝
			if (!cur || cur + a[i] == length) return false;
 	
			//如果当前木棍加进去失败了 直接跳过后续所有木棍
			int j = i;
			while (j < n && a[j] == a[i]) ++j;
			i = j - 1;			
		}
		return false;
	};

	while (true) {
		if (sum % length == 0 && dfs(0, 0, 0)) {
			std::cout << length << "\n";
			break;
		}
		length++;
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    while (std::cin >> t, t) {
	    solve(t);
    }

    return 0;
}
