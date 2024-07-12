#include <bits/stdc++.h>

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    int n;
    std::cin >> n;
    std::vector<int> a(n), ans(n);
    for (int &ai: a) { std::cin >> ai; }
    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i += 1) { p.emplace_back(a[i], i); }
    std::sort(p.begin(), p.end());
    for (int i = 0; i < n; i += 1) {
        if (n % 2) {
            int j = n / 2 - 1, k = n / 2;
            if (j >= i) { j += 1; }
            if (k >= i) { k += 1; }
            ans[p[i].second] = p[j].first + p[k].first;
        } else {
            int j = n / 2 - 1;
            if (j >= i) { j += 1; }
            ans[p[i].second] = p[j].first * 2;
        }
    }
    for (int x: ans) { std::cout << x / 2 << "." << (x % 2 * 5) << "\n"; }
}