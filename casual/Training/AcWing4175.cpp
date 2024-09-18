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
int m, H, nums[N], Time[N]{0}, dec[N]{0};

void solve() {
	int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> nums[i];
    for (int i = 1; i <= n; ++i) std::cin >> dec[i];
    for (int i = 2; i <= n; ++i) {
    	std::cin >> Time[i];
    	Time[i] += Time[i - 1];
    }
	std::cin >> H;	    

	int ans = 0;

	for (int k = 1; k <= n && Time[k] <= H; ++k) {
		std::priority_queue<PII> q;
		for (int j = 1; j <= k; ++j) {
			q.emplace(nums[j], dec[j]);
		}
		int t = H - Time[k], res = 0;

		for (int j = 1; j <= t; ++j) {
			auto[x, y] = q.top();
			q.pop();
			res += x;
			if (x <= 0) break;
			q.emplace(x - y, y);
		}
		ans = std::max(ans, res);
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



/*#include <iostream>
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
const int N = 1e3 + 13;
int m, H, nums[N], Time[N]{0}, dec[N]{0};


int work(int n, int T) {
	int res = 0;
	std::vector<int> spend(N, 0);

	auto get = [&](int k) {
		return std::max(0, nums[k] - dec[k] * spend[k]);
	};

	for (int i = 0; i < T; ++i) {
		int t = 1; 
		for (int j = 1; j <= n; ++j) {
			if (get(j) > get(t))
				t = j;
		}
		res += get(t);
		spend[t]++;
	}
	return res;
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> nums[i];
    for (int i = 1; i <= n; ++i) std::cin >> dec[i];
    for (int i = 2; i <= n; ++i) {
    	std::cin >> Time[i];
    	Time[i] += Time[i - 1];
    }
	std::cin >> H;

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = std::max(res, work(i, H - Time[i]));
	}

	std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
*/