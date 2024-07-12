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
	auto a = input<int>();
	auto b = input<int>();
	int n = a.size(), m = b.size();
	int len = 0, st = 0;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	int k = 0;
        	while (i + k < n and j + k < m and a[i + k] == b[j + k]) {
        		k++;
        	}
        	if (k > len) {
        		len = k;
        		st = i;
        	}
        }
    }
    if (!len) {
    	std::cout << "-1\n";
    	return;
    }


    for (int i = st; i < st + len; ++i) {
    	std::cout << a[i] << " \n"[i == st + len - 1];
    } 

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
