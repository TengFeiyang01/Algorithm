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
using namespace std;

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e6 + 13;
int n, m, a[N];

void solve() {
    ll sum = 0;
    std::cin >> n;
    std::priority_queue<int, vector<int>, greater<int> > q;

    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        sum += k % 2;
        int u = 1;
        for (int t = 2; t < k; ++u) {
            if ((k - k / t) % 2 == 1) break;
            t *= 2;
        }
        q.push(u);
    }

    if (sum % 2) cout << q.top() << "\n";
    else std::cout << 0 << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
