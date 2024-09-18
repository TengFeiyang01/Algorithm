#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
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
using vector = std::vector<std::vector<ll>>;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;


std::vector<ll> add(std::vector<ll> A, std::vector<ll>& B) {
    std::vector<ll> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.emplace_back(t % 10);
        t = t / 10;
    }
    if (t) C.emplace_back(t);
    return C;
}

std::vector<ll> multiple(std::vector<ll> A, ll B) {
    //特判
    if (B == 0) return std::vector<ll>{0};
    int t = 0;
    std::vector<ll> C;
    for (int i = 0; i < A.size(); ++i) {
        t += A[i] * B;
        C.emplace_back(t % 10);
        t /= 10;
    }
    while (t) {
        C.emplace_back(t % 10);
        t /= 10;
    }
    return C;
}

bool cmp(std::vector<ll> A, std::vector<ll> B) { 
    if (sz(A) != sz(B)) return sz(A) < sz(B);
    for (int i = sz(A) - 1; i >= 0; --i) {
        if (A[i] != B[i]) {
            return A[i] < B[i];
        }
    }
    return true;
}

std::vector<ll> f[55][55];

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> w(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> w[i];

    for (int len = 3; len <= n; ++len) 
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int k = l + 1; k < r; ++k) {
                //f[l][r] = std::min(f[l][r], f[l][k] + f[k][r] + w[l] * w[r] * w[k]);
                auto new_v = multiple(multiple({w[l]}, w[k]), w[r]);
                new_v = add(add(new_v, f[l][k]), f[k][r]);
                if (f[l][r].empty() || cmp(new_v, f[l][r])) f[l][r] = new_v;
            }
        }
    auto ans = f[1][n];
    for (int i = sz(ans) - 1; i >= 0; --i) std::cout << ans[i];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
