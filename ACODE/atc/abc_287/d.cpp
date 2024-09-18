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

void solve() {
    int n, m;
    std::string s, t;
    std::cin >> s >> t;
    n = sz(s);
    m = sz(t);
    int l = 0, r = 0;
    for (int i = 0; i < m; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == '?' || t[i] == '?') {
                l++;
                continue;
            } else {
                break;
            }
        } else {
            l++;
        }
    }

    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i, --j) {
        if (s[i] != t[j]) {
            if (s[i] == '?' || t[j] == '?') {
                r++;
                continue;
            } else {
                break;
            }
        } else {
            r++;
        }
    }


    for (int x = 0; x <= t.size(); ++x) {
    	int f = 1;
        if (x > l) f = 0;
        if (m - x > r) f = 0;


		if (f) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
