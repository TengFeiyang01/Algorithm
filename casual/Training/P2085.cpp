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

//大根堆存m个即可，当前比最小的最大还大，直接跳过，否则入堆，弹出最大值。

void solve() {
    int n, m, mid;
    std::cin >> n >> m;
    int a, b, c;
    std::priority_queue<int> pq;
    for (int j = 0; j < n; ++j) {
    	std::cin >> a >> b >> c;
    	for (int i = 1; i <= m; ++i) {
    		int t = a * i * i + b * i + c;
    		if (j == 0) pq.push(t);
            else {
                if (t < pq.top()) {
                    pq.push(t);
                    pq.pop();
                } else break;
            }
    	}
    }
    std::stack<int> st;
    for (int i = 0; i < m; ++i) {
    	int t = pq.top();
    	pq.pop();
        st.push(t);
    }
    while (sz(st)) {
        std::cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
