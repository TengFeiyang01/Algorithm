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
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];


void solve() {
	//a b c
	int a[6];
	for (int i = 0; i < 6; ++i) cin >> a[i];
	if (a[0] != a[2] && a[0] != a[4] && a[2] != a[4])
		cout << "YES\n";
	else if (a[1] != a[3] && a[1] != a[5] && a[3] != a[5])
		cout << "YES\n";
	else cout << "NO\n";
}
 
int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
