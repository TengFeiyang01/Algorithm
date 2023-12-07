#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

unsigned int A, B, C;
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
constexpr int N = 1e7 + 13;
int p, n, ans = 0, a[N];
i64  s[N], t[N];

i64 exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	i64 d = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

int main() {
    scanf("%d%d%u%u%u", &p, &n, &A, &B, &C);
    for (int i = 1; i <= n; i++) {
        a[i] = rng61()%p;
    	if (a[i] == 0) {
    		a[i] = 1;
    		ans ^= 1;
    	}
    }
    s[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	s[i] = s[i - 1] * a[i] % p;
    }
    int x, y;
    exgcd(s[n], p, x, y);
    if (x < 0) x += p;
    t[n] = x;
    for (int i = n; i >= 1; --i) {
    	t[i - 1] = t[i] * a[i] % p;
    }
    for (int i = 1; i <= n; ++i) {
    	ans ^= s[i - 1] * t[i] % p;
    }
    printf("%d\n", ans);
}