#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::vector<int> a(8);
	a[0] = 0;
	a[1] = 3;
	a[2] = 4;
	a[3] = 8;
	a[4] = 9;
	a[5] = 14;
	a[6] = 23;
	char c, d;
	std::cin >> c >> d;
	std::cout << abs(a[c - 'A'] - a[d - 'A']);

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
