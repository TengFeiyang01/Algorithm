#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 1000000007;

int qpow(int x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = 1LL * x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<i64> preSum(n + 1);
    i64 cnt0 = 0;
    for (int i = 0; i < n; ++i) {
   		preSum[i + 1] = preSum[i];
    	if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
    		preSum[i + 1]++;
    	} else {
    		preSum[i + 1]--;
    	}
    	if (i and preSum[i] == 0) {
    		cnt0++;
    	}
    }
    int x = preSum[n] == 0;
    std::cout << ((qpow(2, cnt0) - 1) + x) % mod << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
