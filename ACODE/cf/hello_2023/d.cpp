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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int n, m, a[N], b[N];
int ST[N][24]{0};
int mn[N];

void INIT() {
	for (int len = 1; len <= N; ++len) {
		int k = 0;
		while (1 << k + 1 <= len) {
			++k;
		}
		mn[len] = k;
	}
}

void init() {
	for (int i = 1; i <= n; ++i) ST[i][0] = b[i];
	for (int j = 1; (1 << j) <= n; ++j) 
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			ST[i][j] = std::max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
	int k = mn[R - L + 1];
	return std::max(ST[L][k], ST[R - (1 << k) + 1][k]);
}

/*
	使用ST表维护b数组中的最大值，对于相同的b[i]（i = k1, k2.... km），如果 p, q 之间的最大值小于b[i], 我们可以直接对 [p, q]修改
	这样显然不会影响中间的值，修改后cnt[b[i]]--，否则我们只能对 [p] 区间单独修改，cnt[b[p]]--;如果可操作的次数cnt[b[i]] <= 0, 直接退出
*/

void solve() {
	bool flag = true;
    std::cin >> n;
	std::map<int, std::vector<int>> mp;
	std::map<int, int> cnt;
	mp.clear();
	cnt.clear();
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    	if (a[i] < b[i]) {
    		flag = false;
    	} else if (b[i] < a[i]) {
    		mp[b[i]].push_back(i);
    	}
    }
	init();

    std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		int x;
		std::cin >> x;
		cnt[x]++;
	}
	if (flag) {
		for (auto &v : mp) {
			if (cnt.find(v.first) == cnt.end() || cnt[v.first] <= 0) {
				flag = false;
				break;
			}
			int &C = cnt[v.first];
			C--;
			for (int i = 0; i < (int)v.second.size() - 1; ++i) {
				if (query(v.second[i] + 1, v.second[i + 1] - 1) > v.first) {
					C--;
					if (C < 0) {
						flag = false;
						break;
					}
				}
			}
			if (!flag) break;
		}
	}
	if (flag) std::cout << "YES\n";
	else std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    INIT();
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
