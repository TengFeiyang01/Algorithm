#include <bits/stdc++.h>
 
using ll = long long;
constexpr ll inf = 1e18;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
	
    std::sort(a.begin(), a.end());
	
	std::vector<ll> f(n + 1, inf);
	for (int i = 0; i < n; ++i) {
		//f[k] 表示给前 k 个数加了之后数组的最小值
		f[i + 1] = std::min(f[i] + 1, a[i] + 1);
	}
	
	ll sum = std::accumulate(a.begin(), a.end(), 0LL);
	while (q--) {
		ll k;
		std::cin >> k;

		if (k < n) {
			std::cout << std::min(f[k], a[k]) << " ";
		} else {
			ll ans, s = sum;
			//如果加到最后一个数之后，k是奇数  那需要的是把 (k - n) / 2 个 -1 分配到数组中
			if ((k - n) % 2 == 0) {
				ans = f[n] + k - n;
				s += 1LL * n * (k + k - n + 1) / 2 - (k - n) / 2;
			} else { 
				//否则就只能给前 n-1 个数加，再把剩余的 (k - n + 1)/ 2 个 -1 分配出去
				ans = std::min(a[n - 1], f[n - 1] + k - (n - 1));
				s += 1LL * (n - 1) * (k + k - n + 2) / 2 - (k - n + 1) / 2;
			}
			//ans不会大于数组平均值的下取整  负数的时候 需要(s - n + 1) / n
			ans = std::min(1LL * ans, s >= 0 ? s / n : (s - n + 1) / n);
			std::cout << ans << " ";
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
