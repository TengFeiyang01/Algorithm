#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int h, w, a, b, c, d;
    cin >> h >> w >> a >> b >> c >> d;

    int inf = INT_MAX / 10;
    vector<vector<int>> g(h, vector<int>(w));
    vector<vector<int>> dp(h, vector<int>(w, 0));
    vector<vector<int>> days(h, vector<int>(w, inf));

    deque<vector<int>> pq;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                dp[i][j] = b;
                pq.push_back({i, j, b, 0});
            } else if (g[i][j] == 3) {
                dp[i][j] = a;
                pq.push_back({i, j, a, 0});
            }
        }
    }

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        vector<int> cur = pq.front();
        pq.pop_front();

        int y = cur[0], x = cur[1], val = cur[2], day = cur[3];
        if (val < dp[y][x]) continue;

        for (auto& dir : dirs) {
            int ty = y + dir[0], tx = x + dir[1];
            if (ty >= 0 && ty < h && tx >= 0 && tx < w) {
                if (g[ty][tx] == 1) continue;
                if (dp[ty][tx] < val - 1) {
                    dp[ty][tx] = val - 1;
                    if (g[ty][tx] == 4 && dp[ty][tx] >= d) {
                        dp[ty][tx] = b;
                        days[ty][tx] = min(days[ty][tx], day + 1);
                        pq.push_back({ty, tx, b, day + 1});
                    } else if (g[ty][tx] == 5 && dp[ty][tx] >= c) {
                        dp[ty][tx] = a;
                        days[ty][tx] = min(days[ty][tx], day + 1);
                        pq.push_back({ty, tx, a, day + 1});
                    } else {
                        pq.push_back({ty, tx, dp[ty][tx], day});
                    }
                }
            }
        }
    }

    vector<vector<int>> res(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g[i][j] == 2 || g[i][j] == 3) {
                res[i][j] = 0;
            } else if (g[i][j] <= 1) {
                res[i][j] = -1;
            } else {
                if (days[i][j] == inf) {
                    res[i][j] = -1;
                } else {
                    res[i][j] = days[i][j];
                }
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j != 0) cout << " ";
            cout << res[i][j];
        }
        cout << endl;
    }

    return 0;
}
