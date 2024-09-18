#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

const int MAXN = 100000; // 根据问题的规模调整

vector<pair<int, long long>> graph[MAXN];
long long res[MAXN];
bool vis[MAXN];

void bfs(int start) {
    deque<int> deq;
    deq.push_back(start);
    vis[start] = true;
    res[start] = 0;

    while (!deq.empty()) {
        int cur = deq.front();
        deq.pop_front();
        for (auto &e : graph[cur]) {
            int v = e.first;
            long long w = e.second;
            if (!vis[v]) {
                vis[v] = true;
                res[v] = res[cur] ^ w;
                deq.push_back(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // 清空图
    for (int i = 0; i < n; ++i) {
        graph[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u; --v; // 转换为0-based索引
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    // BFS 初始化
    fill(begin(vis), end(vis), false);
    bfs(0);

    // 统计每个异或值的出现次数
    unordered_map<long long, int> count;
    for (int i = 0; i < n; ++i) {
        count[res[i]]++;
    }

    // 处理查询
    while (q-- > 0) {
        int u;
        long long k;
        cin >> u >> k;
        --u; // 转换为0-based索引
        long long x = res[u];
        cout << count[x ^ k] << "\n";
    }

    return 0;
}
