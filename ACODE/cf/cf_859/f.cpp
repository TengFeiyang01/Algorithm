#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

std::unordered_map<std::string, std::pair<int, int>> dir_map = {
    {"DR", {1, 1}},
    {"DL", {1, -1}},
    {"UR", {-1, 1}},
    {"UL", {-1, -1}}
};

struct node{
    int x, y;
    std::string d;
};

void solve() {
    int n, m;
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 + y1) % 2 != (x2 + y2)) {
    	std::cout << "-1\n";
    	return;
    } 
    std::string op;
    std::cin >> op;

    int tar = x2 + y2;

    auto[dx, dy] = dir_map[op];

    std::queue<node> pq;
    q.push({x1, y1, op});
    while (pq.size()) {
        auto[x, y, dir] = q.front();
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
