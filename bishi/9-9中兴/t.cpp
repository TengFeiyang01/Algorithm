#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int mx = 0;

unordered_map<string, int> cache_dfs;
unordered_map<string, int> cache_get;

int dfs(int x, int y, int cur) {
    mx = max(mx, cur);
    if (max(x, y) < cur) {
        return 1;
    }
    string key = to_string(x) + "," + to_string(y) + "," + to_string(cur);
    if (cache_dfs.find(key) != cache_dfs.end()) {
        return cache_dfs[key];
    }
    int ans = 0;
    if (x >= cur) {
        ans += dfs(x - cur, y, cur + 1);
    }
    if (y >= cur) {
        ans += dfs(x, y - cur, cur + 1);
    }
    cache_dfs[key] = ans;
    return ans;
}

int get(int x, int y, int cur) {
    if (max(x, y) < cur) {
        return cur == mx;
    }
    string key = to_string(x) + "," + to_string(y) + "," + to_string(cur);
    if (cache_get.find(key) != cache_get.end()) {
        return cache_get[key];
    }
    int ans = 0;
    if (x >= cur) {
        ans += get(x - cur, y, cur + 1);
    }
    if (y >= cur) {
        ans += get(x, y - cur, cur + 1);
    }
    cache_get[key] = ans;
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = dfs(n, m, 1);
    cout << get(n, m, 1) << endl;
}

int main() {
    solve();
    return 0;
}
