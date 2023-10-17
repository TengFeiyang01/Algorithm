#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = n + 1;

    /*
        设A是balance bracket，连通分量个数为x，那么（A）的连通分量个数是x+1；
        ()(A)的连通分量个数是x+1；(A)(A)的连通分量个数是2*x+1
        又因为A的第一个字符是左括号，所以只要看有多少对连续的左括号就可以了
        最后加上最外层的括号数量1个就是答案。
    */
    //也可以数有多少个连在一起的 '))' 每有一个 答案+1
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (s[i] == '(' and s[i + 1] == ')') {
            ans--;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
