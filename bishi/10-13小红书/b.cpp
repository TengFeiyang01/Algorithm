#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    if (n == 1) {
    	std::cout << "YES\n";
    	return;
    }

    std::vector<int> periods;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i < n) periods.push_back(i);
            if (n / i != i && n / i < n) periods.push_back(n / i);
        }
    }

    for (int t : periods) {
        std::vector<int> mismatches;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s[i % t]) {
                mismatches.push_back(i);
            }
        }

        if (mismatches.empty()) {
            if (n / t > 1) {
                std::cout << "YES\n";
                return;
            } else {
                continue;  
            }
        }

        if (mismatches.size() > 4) {
            continue;
        }

        bool found = false;
        int m = mismatches.size();
        for (int i = 0; i < m && !found; ++i) {
            for (int j = i + 1; j < m && !found; ++j) {
                std::string swapped = s;
                std::swap(swapped[mismatches[i]], swapped[mismatches[j]]);
                bool is_periodic = true;
                for (int k = 0; k < n; ++k) {
                    if (swapped[k] != swapped[k % t]) {
                        is_periodic = false;
                        break;
                    }
                }
                if (is_periodic) {
                    found = true;
                    std::cout << "YES\n";
                    return;
                }
            }
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;
    while (n--)
	    solve();
    return 0;
}
