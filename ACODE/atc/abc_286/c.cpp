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
#include <stack>
#include <numeric>
#include <cmath>
 
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
const int N = 1e5 + 13;

void solve() {
    ll n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    
    s += s;
    ll ans = (ll)inf * inf;
    for (int i = 0; i < n; ++i) {
        ll tmp = a * i; 
        int cnt = 0;
        for (int l = i, r = i + n - 1; l < r; l++, r--) {
            cnt += (s[l] != s[r]);
        }
        tmp += cnt * b;
        ans = std::min(ans, tmp);
    }
    std::cout << ans;

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
