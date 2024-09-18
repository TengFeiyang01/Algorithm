#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e6 + 13;
int a[N]{0};


void solve() {
    int n;
    std::cin >> n;
    bool ok = false;

    if (a[n]) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int k = 2;
    while (k < N) {
        i64 now = 1, cur = k;
        now += cur;
        cur *= k;
        while (now + cur < N) {
            now += cur;
            a[now] = 1;
            cur *= k;
        }
        k++;
    }

    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
