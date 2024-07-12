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

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    } 
    ll k = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return k;
}


void solve() {
    ll a, b, cnt = 0;
    std::cin >> a >> b;
    if (a > b) {
    	std::swap(a, b);
    }
    while (a != b) {
    	if (b % a == 0) {
    		cnt += (b - 1) / a;
    		break;
    	}
    	cnt += b / a;
    	b -= b / a * a;
        if (a > b) {
    		std::swap(a, b);
    	}
    	if (b == 1) {
    		cnt += a - 1;
    		break;
    	}
    }
    std::cout << cnt;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
