#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::unordered_map<char, int> m{
    	{'W', 0}, {'I', 1}, {'N', 2}, {'G', 3},
    };
    bool ok[4][4][4]{0};
    std::vector<int> cnt(4), a{0, 1, 2, 3};
    
    for (int i = 0; i < 4; ++i) std::cin >> cnt[i];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            char a, b;
            std::cin >> a >> b;
            ok[m[a]][m[b]][i] = true;
        }
    }
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector f(n, std::vector(n, std::vector(4, false)));
    for (int i = 0; i < n; ++i) {
    	f[i][i][m[s[i]]] = true;
    }
    // f[i][j][c] [i-j]这一段能否由c表示

    for (int i = n - 2; i >= 0; --i) {
    	for (int j = i + 1; j < n; ++j) {
    		for (int k = i; k < j; ++k) {
    			for (auto x : a) {
    				for (auto y : a) {
    					for (auto z : a) {
                            if (f[i][k][y] and f[k + 1][j][z] and ok[y][z][x]) {
                                f[i][j][x] = true;
                            }
    					}
    				}
    			}
    		}
    	}
    }
    
    bool flag = false;
    for (auto c : {'W', 'I', 'N', 'G'}) {
    	if (f[0][n - 1][m[c]]) {
    	   flag = true;
           std::cout << c;
        }
    }
    if (!flag) {
        std::cout << "The name is wrong!";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
