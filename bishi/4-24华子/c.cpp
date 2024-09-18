#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Pair {
    int node, weight;
    Pair(int n, int w) : node(n), weight(w) {}
};

class SCC {
public:
    vector<vector<Pair>> g;
    int n, cnt = 0, timestamp = 0;
    vector<bool> inStk;
    vector<int> dfn, low, id, sz, dout, din;
    stack<int> stk;

    SCC(const vector<vector<Pair>>& graph, int nodes) : g(graph), n(nodes),
        inStk(nodes, false), dfn(nodes, 0), low(nodes, 0), id(nodes, 0),
        sz(nodes, 0), dout(nodes, 0), din(nodes, 0) {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == 0) {
                tarjan(i);
            }
        }
        getD();
    }

    void tarjan(int u) {
        dfn[u] = low[u] = ++timestamp;
        stk.push(u);
        inStk[u] = true;
        for (auto& p : g[u]) {
            int v = p.node;
            if (dfn[v] == 0) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            } else if (inStk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            cnt++;
            while (true) {
                int y = stk.top(); stk.pop();
                inStk[y] = false;
                id[y] = cnt;
                sz[cnt]++;
                if (y == u) break;
            }
        }
    }

    void getD() {
        for (int u = 0; u < n; ++u) {
            for (auto& p : g[u]) {
                int v = p.node;
                if (id[u] != id[v]) {
                    dout[id[u]]++;
                    din[id[v]]++;
                }
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<Pair>> g(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        g[i].emplace_back(x, 1);
    }

    SCC scc(g, n);
    queue<int> q;
    unordered_map<int, int> f;
    vector<vector<int>> ng(scc.cnt + 1);
    unordered_map<int, int> din;
    for (int i = 0; i <= scc.cnt; ++i) {
        ng[i].reserve(n);
    }
    for (int i = 0; i < n; ++i) {
        int x = g[i][0].node;
        if (scc.id[i] != scc.id[x]) {
            ng[scc.id[i]].push_back(scc.id[x]);
            din[scc.id[x]]++;
        }
    }
    for (int i = 1; i <= scc.cnt; ++i) {
        if (din[i] == 0) {
            q.push(i);
        }
    }

    vector<pair<int, int>> alls;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        alls.emplace_back(u, f[u] - scc.sz[u]);
        f[u] += scc.sz[u];
        for (int v : ng[u]) {
            f[v] += f[u];
            if (--din[v] == 0) {
                q.push(v);
            }
        }
    }
    sort(alls.begin(), alls.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int x = alls.front().first;
    unordered_set<int> vis;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (scc.id[i] == x) {
            res.push_back(i);
            vis.insert(i);
        }
    }
    sort(res.begin(), res.end());
    queue<int> outputQueue;
    outputQueue.push(res[0]);
    vector<int> ans;
    unordered_set<int> have;
    while (!outputQueue.empty()) {
        int current = outputQueue.front(); outputQueue.pop();
        have.insert(current);
        ans.push_back(current);
        for (auto& p : g[current]) {
            int y = p.node;
            if (vis.count(y) && !have.count(y)) {
                outputQueue.push(y);
            }
        }
    }

    for (int number : ans) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}

