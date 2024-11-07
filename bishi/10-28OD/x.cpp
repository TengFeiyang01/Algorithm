#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        std::cout << -1 << "\n";
        return 0;
    }

    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, inf));

    queue<pair<int, int>> q;

    for (int i = 0; i < N; ++i) {
        dp[1 << i][i] = 0;
        q.push({1 << i, i});
    }

    while (!q.empty()) {
        auto [mask, u] = q.front();
        q.pop();

        for (int v = 0; v < N; ++v) {
            if (arr[u][v] == 1) {  
                int next_mask = mask | (1 << v);
                if (dp[next_mask][v] > dp[mask][u] + 1) {
                    dp[next_mask][v] = dp[mask][u] + 1;
                    q.push({next_mask, v});
                }
            }
        }
    }

    int answer = inf;
    for (int i = 0; i < N; ++i) {
        answer = min(answer, dp[(1 << N) - 1][i]);
    }

    if (answer == inf) {
        cout << -1 << endl;  // 如果没有解，输出 -1
    } else {
        cout << answer << endl;
    }

    return 0;
}