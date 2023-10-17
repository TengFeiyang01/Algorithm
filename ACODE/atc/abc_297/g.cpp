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

const int mod = 998244353;

void solve() {
	int n, l, r;
	std::cin >> n >> l >> r;
	r += l;
	std::vector<int> a(n);
	for (int &x : a) std::cin >> x;
	int f = 0;
	for (int x : a) {
		f ^= x % r / l;
	}    
	std::cout << (f ? "First\n" : "Second\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
