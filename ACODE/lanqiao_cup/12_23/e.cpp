#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

#ifndef ONLINE_JUDGE
#define debug(x) \
  cerr << __FILE__ ":" << __LINE__ << ": (" #x ") = " << x << "\n"
#else
#define debug(...)
#endif

constexpr i64 mod = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<i64> f(16);
  for (int i = 0; i < 16; i += 1) {
    if (i % 4 == 0) { f[i] = 1; }
  }
  for (int i = 0, ai; i < n; i += 1) {
    vector<i64> g(16);
    cin >> ai;
    for (int j = 0; j < 16; j += 1) {
      for (int k = 0; k < 4; k += 1) {
        int x = j / 4 + k * 4;
        if (__builtin_popcount(j) + __builtin_popcount(k) == ai) {
          if ((g[x] += f[j]) >= mod) { g[x] -= mod; }
        }
      }
    }
    f.swap(g);
  }
  i64 ans = 0;
  for (int i = 0; i < 4; i += 1) { ans += f[i]; }
  cout << ans % mod;
}