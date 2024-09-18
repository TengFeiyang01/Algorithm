template <class S,S(*op)(S, S),S(*e)()>
class segtree {
private:
    std::vector<S>node;//保存节点
    std::vector<S>d;//初始化
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
    S que(int rt, int L, int R, int que_L, int que_R) {
        if (L > que_R || R < que_L)return e();
        if (que_L <= L && R <= que_R)return node[rt];
        int mid = (L + R) / 2;
        return op(
                que(2 * rt, L, mid, que_L, que_R),
                que(2 * rt + 1, mid + 1, R, que_L, que_R)
        );
    }

    void upd(int rt, int L, int R, int id, S x) {
        if (L == R) {
            node[rt] = x;
            return;
        }
        int mid = (L + R) / 2;
        if (id <= mid)upd(2 * rt, L, mid, id, x);
        else upd(2 * rt + 1, mid + 1, R, id, x);
        node[rt] = op(node[2 * rt], node[2 * rt + 1]);
    }

public:
    segtree(int n) {
        _n = n;
        d = std::vector<S>(n + 1, e());
        node = std::vector<S>(4 * n, e());
        build(1, 1, n);
    }

    segtree(S *a, int n) {
        _n = n;
        d = std::vector<S>(n + 1, e());
        node = std::vector<S>(4 * n, e());
        for (int i = 1; i <= n; i++)d[i] = a[i];
        build(1, 1, n);
    }

    S que(int L, int R) {
        return que(1, 1, _n, L, R);
    }

    S que(int id) {
        return que(id, id);
    }

    void upd(int id, S x) {
        upd(1, 1, _n, id, x);
    }
};

using S = long long;
S op(S a, S b) {return a + b;};
S e() {return 0;}
S a[500003];