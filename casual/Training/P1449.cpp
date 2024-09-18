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
    //std::cout << s;
    std::stack<int> num;
    for (int i = 0; i < sz(s); ++i) {
        char c = s[i];
    	if (c == '.') continue;
    	else if (c >= '0' && c <= '9') {
            int sum = 0;
            while (isdigit(s[i])) {
                sum = sum * 10 + s[i++] - '0';
            }
            --i;
            num.push(sum);
    	} else if (c == '@') {
            break;
        } else {
    		int a = num.top();
    		num.pop();
    		int b = num.top();
    		num.pop();
    		if (c == '-') {
    			b = b - a;
    		} else if (c == '+') {
    			b = b + a;
    		} else if (c == '*') {
    			b = b * a;
    		} else if (c == '/') {
    			b = b / a;
    		}
    		num.push(b);
    	}
    }
    std::cout << num.top();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
