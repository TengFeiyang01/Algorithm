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

void pre(std::string in, std::string la) {
	int n = in.size();
	if (n) {
		std::cout << la.back();	//找根输出
		int k = in.find(la.back());
		pre(in.substr(0, k), la.substr(0, k));
		pre(in.substr(k + 1), la.substr(k, n - k - 1));//递归左右子树；
	}
}

void solve() {
    std::string in, la;
    std::cin >> in >> la;
	pre(in, la);    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
