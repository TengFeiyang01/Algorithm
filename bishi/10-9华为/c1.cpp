#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // For std::copy

using namespace std;

int n, m, c;
vector<int> w(205), b(205), a(205);
int ans = 0;

void dfs(int x) {
    if (x == m + 1) {
        set<double> se;
        for (int i = 1; i <= n; i++) {
            se.insert(min(a[i], w[i]) / (double)w[i]);
        }
        if (se.size() == 1) {
            ans++;
        }
        return;
    }

    if (x + c - 1 <= m) {
        // 策略1
        vector<int> tempA1 = a; // 克隆当前状态
        for (int i = x; i < x + c; i++) {
            int idx = (i - x) % n + 1;
            tempA1[idx - 1] += 4;
        }
        dfs(x + c);

        // 策略2
        vector<int> tempA2 = a; // 克隆当前状态
        for (int i = 0; i < c; i++) {
            int mx = 0, id = 0;
            for (int j = 0; j < n; j++) {
                if (w[j + 1] - tempA2[j] > mx) {
                    mx = w[j + 1] - tempA2[j];
                    id = j;
                }
            }
            tempA2[id] += 4;
        }
        dfs(x + c);

        // 策略3
        vector<int> tempA3 = a; // 克隆当前状态
        int now = 0, sum_val = 0;
        for (int i = x; i < x + c; i++) {
            sum_val += 1;
            int idx = (now + 1) % n;
            tempA3[idx] += 4;
            if (sum_val >= b[idx + 1]) {
                now += 1;
                sum_val = 0;
            }
        }
        dfs(x + c);
    } else {
        // 当 x 到 m 的距离小于 c 时
        // 策略1
        vector<int> tempA1 = a; // 克隆当前状态
        for (int i = x; i <= m; i++) {
            int idx = (i - x) % n + 1;
            tempA1[idx - 1] += 4;
        }
        dfs(m + 1); // 直接到达 m + 1

        // 策略2
        vector<int> tempA2 = a; // 克隆当前状态
        for (int i = 0; i < m - x + 1; i++) {
            int mx = 0, id = 0;
            for (int j = 0; j < n; j++) {
                if (w[j + 1] - tempA2[j] > mx) {
                    mx = w[j + 1] - tempA2[j];
                    id = j;
                }
            }
            tempA2[id] += 4;
        }
        dfs(m + 1); // 直接到达 m + 1
    }
}

int main() {
    // 输入部分
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i]; // 读取 w 数组
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i]; // 读取 b 数组
    }
    cin >> m >> c;
    m /= 4;
    // 初始化 a 数组
    fill(a.begin(), a.end(), 0); 

    // 调用 DFS
    dfs(1);

    // 输出答案
    cout << ans << endl;

    return 0;
}
