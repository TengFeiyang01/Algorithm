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

void solve() {
    int n, k;
    std::cin >> n >> k;
    int cnt[N * 3];
    memset(cnt, -1, sizeof cnt);
    std::queue<int> q;

    q.push(n);
    cnt[n] = 0;
    
    while (q.size()) {
    	int t = q.front();
    	q.pop();
    	if (t - 1 >= 0 && cnt[t - 1] == -1) {
            cnt[t - 1] = cnt[t] + 1;
            q.push(t - 1);
        }
    	if (t + 1 < 2 * N && cnt[t + 1] == -1) {
            cnt[t + 1] = cnt[t] + 1; 
            q.push(t + 1);
        }
    	if (t * 2 <= N * 2 && cnt[t * 2] == -1) {
            cnt[t * 2] = cnt[t] + 1;
            q.push(t * 2);
        }
    }
    std::cout << cnt[k] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
