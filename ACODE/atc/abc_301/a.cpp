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
    int n;
    std::string s;
    std::cin >> n >> s;

    int a = 0, t = 0;
    for (auto c : s) {
        if (c == 'T') t++;
        else a++;
        if (a == (n + 1) / 2) {
            std::cout << "A";
            return;
        } else if (t == (n + 1) / 2) {
            std::cout << "T";
            return;
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
