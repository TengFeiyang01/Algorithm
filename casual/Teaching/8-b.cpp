#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

/*
[1]: [4, 7]
[2]: [5, 7]
[3]: [6, 7]

[1]  
[1, 2]
[1, 3]

*/
// O(m) 

void solve() {
    int n, m;
    std::cin >> m >> n;
    // 存储每个数的下标
    std::unordered_map<int, std::deque<int>> pos;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].push_back(i);
    }
    for (auto &[k, v] : pos) {
    	v.push_back(n);
    }
    int ans = 0;

    // 操作系统，未来最晚被访问的移除，可以最优
    std::unordered_set<int> st;
    // st.find(x) == st.end()
    // st.count(x) == 0

    for (auto x : a) {
    	if (!st.count(x)) {
            ans++; // 不在缓存中

            // 放入缓存之前：检查是否满
    		if (st.size() == m) {
    			int mx = -1;
                // 找出缓存中最晚被访问的
    			for (auto y : st) {  // 1 2
    				if (mx == -1 || pos[y].front() > pos[mx].front()) {
    					mx = y;
    				}
    			}
    			st.erase(mx);
    		}
            // 插入缓存
    		st.insert(x);
    	}
 		pos[x].pop_front();
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
/*
// 缓存满：
    选出最晚访问的

1     1
1 2   2
1 3   3  
1 3   3
2 3   4
2 3   4
*/