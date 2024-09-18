#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    const int MOD = 1000000007;
    int n, k, op, x;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> diff(n); // 差分数组
    ll p = n, val; // 记录被变成 0 的位置，及其对应的值
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    val = a[n - 1];
    diff[0] = a[0];
    for (int i = 1; i < n; ++i) diff[i] = a[i] - a[i - 1];
    for (int i = 0; i < k; ++i) {
        cin >> op >> x;
        // op 1
        if (op == 1) {
            diff[0] += x;
            val += x;
        }
        // op 2
        else if (op == 2) {
            diff[0] -= x;
            val -= x;
            while (p > 0 && val < 0) {
                val -= diff[--p];
            }
            if (p == 0 && val < 0) diff[0] = 0, val = 0;
        }
    }
    ll ans = diff[0], cnt = diff[0];
    if (p == 0) ans = (val % MOD)* n;
    else {
        for (int i = 1; i < p; ++i) {
            cnt += diff[i];
            ans += cnt;
            ans %= MOD;
        }
        ans += (n - p) * val;
    }
    ans %= MOD;
    printf("%lld", ans);
    return 0;
}