#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e6;

void solve() {
    std::vector f(N, 0);
    int n;
    std::cin >> n;
    i64 ans = 0;
    std::vector<int> a(n);
    for (auto &x : a) {
        std::cin >> x;
        f[x]++;
        if (!std::ranges::count(
                std::views::all(std::to_string(x)) |
                std::views::transform([](char c) { return (c - '0') <= 4; }),
                false))
            ans--;
    }
    for (int p = 1; p < N; p *= 10) {
        for (int i = 0; i < N; ++i) {
            if (i / p % 10 > 0) {
                f[i] += f[i - p];
            }
        }
    }
    std::ranges::for_each(a, [&](int x) { ans += f[999999 - x]; });
    std::cout << ans / 2 << "\n";
}

int main() {
    std::istream::sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}