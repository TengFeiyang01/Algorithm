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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
ll n, m, k, x;

std::string H = "Happy new year!";

/*
    AC 只能发生在这些地方：
    s[1] 内部
    s[2] 内部
    s[1]+s[1] 交界处（这是不可能的）
    s[1]+s[2] 交界处
    s[2]+s[1] 交界处
    s[2]+s[2] 交界处

    那么暴力枚举 s[1] 中有多少 AC，开头是否为 C，结尾是否为 A。
    s[2] 同理。
    然后迭代计算 s[k] 的 AC 个数，看是否为 x。

    注意如果 AC 数量超过 x，要及时退出循环，否则会溢出。虽然这题没有针对 hack 这种代码的数据，但是还是要注意不要写出错误的代码。
*/


void solve() {
    std::cin >> k >> x >> n >> m;

    for (int c1 = 0; c1 < 2; ++c1)
        for (int a1 = 0; a1 < 2 && c1 + a1 <= n; ++a1)
            for (int c2 = 0; c2 < 2; ++c2)
                for (int a2 = 0; a2 < 2 && c2 + a2 <= m; ++a2)
                    for (int ac1 = 0; ac1 <= (n - c1 - a1) / 2; ++ac1)
                        for (int ac2 = 0; ac2 <= (m - c2 - a2) / 2; ++ac2) {
                            int C1 = c1, C2 = c2, A1 = a1, AC1 = ac1, AC2 = ac2;
                            for (int i = 2; i < k && AC2 <= x; ++i) {
                                int old_AC2 = AC2;
                                AC2 = AC1 + (A1 & C2) + old_AC2;
                                AC1 = old_AC2;
                                std::swap(C1, C2);
                                A1 = a2;
                            }
                            if (AC2 == x) {
                                for (int i = 0; i < c1; ++i) std::cout << "C";
                                for (int i = 0; i < ac1; ++i) std::cout << "AC";
                                for (int i = 0; i < n - c1 - ac1 * 2 - a1; ++i) std::cout << "B";
                                for (int i = 0; i < a1; ++i) std::cout << "A";
                                std::cout << "\n";
                                for (int i = 0; i < c2; ++i) std::cout << "C";
                                for (int i = 0; i < ac2; ++i) std::cout << "AC";
                                for (int i = 0; i < m - c2 - ac2 * 2 - a2; ++i) std::cout << "B";
                                for (int i = 0; i < a2; ++i) std::cout << "A";
                                std::cout << "\n";
                                return;
                            }
                        }


    std::cout << H << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
