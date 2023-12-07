#include <bits/stdc++.h>

using namespace std;

const int base = 31;
const int maxn = 1000105;
typedef unsigned long long ull;


char a[maxn];
int q, n;
ull p[maxn];
ull sum[2][maxn];

inline int lowbit(int x) {
    return x & -x;
}

void add(int p, ull val, bool flag) {
    for (int i = p; i <= n; i += lowbit(i)) {
        sum[flag][i] += val;
    }
}

ull getSum(int p, bool flag) {
    ull ans = 0;
    for (int i = p; i > 0; i -= lowbit(i)) {
        ans += sum[flag][i];
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    scanf("%s", a + 1);
    n = strlen(a + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * base;
    }
    for (int i = 1; i <= n; ++i) {
        add(i, a[i] * p[i - 1], 0);
    }
    for (int i = 1; i <= n; ++i) {
        add(i, a[n - i + 1] * p[i - 1], 1);
    }
    int x, y, op;
    char c;
    ull s1, s2;
    while (q--) {
        scanf("%d", &op);
        if (op == 2) {
            scanf("%d %d", &x, &y);
            s1 = getSum(y, 0) - getSum(x - 1, 0);
            s2 = getSum(n - x + 1, 1) - getSum(n - y, 1);
            if (y < n - x + 1)
                s1 *= p[n - x + 1 - y];
            else
                s2 *= p[y - (n - x + 1)];
            if (s1 == s2)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else {
            scanf("%d %c", &x, &c);
            add(x, (c - a[x]) * p[x - 1], 0);
            add(n - x + 1, (c - a[x]) * p[n - x], 1);
            a[x] = c;
        }
    }
}
