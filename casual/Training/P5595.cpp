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
    std::string s;
    std::cin >> s;
    int pos = -1;
    int len = sz(s);
    std::string a(len, '9'), b(len, '9');
    //存在z 则必须从后往前连续，否则不存在
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'Z') {
            pos = i;
            break;
        }
    }
    if (pos != -1 && s.substr(pos) != std::string(len - pos, 'Z')) {
        std::cout << "-1";
        return;
    }

    for (int i = 0; i < len; ++i) {
    	if (s[i] == 'X')
    		b[i]--;
    	else if (s[i] == 'Y')
    		a[i]--;
    }
    std::cout << a << "\n" << b;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
