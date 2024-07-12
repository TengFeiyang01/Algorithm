#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    auto solve = [&](auto solve, int l, int r, int k) {
        if (k == 0) return 0;
        int m = std::partition_point(a.begin() + l, a.begin() + r, [&](int x) { return ~x >> (k - 1) & 1; }) - a.begin();
        if (l == m || m == r) return solve(solve, l, r, k - 1);
        return std::min(solve(solve, l, m, k - 1), solve(solve, m, r, k - 1)) | 1 << (k - 1);
    };
    
    std::cout << solve(solve, 0, N, 30) << "\n";
    
    return 0;
}
