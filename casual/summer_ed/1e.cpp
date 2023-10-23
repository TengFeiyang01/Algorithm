#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int cnt = 1;

void solve() {
    int L, N;
    std::cin >> L >> N;
    i64 ans = 0;
    i64 cur = 0;
    while (N--) {
        int d; char c;
        std::cin >> d >> c;
        if (c == 'A') d = -d;
        cur += d;
        ans += abs(cur) / L;
        cur %= L;
    }    

    std::cout << "Case #" << cnt++ << ": " << ans << "\n";
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