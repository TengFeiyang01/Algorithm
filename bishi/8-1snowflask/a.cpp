#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;

int getMaximumRemovals(vector<int> orders, string source, string target) {
	int n = orders.size();
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		bool ok = false;
		set<int> st;
		for (int i = 0; i < mid; ++i) {
			st.insert(orders[i] - 1);
		}

		for (int i = 0, j = 0; i < n; ++i) {
			if (st.count(i)) continue;
			if (source[i] == target[j]) {
				j++;
				if (j == target.size()) {
					ok = true;
					break;
				}
			}
		}
		if (ok) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
    	cin >> x;
    }
    string s, t;
    cin >> s >> t;
    cout << getMaximumRemovals(a, s, t) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
