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

void solve() {
	std::cin >> n;
    std::string s;
    std::cin >> s;
    int l = -1, r =  n;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'R') {
    		r = i;
    		break;
    	}
    }
    for (int i = 0; i < n - 1;  ++i) {
    	if (s[i] == 'L' && s[i + 1] == 'R') {
    		std::cout << i + 1 << "\n";
    		return;
    	}
    }
    for (int i = n - 1; i >= 0; --i) {
    	if (s[i] == 'L') {
    		l = i;
    		break;
    	}
    }
    if (l > r) {
    	std::cout << "0\n";
        return;
    } 
    std::cout << "-1\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
