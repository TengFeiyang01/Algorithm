#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int n, int W, vector<int>& v, vector<int>& w, vector<int>& m) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        int vi = v[i], wi = w[i], mi = m[i];
        for (int k = 1; mi > 0; k <<= 1) {
            int num = min(k, mi);
            for (int j = W; j >= wi * num; --j) {
                dp[j] = max(dp[j], dp[j - wi * num] + vi * num);
            }
            mi -= num;
        }
    }

    return dp[W];
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n), m(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> w[i] >> m[i];
    }
    cout << knapsack(n, W, v, w, m) << endl;
    return 0;
}