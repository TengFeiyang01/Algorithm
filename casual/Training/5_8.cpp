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
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::map<int, int> cnt;
    std::cin >> n >> m;
    // cnt[n] = 0;
    // std::queue<int> q;
    // q.push(n);
    // while (q.size()) {
    // 	auto t = q.front();
    // 	if (t == m) {
    // 		std::cout << cnt[t] << "\n";
    // 		break;
    // 	}
    // 	q.pop();
    // 	if (!cnt.count(t - 1)) {
    // 		q.push(t - 1);
    // 		cnt[t - 1] = cnt[t] + 1;
    // 	}
    //     if (t > m) continue;
    // 	if (!cnt.count(t * 2)) {
    // 		q.push(t * 2);
    // 		cnt[t * 2] = cnt[t] + 1;
    // 	}
    // }
    int ans = 0;
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m += 1;
        }
        ans++;
    }
    std::cout << ans + n - m;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
