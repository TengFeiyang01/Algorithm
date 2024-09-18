template <
        class S,S(*op)(S, S),S(*e)(),
        class F,S(*mapping)(F, S),F(*composition)(F, F),F(*id)()>
class lazyseg {
private:
    std::vector<S>node;
    std::vector<S>d;
    std::vector<F>lz;
    int _n;

    void build(int rt, int L, int R) {
        if (L == R) {
            node[rt] = d[L];
            return;
        }
        int mid = (L + R) / 2;
        build(2 * rt, L, mid);
        build(2 * rt + 1, mid + 1, R);
        node[rt] = op(node[2 * rt], node[2 * rt + 1]);
    }
public:
    lazyseg(int n) {
        _n = n;
        d = std::vector<S>(n + 1, e());
        node = std::vector<S>(4 * n, e());
        lz = std::vector<F>(4 * n, id());
        build(1, 1, n);
    }

    lazyseg(S *a, int n) {
        _n = n;
        d = std::vector<S>(n + 1, e());
        node = std::vector<S>(4 * n, e());
        lz = std::vector<F>(4 * n, id());
        for (int i = 1; i <= n; i++)d[i] = a[i];
        build(1, 1, n);
    }

    void push(int rt, F x) {
        node[rt] = mapping(x, node[rt]);
        lz[rt] = composition(x, lz[rt]);
    }

    void push_down(int rt) {
        push(2 * rt, lz[rt]);
        push(2 * rt + 1, lz[rt]);
        lz[rt] = id();
    }

    S que(int rt, int L, int R, int que_L, int que_R) {
        if (L > que_R || R < que_L)return e();
        if (que_L <= L && R <= que_R)return node[rt];
        int mid = (L + R) / 2;
        push_down(rt);
        return op(
                que(2 * rt, L, mid, que_L, que_R),
                que(2 * rt + 1, mid + 1, R, que_L, que_R)
        );
    }

    S que(int L, int R) {
        return que(1, 1, _n, L, R);
    }

    void upd(int rt, int L, int R, int que_L, int que_R, F x) {
        if (L > que_R || R < que_L)return;
        if (que_L <= L && R <= que_R) {
            push(rt, x);
            return;
        }
        int mid = (L + R) / 2;
        push_down(rt);
        upd(2 * rt, L, mid, que_L, que_R, x);
        upd(2 * rt + 1, mid + 1, R, que_L, que_R, x);
        node[rt] = op(node[2 * rt], node[2 * rt + 1]);
    }
    void upd(int L, int R, F x) {
        upd(1, 1, _n, L, R, x);
    }
};

using ll = long long;
int mod;
struct S {ll sum; ll size;};
struct F {ll mul, add;};
S op(S l, S r) { return S{ (l.sum + r.sum) % mod, l.size + r.size };}
S e() { return S {0, 0}; }
S mapping(F f, S x) { return S{ ((x.sum * f.mul) % mod + x.size * f.add%mod) % mod, x.size }; }
F composition(F f, F g) { return F{ (f.mul * g.mul) % mod  , ((f.mul * g.add) % mod + f.add) % mod }; }
F id() { return F{ 1, 0 }; }
S a[500005];