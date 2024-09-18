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
const int N = 1e6 + 13;
int n, m;
int mp[N + 1]{0};
std::vector<int> prime;

//1e9 内 最多 10 个 不同质因子
//分解质因数
//使用set去存每个数的质因子

void solve() {
    std::cin >> n;
    std::set<int> s;
    int ok = 0;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> m;
    	for (auto p : prime) {
    		if (p * p > m) break;
    		if (m % p == 0) {
    			if (s.count(p)) {
    				ok = 1;
    				break;
    			}
    			s.insert(p);
    			while (m % p == 0) m /= p;
    		}
    	}
    	if (m > 1) {
    		if (s.count(m)) {
    			ok = 1;
    		}
            s.insert(m);
    	}
    }
    if (ok) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 2; i <= N; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            prime.push_back(i);
        }
        for (auto p : prime) {
            if (i * p > N) break;
            mp[i * p] = p;
            //提前退出
            if (i % p == 0) break;
        }
    }

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
