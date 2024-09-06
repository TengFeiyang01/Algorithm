#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<pair<int, int>> tasks(N + 1);

        for (int i = 1; i <= N; ++i) {
            cin >> tasks[i].first >> tasks[i].second;
        }

        // Initialize dp array
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INF));

        dp[0][0] = 0; // Initial state with both robots at start position

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                int current_task = max(i, j) + 1;
                if (current_task > N) continue;

                // If robot 1 takes the current task
                if (i < N) {
                    int dist1 = (i == 0 ? 0 : abs(tasks[current_task].first - tasks[i].second));
                    dp[current_task][j] = min(dp[current_task][j], dp[i][j] + dist1 + abs(tasks[current_task].second - tasks[current_task].first));
                }

                // If robot 2 takes the current task
                if (j < N) {
                    int dist2 = (j == 0 ? 0 : abs(tasks[current_task].first - tasks[j].second));
                    dp[i][current_task] = min(dp[i][current_task], dp[i][j] + dist2 + abs(tasks[current_task].second - tasks[current_task].first));
                }
            }
        }

        // Find the minimum distance by considering all possibilities
        int result = INF;
        for (int i = 0; i <= N; ++i) {
            result = min(result, dp[i][N]);
            result = min(result, dp[N][i]);
        }

        cout << result << endl;
    }
    return 0;
}
