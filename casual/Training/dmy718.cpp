#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e6 + 13;

unsigned int A, B, C, a[N], b[N][22], ans;
int n, q;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}

int main(){
    scanf("%d%d%u%u%u", &n, &q, &A, &B, &C);
    for (int i = 1; i <= n; i++) {
        a[i] = rng61();
        b[i][0] = a[i];
    }

    for (int j = 1; j <= std::__lg(n); ++j) {
        int r = n - (1 << j) + 1;
    	for (int i = 1; i <= r; ++i) {
    		b[i][j] = std::max(b[i][j - 1], b[i + (1 << j - 1)][j - 1]);
    	}
    }

    for (int i = 1; i <= q; i++) {
        unsigned int l = rng61() % n + 1, r = rng61() % n + 1;
        if (l > r) std::swap(l, r);
        int k = std::__lg(r - l + 1);
        ans ^= std::max(b[l][k], b[r - (1 << k) + 1][k]);
    }
    printf("%u\n", ans);
}
