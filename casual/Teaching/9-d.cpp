#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int block, n;
    std::cin >> block >> n;
    std::vector<std::pair<i64, i64>> a(n);
//    for (auto &t : a) {
//        std::cin >> t.first >> t.second;
//    }
    for (auto &[l, r]: a) {
        std::cin >> l >> r;
    }
    std::sort(a.begin(), a.end());

    std::vector<std::pair<i64, i64>> res, ans;
    for (const auto &[l, r]: a) {
        // 如果还没有区间 ||
        // [   ]
        //  [     ]     新加入的区间的右端点大于当前已经合并的范围
        //  [ ]         新加入的区间的右端点小于当前已经合并的范围
        if (res.empty() or res.back().second + 1 < l) {
            res.emplace_back(l, r);
        } else {
            res.back().second = std::max(res.back().second, r);
        }
    }
    //   [  ][  ]
    //   [    ]  // 最后一个单独
    // [ |  ]    // 第一个单独
    // [][  ]
    // [     ]  // 都有
    // 每个扇区的左端点编号都是 block*k
    for (const auto &[l, r]: res) {
        // 拆分
        if (l % block) { // l 之前需要拆分
            // l 之后的下一个扇区的左端点-1
            // [ |  ]    // 第一个单独
            // []|
            // x / y 上取整 -> (x + y - 1) / y
            // [0, 3][4, 7]
            // [5, 6]
            // [5, 6]
            i64 p = (l + block - 1) / block * block - 1;
            ans.emplace_back(l, std::min(r, p));
            if (p >= r) {
                continue;
            }
        }

        i64 cur = (l + block - 1) / block * block;
        while (cur <= r) {
            // [  ][  ]
            // [ ]
            // [    ] r大
            i64 newR = std::min(r, cur + block - 1);
            // std::cout << cur << " " << newR << "\n";
            ans.emplace_back(cur, newR);
            cur = newR + 1;
        }
    }
    for (const auto &t : ans) {
        std::cout << t.first << " " << t.second << "\n";
    }
//    for (const auto &[l, r]: ans) {  // C++ 17 struct binding
//        std::cout << l << " " << r << "\n";
//    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
