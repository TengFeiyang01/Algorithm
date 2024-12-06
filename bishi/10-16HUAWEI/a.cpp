#include <bits/stdc++.h>

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    std::vector<std::array<int, 2>> b(q);
    for (int i = 0; i < q; i++) {
        std::cin >> b[i][0] >> b[i][1];
    }
    std::vector<std::vector<int>> st(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        st[a[i]][i] = 1;
    }
    for (int i = 0; i < q; i++) {
        int l = b[i][0] - 1, r = b[i][1] - 1;
        std::vector<int> na(n);
        int p = 0;
        for (int j = 0; j < l; j++) {
            na[p++] = a[j];
        }
        for (int j = r + 1; j < n; j++) {
            na[p++] = a[j];
        }
        for (int j = l; j <= r; j++) {
            na[p++] = a[j];
        }
        a.swap(na);
        for (int j = 0; j < n; ++j) {
            st[a[j]][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += st[i][j];
        }
        std::cout << s << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}