#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
struct Edge {
    int to, next;
} edges[MAXN * 2];
int head[MAXN], edgeCnt;

void addEdge(int u, int v) {
    edges[edgeCnt] = {v, head[u]};
    head[u] = edgeCnt++;
}

void solve() {
    int n, x;
    cin >> n >> x;
    memset(head, -1, sizeof(head));
    edgeCnt = 0;
    vector<int> degree(n + 1, 0);

    // 读取图中的 n 条边并构建链式前向星
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> q;
    vector<bool> visited(n + 1, false);

    // 将所有度数为1的节点加入队列
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
            visited[i] = true;
        }
    }
    if (visited[x]) {
        cout << "Xiaoyo\n";
        return;
    }

    // 移除所有叶子节点
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (!visited[v]) {
                degree[v]--;
                if (degree[v] == 1) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    // 环上的节点
    vector<int> cycleNodes;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cycleNodes.push_back(i);
        }
    }

    set<int> st;
    for (int t : cycleNodes) {
        st.insert(t);
    }
    if (st.count(x)) {
        cout << "Draw\n";
        return;
    }
    int p = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) -> void {
        for (int i = head[u]; ~i; i = edges[i].next) {
            int v = edges[i].to;
            if (v != fa) {
                if (st.count(v)) {
                    p = d;
                    return;
                }
                dfs(v, u, d + 1);
            }
        }
    };
    dfs(x, 0, 0);

    // 不在环上的点的个数
    int other = n - st.size() - p;

    if (other % 2) {
        cout << "Xiaoyo\n";
    } else {
        cout << "Pyrmont\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
