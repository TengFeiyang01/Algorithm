#include <bits/stdc++.h>

using i64 = long long;

//CF 915E 896C

i64 qpow(i64 x, i64 y, int mod) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

struct node {
    int l, r;
    mutable i64 v;
    explicit node(int left = 0, int right = 0, i64 val = 0) : l(left), r(right), v(val){}
    bool operator<(const node &other) const {
        return l < other.l;
    }
};

std::set<node> s;

auto split(int pos) {
    auto it = s.lower_bound(node(pos));  // 寻找左端点大于等于pos的第一个节点
    if (it != s.end() && it->l == pos) {
        return it;
    }
    it--;  // 否则往前数一个节点
    auto[l, r, v] = *it;
    s.erase(it);  // 删除该节点
    s.insert(node(l, pos - 1, v));  // 插入<l,pos-1,v>和<pos,r,v>
    return s.insert(node(pos, r, v)).first;
    //pair<iterator, bool> insert(const value_type& val>
}

void add(int l, int r, i64 val = 1) {
//    split(l);
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) itl->v += val;
}

void assign(int l, int r, i64 val = 0) {
//    split(l);
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    //iterator erase(const_iterator first, const_iterator last)
    s.insert(node(l, r, val));
}

int rank(int l, int r, int k) {
//    split(l);
    auto itr = split(r + 1), itl = split(l);
    std::vector<std::pair<int, int>> vp;
    for (; itl != itr; ++itl) {
        vp.emplace_back(itl->v, itl->r - itl->l + 1);
    }
    std::sort(vp.begin(), vp.end());
    for (const auto &i : vp) {
        k -= i.second;
        if (k <= 0) {
            return i.first;
        }
    }
    return -1;
}

i64 sum(int l, int r, int ex, int mod) {
//    split(l);
    auto itr = split(r + 1), itl = split(l);
    i64 res = 0;
    for (; itl != itr; ++itl) {
        res = (res + i64(itl->r - itl->l + 1) * qpow(itl->v, ex, mod)) % mod;
    }
    return res;
}

i64 seed;

i64 rnd() {
    auto ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, m, vmax;
    std::cin >> n >> m >> seed >> vmax;

    for (int i = 1; i <= n; ++i) {
        s.insert(node{i, i, rnd() % vmax + 1});
    }

    for (int i = 0; i < m; ++i) {
        int op, l, r, x, y;
        op = rnd() % 4 + 1;
        l = rnd() % n + 1;
        r = rnd() % n + 1;

        if (l > r) std::swap(l, r);

        if (op == 1) {
            x = rnd() % vmax + 1;
            add(l, r, x);
        } else if (op == 2) {
            x = rnd() % vmax + 1;
            assign(l, r, x);
        } else if (op == 3) {
            x = rnd() % (r - l + 1) + 1;
            std::cout << rank(l, r, x) << "\n";
        } else {
            x = rnd() % vmax + 1;
            y = rnd() % vmax + 1;
            std::cout << sum(l, r, x, y) << "\n";
        }
    }

    return 0;
}
