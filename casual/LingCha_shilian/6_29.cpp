#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int x, d;
    std::cin >> x >> d;
    auto isPrime = [&](int n) ->bool {
    	for (int i = 2; i <= n / i; ++i) {
    		if (n % i == 0) {
    			return false;
    		}
    	}
    	return true;
    };
    int k = 0;
    while (x % d == 0) {
    	x /= d;
    	k++;
    }
    if (k > 1 // 如果 k = 1，那么方案只有一种，x 自己，不符合要求 
        and (!isPrime(x) // x 是合数，有多种分解
        or  // 此时 x 是 1 或质数
            // 需要拿一个 d 出来，分解给 x * 1 * 1 * ...
            // 那么 d 必须是合数，且至少要 3 个 d
            // 特别地，如果有 3 个 d，那么 d 不能分解成 x^2（注意 x 是质数），否则 x 分给 x 得到 x^2=d，不符合要求
         !(k == 2 or k == 3 and i64(d) == i64(x) * x or isPrime(d)))) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
