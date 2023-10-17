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
using  namespace  std;

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e4 + 13;
ll mod = 1e9 + 7;

long long binpow (long long a, long long n) {
  if (n == 0)
    return 1;
  if (n % 2 == 1)
    return (binpow (a, n-1) * a) % mod;
  else {
    long long b = (binpow (a, n/2)) % mod;
    return (b * b) % mod;
  }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        ll p = ((n * (n + 1) % mod * (2 * n + 1) % mod * 2022 % mod) * binpow(6, mod - 2));
        ll q = ((n - 1) * (n) % (n + 1) % mod * 2022 % mod * binpow(3, mod - 2));

        ll ans = (p + q) % mod;
        ans %= mod;

        cout << ans << "\n";
    }

    return 0;
}
