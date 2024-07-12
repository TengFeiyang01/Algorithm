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
 
 const int inf = 0x3f3f3f3f;
 using ll = long long;
 using PII = std::pair<int, int>;
 const int N = 1e5 + 13;
 int n, m, nums[N];

//https://atcoder.jp/contests/abc268/submissions/37573533

//提示 1：邻项交换法，对于两个字符串，哪个应该排在前面？
//提示 2：X 越多，数字之和越小的。

 void solve() {
     int n;
     std::cin >> n;
     std::vector<std::string> v;
     for (int i = 1; i <= n; ++i) {
     	std::string s;
     	std::cin >> s;
     	v.push_back(s);
     }
	std::sort(v.begin(), v.end(), [&](std::string a, std::string b){
		ll x1 = 0, x2 = 0;
		int sum1 = 0, sum2 = 0;
		for (auto c : a) {
			if (c == 'X') x1++;
			else sum1 += c - '0';
		}
		for (auto c : b) {
			if (c == 'X') x2++;
			else sum2 += c - '0';
		}
		return x1 * sum2 > x2 * sum1;
	});	   
   
	ll ans = 0, cntx = 0;
	for (auto s : v) {
		for (auto c : s) {
			if (c == 'X')
				cntx++;
			else ans += (ll)(c - '0') * cntx;
		}
	}
	std::cout << ans << "\n";
 }
 
 int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();
 
    return 0;
 }
 