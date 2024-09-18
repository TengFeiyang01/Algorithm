#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int strStr(std::string s, std::string p) {
    int n = s.size(), m = p.size();
    if(m == 0) return 0;
    s.insert(s.begin(),' ');
    p.insert(p.begin(),' ');
    std::vector<int> next(m + 1);
    for(int i = 2, j = 0; i <= m; i++){
        while(j and p[i] != p[j + 1]) j = next[j];
        if(p[i] == p[j + 1]) j++;
        next[i] = j;
    }
    int ans = -1;
    for(int i = 1, j = 0; i <= n; i++){
        while(j and s[i] != p[j + 1]) j = next[j];
        if(s[i] == p[j + 1]) j++;
        if(j == m) {
        	return i - m;
        }
    }
    return -1;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n), b(n);
    std::vector<std::string> s(n), t(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    bool ok = true;
    std::vector<int> ans;
    for (int p = 0; p < n; ++p) {
    	std::string S, T;
    	for (int i = p, j = 0; i >= 0 and j < m; --i, ++j) {
    		S += a[i][j];
    		T += b[i][j];
    	}
    	if (S == T) {
    		ans.push_back(0);
    		continue;
    	}
    	S = S + S;
    	int x = strStr(S, T);
    	if (x == -1) {
    		ok = false;
    	} else {
    		ans.push_back(T.size() - x);
    	}
    }

    for (int p = 1; p < m; ++p) {
    	std::string S, T;
    	for (int i = n - 1, j = p; i >= 0 and j < m; --i, ++j) {
    		S += a[i][j];
    		T += b[i][j];
    	}
    	if (S == T) {
    		ans.push_back(0);
    		continue;
    	}
    	S = S + S;
    	int x = strStr(S, T);
    	if (x == -1) {
    		ok = false;
    	} else {
    		ans.push_back(T.size() - x);
    	}
    }
    if (!ok) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n";
    	for (int x : ans) {
    		std::cout << x << " ";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
// 1 2
// 3 4
// 5 6
// 7 8
