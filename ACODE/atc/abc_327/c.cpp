#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int a[9][9];
    std::set<int> st;
    for (int i = 0; i < 9; ++i) {
    	st.insert(i + 1);
    	for (int j = 0; j < 9; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    bool ok = true;
    for (int i = 0; i < 9; ++i) {
        std::set<int> s;
    	for (int j = 0; j < 9; ++j) {
            s.insert(a[i][j]);
        }
        if (s != st) {
            ok = false;
        }
        s.clear();
        for (int j = 0; j < 9; ++j) {
            s.insert(a[j][i]);
        }
        if (s != st) {
            ok = false;
        }
    }

    for (int i = 0; i < 9; i += 3) {
    	for (int j = 0; j < 9; j += 3) {
            std::set<int> s;
    		for (int p = 0; p < 3; ++p) {
    			for (int q = 0; q < 3; ++q) {
    		  	   	s.insert(a[i + p][j + q]);
    			}
    		}
            if (s != st) {
                ok = false;
            }
    	}
    }
    std::cout << (ok ? "Yes\n" : "No");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
