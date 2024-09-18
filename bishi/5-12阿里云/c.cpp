#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    i64 ans = 0;
    int n = s.size();
    
    auto get = [&](int st, int ed) {
    	int x = 0, y = 0;
    	for (int l = st, r = st; r <= ed; ++r) {
    		if (s[r] == 'r') {
    			x++;
    		} else if (s[r] == 'e') {
    			y++;
    		}
    		while (x and y) {
    			ans += ed - r + 1;
    			if (s[l] == 'r') {
    				x--;
    			} else if (s[l] == 'e') {
    				y--;
    			}
    			l++;
    		}
    	}
    };
    int i = 0;
    while (i < n) {
    	while (i < n and s[i] == 'd') {
    		i++;
    	}
    	int j = i;
    	while (j < n and s[j] != 'd') {
    		j++;
    	}
    	get(i, j - 1);
    	i = j;
    }



    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
