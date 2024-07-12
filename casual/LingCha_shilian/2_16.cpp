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

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
	int x = 0;
	std::vector<int> cnt(n); 
/*	for (int i = 0; i < n; ++i) {
		std::cout << s[i] << " \n"[i == n - 1];
	}	*/
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') x++;
		else x--;
		cnt[i] = x;
		//std::cout << cnt[i] << " \n"[i == n - 1];
	}
	for (int i = n - 2; i >= 0; --i)
		cnt[i] = std::min(cnt[i + 1], cnt[i]);
/*	for (int i = 0; i < n; ++i)
		std::cout << cnt[i] << " \n"[i == n - 1];*/
	int ans = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {	//如果cnt[i] == 2 表明当前是左括号多 且当前是左括号， 可以考虑将其修改 修改后cnt -= 2 刚好为0
			if (cnt[i] == 2 && x == 2) ans++;
			b++;
		} else {
			if (cnt[i] == -2 && x == -2) ans++;
			b--;
		}
		if (b < 0) break;
	}
	printf("%d\n", ans);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
