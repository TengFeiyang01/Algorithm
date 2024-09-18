#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<typename T>
std::vector<T> input() {
    std::vector<T> a;
    T s;
    while(std::cin >> s) {
        a.push_back(s);
        if(std::cin.get() != ' ') break;
    }
    return a;
}


void solve() {
	auto s = input<std::string>();
	std::map<std::string, int> id;
	auto t = input<std::string>();
	for (int i = 0; i < t.size(); ++i) {
		id[t[i]] = i;
	}
	std::vector<std::string> ans;
	for (auto x : s) {
		if (id.count(x)) {
			ans.push_back(std::to_string(id[x]));
		} else {
			ans.push_back(x);
		}
	} 
	int n = ans.size();
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
