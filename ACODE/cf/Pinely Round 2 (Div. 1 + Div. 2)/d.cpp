#include <bits/stdc++.h>

using i64 = long long;
/*
LR和UD的染色是相互独立的，UD的染色结果不能影响LR

LR会影响列的染色结果，需要相同列的LR来中和。

UD同理，会影响行的染色结果，需要相同行的UD来中和。
*/
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    std::vector<int> col[m], row[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        for (int j = 0; j < m; ++j) {
        	if (s[i][j] == 'L') {
        		col[j].push_back(i);
        	}
        	if (s[i][j] == 'U') {
        		row[i].push_back(j);
        	}
        }
    }
    
    bool ok = true;
    for (int i = 0; i < n; ++i) {
    	if (row[i].size() % 2) {
    		ok = false;
    	}
    }

    for (int i = 0; i < m; ++i) {
    	if (col[i].size() % 2) {
    		ok = false;
    	}
    }

    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < row[i].size(); ++j) {
			int x = row[i][j];
			if (j & 1) {
				s[i][x] = 'W';
				s[i + 1][x] = 'B';
			} else {
				s[i][x] = 'B';
				s[i + 1][x] = 'W';
			}
		}    	
    }

    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < col[i].size(); ++j) {
    		int x = col[i][j];
    		if (j & 1) {
    			s[x][i] = 'W';
    			s[x][i + 1] = 'B';
    		} else {
    			s[x][i] = 'B';
    			s[x][i + 1] = 'W';
    		}
    	}
    }

    if (!ok) {
    	std::cout << "-1\n";
    	return;
    }

    for (int i = 0; i < n; i++) {
        std::cout << s[i] << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}