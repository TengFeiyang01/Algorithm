#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

bool get(std::string s, std::string p) {
        int n = s.size(), m = p.size();
        if(m == 0) return 0;
        s.insert(s.begin(),' ');
        p.insert(p.begin(),' ');
        std::vector<int> ne(m + 1);
        for(int i = 2, j = 0; i <= m; i++){
            while(j and p[i] != p[j + 1]) j = ne[j];
            if(p[i] == p[j + 1]) j++;
            ne[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j and s[i] != p[j + 1]) j = ne[j];
            if(s[i] == p[j + 1]) j++;
            if(j == m) return true;
        }
        return false;
    }

void solve() {
    std::string s, t;
    for (int i = 0; i < 3; ++i) {
    	std::cin >> s >> t;
    	s += s;
    	std::cout << get(s, t);
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
