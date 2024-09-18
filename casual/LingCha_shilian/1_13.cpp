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
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 5e5 + 13;

char _t[N];
/*https://codeforces.com/contest/777/submission/171012642

提示 1：贪心，从后往前枚举，每个字符串要保留尽可能多的字符。

提示 2：由于字典序的传递性，只需要比较相邻的字符串。*/

void solve() {
	int n;
    //std::cin >> n;
    scanf("%d", &n);
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	scanf("%s", _t);
    	s[i] = _t;
    }
    //for (int i = 0; i < n; ++i) std::cin >> s[i];

    for (int i = n - 2; i >= 0; --i) {
        std::string s0 = s[i], s1 = s[i + 1];
        int l = s0.size();
        if (s1.size() < l) l = s1.size();

        if (s0.substr(0, l) == s1.substr(0, l)) {
            s[i] = s0.substr(0, l);
            continue;
        }
        for (int j = 1; j < l; ++j) {
            if (s0[j] < s1[j]) break;
            if (s0[j] > s1[j]) {
                s[i] = s0.substr(0, j);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << s[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
