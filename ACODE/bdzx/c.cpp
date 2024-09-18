#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = unsigned long long;

constexpr int P1 = 1731731, P2 = 131331;
constexpr int N = 1e5 + 13;

i64 h1[N][26]{0}, h2[N][26]{0};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = " " + s;

    std::vector<i64> p1(n + 1, 1), p2(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
    	p1[i] = p1[i - 1] * P1 % P2;
    	p2[i] = p2[i - 1] * P2 % P1;
    }	

    for (int i = 1; i <= n; ++i) {
    	h1[i][s[i] - 'a'] += i64(s[i] - 'a' + 1) * p1[i] % P2;
    	h2[i][s[i] - 'a'] += i64(s[i] - 'a' + 1) * p2[i] % P1;
    	for (int j = 0; j < 26; ++j) {
	    	h1[i][j] += h1[i - 1][j] % P2;
	    	h2[i][j] += h2[i - 1][j] % P1;
    	}
    }



   	int l1, l2, r1, r2;

    auto check = [&](int j) -> bool {
    	if (l1 > l2) {
    		std::swap(l1, l2);
    		std::swap(r1, r2);
    	}
    	if (l1 == l2) {
    		return true;
    	}
    	int d = l2 - l1;

    	return (((h1[r1][j] - h1[l1 - 1][j]) * p1[d]) % P2) == ((h1[r2][j] - h1[l2 - 1][j]) % P2);
    };


    while (q--) {
    	std::cin >> l1 >> r1 >> l2 >> r2;
    	std::string t;
    	

    	bool ok = true;
    	for (int i = 0; i < 26; ++i) {
    		if (!check(i)) {
    			ok = false;
    			t += char(i + 'a');
    		}
    	}

    	if (ok) {
    		std::cout << "0\n\n";
    	} else {
    		std::cout << t.size() << "\n" << t << "\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
