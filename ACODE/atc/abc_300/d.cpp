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
const int N = 5e5 + 13;
std::vector<ll> prime;
int mp[N + 1]{0};

void init() {
    for (ll i = 2; i <= N; ++i) {
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

void solve() {
    ll n;
    std::cin >> n;
    int m = prime.size();
    int ans = 0;
    for (int i = 0; i < m - 2 and prime[i] * prime[i] * prime[i] < n / (prime[i] * prime[i]); ++i) {
    	ll t = prime[i] * prime[i];
    	for (int j = i + 1; j < m - 1 and prime[j] < n / t; ++j) {
    		for (int k = j + 1; k < m; ++k) {
    			if (t * prime[j] * prime[k] <= n / prime[k]) {
    				ans += 1;
    			} else {
    				break;
    			}
    		}
    	}
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    init();
    solve();

    return 0;
}
