#include <bits/stdc++.h>

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
const int N = 1e4 + 13;

//https://www.lanqiao.cn/problems/2385/learning/?contest_id=80
std::vector<int> prime;

int mp[N + 1]{0};

void init() {
    for (int i = 2; i < N; ++i) {
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
}

//dp问题
//当前位置的最值可以由能跳到当前位置的最值推过来
void solve() {
    init();
    int n;
    std::cin >> n;
    std::vector<int> sc(n + 1);
    std::vector<int> dp(n + 1, -inf);
    for (int i = 1; i <= n; ++i) std::cin >> sc[i];
    dp[1] = sc[1];
    for (int i = 2; i <= n; ++i) {
    	for (int j = 1; j < i; ++j) {
    		if (j + 1 == i || j + mp[n - j] >= i) 
    			dp[i] = std::max(dp[i], dp[j]);
    	}
        dp[i] += sc[i];
    }
    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
