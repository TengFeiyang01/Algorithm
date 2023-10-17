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
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    // a + b = c   b是负的mod回文 a也是回文
    std::vector<int> c(n);
    int ok = 1;
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    std::vector<int> a(n), b(n);
	for (int i = 0; i < n / 2; ++i) {
		int md1 = (c[i] + m) % m;
		int md2 = (c[n - i - 1] + m) % m;
		int dif = abs(md1 - md2);
		b[i] = (m - dif) / 2; 
		b[n - i - 1] = m - b[i];
		int t = (c[i] + c[n - i - 1]);
		if (t % 2 && m % 2 == 0) ok = 0;
		a[i] = a[n - i - 1] = t / 2;
	}
	if (n % 2) {
		a[n / 2 + 1] = c[n / 2 + 1];
		b[n / 2 + 1] = 0;
	}
	for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
		for (int i = 0; i < n; ++i) std::cout << b[i] << " \n"[i == n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
