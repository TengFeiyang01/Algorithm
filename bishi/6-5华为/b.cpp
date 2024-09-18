#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
int a[40001]{0};

void solve() {
    std::string op;
    std::set<int> file;

    while (std::cin >> op) {
    	if (!(op == "d" or op == "i")) {
    		int i = 0, j = 0, k = 0;
    		while (op[i] != ',') {
    			k = k * 10 + (op[i] - '0');
    			++i;
    		}
    		i++;
    		while (i < op.size()) {
    			j = j * 10 + (op[i] - '0');
    			++i;
    		}
    		a[k] = j;
    		file.insert(k);
    	} else {
    		if (op == "d") {
    			int k;
    			std::cin >> k;
    			auto it = file.upper_bound(k);
    			if (it == file.end()) {
    				it = file.begin();
    			}
    			a[*it] += a[k];
    			a[k] = 0;
    			file.erase(k);
    		}
    		if (op == "i") {
    			int k, j;
    			std::cin >> k >> j;
    			auto it = file.upper_bound(k);
    			if (it == file.end()) {
    				it = file.begin();
    			}
    			a[*it] -= j;
    			a[k] = j;
    			file.insert(k);
    		}
    	}
    }
    int mx = 0;

    for (int x : file) {
    	if (a[x] > mx) {
    		mx = a[x];
    	}
    }

    std::vector<int> ans;

    for (int x : file) {
    	if (a[x] == mx) {
    		ans.push_back(x);
    	}
    }
        for (int i = 0; i < ans.size(); ++i) {
    		std::cout << ans[i] << "," << a[ans[i]] << " \n"[i == ans.size() - 1];
    	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
