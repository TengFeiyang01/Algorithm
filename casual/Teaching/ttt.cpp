#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int N = 61;

i64 c[N][N];
void init() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
}

void solve() {
    int n, m, k;
    std::cin >> k >> n >> m;
    if (k < m + n) {
    	std::cout << 0;
    	return;
    } 
    std::cout << c[n + m][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
