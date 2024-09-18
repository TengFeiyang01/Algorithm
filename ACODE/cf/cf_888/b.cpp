#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b, c;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] % 2) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());
    int ok = 1, p = -1;
    int j = 0, k = 0;
    if (a[0] % 2) {
        p = b[0];
        j++;
    } else {
        p = c[0];
        k++;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i] % 2) {
            if (b[j] < p) {
                ok = 0;
                break;
            }
            p = b[j];
            j++;
        } else {
            if (c[k] < p) {
                ok = 0;
                break;
            }
            p = c[k];
            k++;
        }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
