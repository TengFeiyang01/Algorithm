#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int dx[] = {-1, 1, -4, 4};

struct Step {
    int x1, y1, x2, y2;
};

std::string init, goal;
std::queue<std::string> q;
std::map<std::string, int> dist;
std::map<std::string, std::string> pre;
std::map<std::string, Step> op;

std::string read() {
    std::string res, tmp;
    for (int i = 0; i < 4; ++i) {
        std::cin >> tmp;
        res += tmp;
    }
    return res;
}

void print(const std::string& x) {
    if (!pre.count(x)) return;
    print(pre[x]);
    auto step = op[x];
    std::cout << step.x1 << step.y1 << step.x2 << step.y2 << '\n';
}

void solve() {
    init = read();
    goal = read();
    
    q.push(init);
    dist[init] = 0;
    
    while (!q.empty()) {
        std::string u = q.front();
        q.pop();
        
        if (u == goal) {
            std::cout << dist[u] << '\n';
            print(u);
            return;
        }
        
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 4; ++j) {
                if ((i == 4 || i == 8 || i == 12) && j == 0) continue;
                if ((i == 3 || i == 7 || i == 11) && j == 1) continue;
                
                int tx = i + dx[j];
                if (tx < 0 || tx > 15) continue;
                
                std::string v = u;
                std::swap(v[i], v[tx]);
                
                if (!dist.count(v)) {
                    dist[v] = dist[u] + 1;
                    pre[v] = u;
                    op[v] = {i / 4 + 1, i % 4 + 1, tx / 4 + 1, tx % 4 + 1};
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
