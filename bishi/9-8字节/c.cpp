#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

class Dsu {
public:
    int n;
    vector<int> arr;
    vector<long long> gz;

    Dsu(int n, vector<long long>& val) : n(n), arr(n, -1), gz(val) {}

    int find(int u) {
        if (arr[u] == -1) {
            return u;
        }
        return arr[u] = find(arr[u]);
    }

    void merge(int u, int v) {
        int a = find(u), b = find(v);
        if (a != b) {
            arr[a] = b;
            gz[b] += gz[a];
        }
    }

    long long group(int u) {
        return gz[find(u)];
    }
};

struct Op {
    int cmd;
    vector<int> list;
    int tt;
    int idx;
    int qidx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<Op> ops;
    for (int i = 0; i < m; i++) {
        int tt, c;
        cin >> tt >> c;
        Op op;
        op.tt = tt;
        op.cmd = 0;
        op.list.resize(c);
        for (int j = 0; j < c; j++) {
            cin >> op.list[j];
            op.list[j]--;  // 转换为 0 索引
        }
        ops.push_back(op);
    }

    for (int i = 0; i < q; i++) {
        int tt, idx;
        cin >> tt >> idx;
        Op op;
        op.cmd = 1;
        op.tt = tt;
        op.idx = idx - 1;  // 转换为 0 索引
        op.qidx = i;
        ops.push_back(op);
    }

    sort(ops.begin(), ops.end(), [](const Op& a, const Op& b) {
        if (a.tt != b.tt) return a.tt < b.tt;
        return a.cmd < b.cmd;
    });

    Dsu dsu(n, arr);
    vector<long long> res(q);
    for (const Op& op : ops) {
        if (op.cmd == 0) {
            int fp = op.list[0];
            for (int v : op.list) {
                dsu.merge(fp, v);
            }
        } else {
            res[op.qidx] = dsu.group(op.idx);
        }
    }

    for (const auto& r : res) {
        cout << r << "\n";
    }

    return 0;
}
