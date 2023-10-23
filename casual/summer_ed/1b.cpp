#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::string t;

    //GG HH 不影响答案
    //GH HG 会交换 目标是GH -> HG
    //GH 1 HG 0
    //即为01串
    //11000 翻转前缀使得0最多
    
    int ans = 0;
    for (int i = 0; i < n; i += 2) {
    	if (s[i] != s[i + 1]) {
            if (s[i] == 'G') t += "1";
            else t += "0";
    	} 
    } 
    t += "0";
    for (int i = 0; i < t.size() - 1; ++i) {
        if (t[i] != t[i + 1]) ans++;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
