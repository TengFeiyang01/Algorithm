#include <bits/stdc++.h>
using namespace std;

// 2023 OneWan

const int N = 100000 + 5;
// const int M = 1 << __lg(N + 5) + 1;
const int M = N << 4;
const long long mod = 998244353;

struct Node {
    int L, R;
    long long sum[3];
    Node() {
        for (int i = 0 ; i < 3 ; i++) {
            sum[i] = 0;
        }
    }
    friend Node operator+ (const Node &lhs, const Node &rhs) {
        Node res;
        res.L = lhs.L;
        res.R = rhs.R;
        for (int i = 0 ; i < 3 ; i++) {
            res.sum[i] = (lhs.sum[i] + rhs.sum[i]) % mod;
        }
        return res;
    }
    
} tr[M];
struct Tag {
    int to[3];
    long long mul[3];
    Tag() {
        for (int i = 0 ; i < 3 ; i++) {
            to[i] = i;
            mul[i] = 1;
        }
    }
} lazy[M];

int a[N];

void pushtag(int p, Tag tag) {
    {
        Node res;
        res.L = tr[p].L;
        res.R = tr[p].R;
        for (int i = 0 ; i < 3 ; i++) {
            res.sum[tag.to[i]] = (res.sum[tag.to[i]] + tag.mul[i] * tr[p].sum[i] % mod) % mod;
        }
        tr[p] = res;
    }
    {
        Tag res;
        for (int i = 0 ; i < 3 ; i++) {
            res.to[i] = tag.to[lazy[p].to[i]];
            res.mul[i] = lazy[p].mul[i] * tag.mul[lazy[p].to[i]] % mod;    
        }
        lazy[p] = res;
    }
}
// 
void pushdown(int p) {
    pushtag(p << 1, lazy[p]);
    pushtag(p << 1 | 1, lazy[p]);
    lazy[p] = Tag();
}
int n;
void build(int p = 1, int L = 1, int R = n) {
    tr[p].L = L;
    tr[p].R = R;
    if (L == R) {
        tr[p].sum[a[L]] = 1;
        return;
    }
    int mid = L + R >> 1;
    build(p << 1, L, mid);
    build(p << 1 | 1, mid + 1, R);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}

void modify(int p, int QL, int QR, Tag tag) {
    // cerr << tr[p].L << " " << tr[p].R << "\n";
    if (QL <= tr[p].L && tr[p].R <= QR) {
        pushtag(p, tag);
        // cout << tr[p].sum[0] << " " << tr[p].sum[1] << " " << tr[p].sum[2] << "\n";
        return;
    }
    pushdown(p);
    int mid = tr[p].L + tr[p].R >> 1;
    if (QL <= mid) modify(p << 1, QL, QR, tag);
    if (QR >= mid + 1) modify(p << 1 | 1, QL, QR, tag);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        a[i]--;
    }
    build();
    for (int i = 1 ; i <= m ; i++) {
        int L, R, op;
        cin >> L >> R >> op;
        Tag tag;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            tag.to[x] = y;
            tag.to[y] = x;
        }
        if (op == 2) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            tag.to[x] = y;
        }
        if (op == 3) {
            int x;
            cin >> x;
            x--;
            tag.mul[x] = 2;
        }
        // cout << tag.to[0] << " " << tag.to[1] << " " << tag.to[2] << "\n";
        modify(1, L, R, tag);
        cout << tr[1].sum[0] << " " << tr[1].sum[1] << " " << tr[1].sum[2] << "\n";
        // break;
    }
    return 0;
}