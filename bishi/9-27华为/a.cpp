#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<typename T>
std::vector<T> input() {
    std::vector<T> a;
    T s;
    while(std::cin >> s) {
        a.push_back(s);
        if(std::cin.get() != ' ') break;
    }
    return a;
}

bool bfs(int start, std::vector<std::vector<int>> &adj, std::vector<int> color, std::vector<std::vector<int>> groups)  {
    std::queue<int> q;
    q.push(start);
    color[start] = 0;
    groups[0].push_back(start);

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                groups[color[v]].push_back(v);
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }    
    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> st(n, -1);
    std::vector<std::vector<int>> adj;
    for (int i = 0; i < n; ++i) {
        auto t = input<int>();
        adj.push_back(t);
    }

    std::vector<std::vector<std::vector<int>>> res;
    for (int i = 0; i < n; ++i) {
        if (st[i] == -1) {
            std::vector<std::vector<int>> a(2);
            if (!bfs(i, adj, st, a)) {
                std::cout << "-1\n";
                return;
            }
            res.push_back(a);
        }
    }
    std::set<int> ans1, ans2;
    for (auto g : res) {
        for (auto x : g[0]) {
            ans1.insert(x);
        }

        for (auto x : g[1]) {
            ans2.insert(x);
        }
    }
    for (auto x : ans1) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    for (auto x : ans2) {
        std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
