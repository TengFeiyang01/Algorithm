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
    std::stack<char> stk;
    std::vector<int> cnt(27, 0);
    std::cin >> s;

    int n = s.size();
    for (auto c : s) cnt[c - 'a']++;

    int i = 0, j;
    while (i != n) {
        int k = 26;
        if (!stk.empty()) {
            k = stk.top() - 'a';
        }

        for (j = 0; j < 26; ++j) {
            if (cnt[j]) break;
        }
        k = std::min(j, k);
        
        while (1) {
            if (!stk.empty() && stk.top() - 'a' == k) break;
            cnt[s[i] - 'a']--;
            stk.push(s[i++]);
            if (i == n) break;
        }

        if (!stk.empty()) {
            std::cout << stk.top();
            stk.pop();
        }
    }
    while (!stk.empty()) {
        std::cout << stk.top();
        stk.pop();
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	solve();

    return 0;
}
