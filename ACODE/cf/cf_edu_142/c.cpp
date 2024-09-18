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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], mp[a[i]] = i;
    int mid = (n + 1) / 2;
    int t = 0;
    int k = mp[mid];
    if (n % 2) {
        int t1 = 0, t2 = 0;
        int l = mid - 1, r = mid + 1;
        for (int i = k; i >= 1; --i) {
            if (a[i] == l) {
                l--;
                t1++;
            } 
        }
        for (int j = k; j <= n; ++j) {
            if (a[j] == r) {
                r++;
                t2++;
            }
        }
        std::cout << (n - std::min(t1, t2) * 2) / 2 << "\n";
    } else {
        int l = mid, r = mid + 1;
        int t1 = 0, t2 = 0;
        for (int i = k; i >= 1; --i) {
            if (a[i] == l) {
                l--;
                t1++;
            } 
        }
        for (int j = k; j <= n; ++j) {
            if (a[j] == r) {
                r++;
                t2++;
            }
        }
        std::cout << (n - std::min(t1, t2) * 2) / 2 << "\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
