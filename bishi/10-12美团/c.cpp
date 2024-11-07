#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 205;
const int INF = 1e9;

int n, m;
int a[MAXN], b[MAXN];
bool isPrime[1000005];  // 质数判断数组
int weight[MAXN][MAXN];  // 权值矩阵
int u[MAXN], v[MAXN], p[MAXN], way[MAXN];  // KM算法辅助数组

// 埃拉托色尼筛法预处理质数
void sieve() {
    fill(isPrime, isPrime + 1000005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {
    sieve();  // 预处理质数

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }

    // 构建权值矩阵
    for (int i = 1; i <= n; ++i) {
        bool primeA = isPrime[a[i]];
        for (int j = 1; j <= m; ++j) {
            bool primeB = isPrime[b[j]];
            int w = 0;
            if (primeA && primeB) {
                w = 2 * (a[i] + b[j]);
            } else if (primeA || primeB) {
                w = 2 * max(a[i], b[j]);
            } else {
                w = a[i] + b[j];
            }
            weight[i][j] = w;
        }
    }

    // Kuhn-Munkres (KM) 算法
    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));
    memset(p, 0, sizeof(p));
    memset(way, 0, sizeof(way));

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        vector<int> minv(m + 1, INF);
        vector<bool> used(m + 1, false);
        int j0 = 0;

        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1 = -1;

            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = weight[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    int ans = 0;
    vector<int> match(n + 1, -1);

    for (int j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            match[p[j]] = j;
        }
    }

    // 计算总战力提升
    for (int i = 1; i <= n; ++i) {
        if (match[i] != -1) {
            int x = a[i], y = b[match[i]];
            if (isPrime[x] && isPrime[y]) {
                ans += 2 * (x + y);
            } else if (isPrime[x] || isPrime[y]) {
                ans += 2 * max(x, y);
            } else {
                ans += x + y;
            }
        }
    }

    cout << ans << "\n";

    // 输出匹配结果
    for (int i = 1; i <= n; ++i) {
        if (match[i] != -1) {
            cout << match[i] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;

    return 0;
}
