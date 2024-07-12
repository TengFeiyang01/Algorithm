#include <bits/stdc++.h>

const int N = 1e6 + 5;
int spf[N];

void solve() {
	int n, m;
    std::cin >> n >> m;
    if (n == 1 or spf[n] > m) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::iota(spf, spf + N, 0);
    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                spf[j] = std::min(spf[j], i);
            }
        }
    }
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
