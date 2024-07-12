#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> cntl, cntr;
    std::set<int> left, right;
    int l, r;
    while (n--) {
    	char op;
    	std::cin >> op >> l >> r;
    	if (op == '+') {
    		cntl[l]++;
    		cntr[r]++;
    		left.insert(l);
    		right.insert(r);
    	} else {
    		if (--cntl[l] == 0) {
    			left.erase(l);
    		}
    		if (--cntr[r] == 0) {
    			right.erase(r);
    		}
    	}
    	if (left.size() && right.size()) {
    		auto a = right.begin();
    		auto b = --left.end();
    		if (*a < *b) {
    			std::cout << "YES\n";
    		} else {
    			std::cout << "NO\n";
    		}
    	} else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}