#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 2>> queries(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> queries[i][0] >> queries[i][1];
    }

    // lambda 表达式
    // std::sort(queries.begin(), queries.end(), [&](auto x, auto y) {
    //     if (x[1] != y[1]) {
    //         return x[1] < y[1];
    //     }
    //     return x[0] < y[0];
    // });
    std::sort(queries.begin(), queries.end());

    
    int last = 1, res = 0, ok = 0;

    for (int i = 0; i < m; ++i) {   // 枚举所有区间，区间已经按照左端点进行排序
    	int j = i, r = -inf;
        // 双指针遍历所有左端点在st左边的区间右端点的最大值
    	while (j < m && queries[j][0] <= last) {  
    		r = std::max(r, queries[j][1]);
    		++j;
    	}
    	if (r < last) {  // 如果当前最大的区间右端点都无法到达st,那么则无法覆盖，覆盖失败返回-1
    		res = -1;
    		break;
    	}
    	++res;  // 可以覆盖，区间数++
    	if (r >= n) {  // 如果所选区间加上已经大于了ed，则覆盖完毕
    		ok = 1;
    		break;
    	}
    	last = r;   // 更新起点
    	i = j - 1;  // 更新双指针位置,注意在此是i=j-1而不是i=j,循环中i还会++,j已经指向了下一个区间位置
    }
    if (!ok) {
    	res = -1;
    }
    std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
