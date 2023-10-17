  #include <bits/stdc++.h>
   
  const int inf = 0x3f3f3f3f;
  using i64 = long long;
  using PII = std::pair<int, int>;
  const int N = 1e5 + 13;
  
  void solve() {
      std::vector<int> a(8);
      bool ok = 1;
      int pre = -1;
      for (int &x : a) {
      	std::cin >> x;
      	if (x % 25) ok = 0;
      	if (x < 100 or x > 675) ok = 0;
      	if (pre != -1 and pre > x) ok = 0;
      	pre = x;
      }
      std::cout << (ok ? "Yes\n" : "No\n");
  }
  
  int main() {
      std::cin.sync_with_stdio(false);
      std::cin.tie(0);
  
      solve();
  
      return 0;
  }
  