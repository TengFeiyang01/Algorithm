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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

bool check(int x) {
	std::set<int> s;
	int cnt = 0;
	while (x) {
		s.insert(x % 10);
		x /= 10;
		cnt++;
	}
	return sz(s) == cnt;
}

void solve() {
    int x;
    std::cin >> x;

    for (int i = x + 1; i <= 9000; ++i) {
    	if (check(i)) {
    		std::cout << i;
    		return;
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
