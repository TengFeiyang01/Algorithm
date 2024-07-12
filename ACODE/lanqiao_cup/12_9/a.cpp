#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int N = 1e5 + 10;
std::vector<int> pri;
bool not_prime[N];

void pre(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        // i % pri_j == 0
        // 换言之，i 之前被 pri_j 筛过了
        // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定会被
        // pri_j 的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break
        // 掉就好了
        break;
      }
    }
  }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> sum(n + 2);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> sum[i];
    	sum[i] += sum[i - 1];
    }

    i64 ans = sum[2];

    for (int p : pri) {
    	if (p > n) break;
    	for (int i = p; i <= n; ++i) {
    		ans = std::max(ans, sum[i] - sum[i - p]);
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    pre(100001);
    solve();

    return 0;
}
