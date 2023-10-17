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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::string s;
    std::cin >> s;
    n = s.size();

    if (s[0] == s[n - 1]) {
   		auto a = s.substr(0, 1);
    	auto b = s.substr(1, n - 2);
    	auto c = s.substr(n - 1);
    	std::cout << a << " " << b << " " << c << "\n";
    	return;
    } else {
    	for (int i = 1; i < n - 1; ++i) {
    		if (s[i] == 'a') {
    			auto a = s.substr(0, i);
    			auto b = s.substr(i, 1);
    			auto c = s.substr(i + 1);
    			std::cout << a << " " << b << " " << c << "\n";
    			return;
    		} else {
    			auto a = s.substr(0, 1);
    			auto b = s.substr(i, n - i - 1);
    			auto c = s.substr(n - 1);
                std::cout << a << " " << b << " " << c << "\n";
    		 	return;
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
