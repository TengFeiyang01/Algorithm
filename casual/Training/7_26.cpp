#include <bits/stdc++.h>
using namespace std;


int T;
const long long mod = 998244353;
long long sum[200005 << 4][2], lazy[200005 << 4][2];
void push(const int p) {
    sum[p][0] = (sum[p << 1][0] + sum[p << 1 | 1][0]) % mod;
    sum[p][1] = (sum[p << 1][1] + sum[p << 1 | 1][1]) % mod;
}
void down(const int p, const int L, const int R) {
    const int x = p << 1, y = p << 1 | 1, mid = L + R >> 1;
    for (auto i : {0, 1}) {
        if (lazy[p][i] != 0) {
            sum[x][i] = (sum[x][i] + lazy[p][i] * (mid - L + 1) % mod) % mod;
            sum[y][i] = (sum[y][i] + lazy[p][i] * (R - mid) % mod) % mod;
            lazy[x][i] = (lazy[x][i] + lazy[p][i]) % mod;
            lazy[y][i] = (lazy[y][i] + lazy[p][i]) % mod;
            lazy[p][i] = 0;
        }
    }
}
void modify(const int p, const int QL, const int QR, const int L, const int R, const int w) {
    if (R < QL || L > QR) {
        return;
    }
    if (QL <= L && R <= QR) {
        sum[p][0] = (sum[p][0] + 1LL * w * (T - 1) % mod * (R - L + 1)) % mod;
        lazy[p][0] = (lazy[p][0] + 1LL * w * (T - 1) % mod) % mod;
        sum[p][1] = (sum[p][1] + 1LL * w * (R - L + 1) % mod) % mod;
        lazy[p][1] = (lazy[p][1] + w) % mod;
        return;
    }
    down(p, L, R);
    const int mid = L + R >> 1;
    modify(p << 1, QL, QR, L, mid, w);
    modify(p << 1 | 1, QL, QR, mid + 1, R, w);
    push(p);
}
pair<long long, long long> query(const int p, const int QL, const int QR, const int L, const int R) {
    if (R < QL || L > QR) {
        return {0LL, 0LL};
    }
    if (QL <= L && R <= QR) {
        return {sum[p][0], sum[p][1]};
    }
    down(p, L, R);
    const int mid = L + R >> 1;
    const auto [x1, y1] = query(p << 1, QL, QR, L, mid);
    const auto [x2, y2] = query(p << 1 | 1, QL, QR, mid + 1, R);
    return {(x1 + x2) % mod, (y1 + y2) % mod};
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (T = 1 ; T <= q ; T++) {
        int op, L, R;
        cin >> op >> L >> R;
        if (op == 0) {
            int w;
            cin >> w;
            modify(1, L, R, 1, n, w);
        } else {
            auto [x, y] = query(1, L, R, 1, n);
            y = y * T % mod;
            long long ans = (y - x + mod) % mod;
            cout << ans << "\n";
        }
    }
    return 0;
}