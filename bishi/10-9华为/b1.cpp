#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

const int MAX_N = 21000; // 最大节点数
long long arr[MAX_N];     // 节点权值
int deg[MAX_N];           // 入度数组
vector<int> g[MAX_N];     // 使用 vector 表示邻接表
int n;

int main() {
    cin >> n;

    // 输入每个节点的权值
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 初始化图的邻接表和入度数组
    for (int i = 0; i < n; i++) {
        deg[i] = 0; // 初始化入度为0
    }

    // 清空输入缓冲区
    cin.ignore();

    // 输入邻接边
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int v;

        while (ss >> v) {
            if (v == -1) break; // 结束条件
            g[v - 1].push_back(i); // 有向边从 v-1 指向 i
            deg[i]++; // 增加入度
        }
    }

    long long dp[MAX_N] = {0}; // 动态规划数组

    // 优先队列，存储 {路径和, 节点}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pp;

    // 将所有入度为0的节点入队
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            pp.push({arr[i], i});
            dp[i] = arr[i]; // 初始化动态规划值
        }
    }

    while (!pp.empty()) {
        auto cur = pp.top();
        pp.pop();
        int u = cur.second;

        for (int v : g[u]) {
            if (--deg[v] == 0) {
                dp[v] = dp[u] + arr[v];
                pp.push({dp[v], v});
            }
        }
    }

    cout << *max_element(dp, dp + n) << endl; // 输出最大权值和

    return 0;
}
