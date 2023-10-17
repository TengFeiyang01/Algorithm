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
const int N = 5e4 + 13;

std::vector<int> primes;
bool st[N];

void init() {
    for (int i = 2; i < N; ++i) {
        if (!st[i]) primes.push_back(i);
        for (int p : primes) {
        	if (i * p > N) break;
            st[p * i] = true;
            if (i % p == 0) break;
        }
    }
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::vector<PII> factor;
    int t = d;
    for (int p : primes) {
    	if (t / p < p) break;
    	if (t % p == 0) {
    		int s = 0;
    		while (t % p == 0) {
    			t /= p;
    			s++;
    		}
    		factor.emplace_back(p, s);
    	}
    }
    if (t > 1) factor.emplace_back(t, 1);


    std::vector<int> divide;
    std::function<void(int, int)> dfs = [&](int u, int p) {
    	if (u == sz(factor)) {
    		divide.push_back(p);
    		return;
    	}

    	for (int i = 0; i <= factor[u].second; ++i) {
    		dfs(u + 1, p);
    		p *= factor[u].first;
    	}
    };

    dfs(0, 1);

    int ans = 0;
    for (int x : divide) {
    	if (gcd(a, x) == b && (ll)c * x / gcd(c, x) == d) ans++;
    }
    std::cout << ans << "\n";
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
