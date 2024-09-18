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

void solve() {
	ll n, m;
	std::cin >> n >> m;

	int ok = 0;
	//(1, 1)确定行or列的
	std::cout << "? 1 1" << std::endl;
	

	//(t, t)查询位置
	ll d, d1, d2;
	std::cin >> d;
	ll x, y, t = d + 1;
	if (t <= m and t <= n) {
		//行列都有可能
		std::cout << "? " << t << " " << t << std::endl;
		std::cin >> d1;
		std::cout << "? " << t << " " << 1 << std::endl;
		std::cin >> d2;
		if (d2 < d) {
			std::cout << "! " << t << " " << 1 + d2 << std::endl;
		} else {
			std::cout << "! " << t - d1 << " " << t << std::endl; 
		}		
	} else if (t > m) {
		//只可能在行上
		std::cout << "? " << t << " " << 1 << std::endl;
		std::cin >> d1;
		std::cout << "! " << t << " " << 1 + d1 << std::endl;
	} else if (t > n) {
		//只可能在列上
		std::cout << "? " << 1 << " " << t << std::endl;
		std::cin >> d1;
		std::cout << "! " << 1 + d1 << " " << t << std::endl;
	}
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
