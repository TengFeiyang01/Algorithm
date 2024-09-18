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

const int mod = 1e9 + 7;

/*ll c[N][N];
void init() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j)
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}*/

ll fact[N];
ll infact[N];

ll qmi(int a, int b, int p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = (ll)a * a % p;
		b >>= 1;
	}
	return res;
}

void init() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
	}
}

void solve() {
	int a, b;
	std::cin >> a >> b;    
	//std::cout << c[a][b] << "\n";
	std::cout << fact[a] * infact[a - b] % mod * infact[b] % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	init();

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
