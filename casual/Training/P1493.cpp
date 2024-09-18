#include <bits/stdc++.h>

struct Pear {
	int val, id;

	bool operator<(const Pear& b) const {
		return val < b.val;
	}
};

void solve() {
    int n, c1, c2, c3;
    std::cin >> n >> c1 >> c2 >> c3;
    std::vector<int> a(n), b(n);
    std::vector<Pear> c(n), d(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	std::cin >> b[i];
        c[i] = {b[i], i};
    	d[i] = {c1 * a[i] + c2 * b[i] - c3, i};
    }

    std::sort(c.begin(), c.end());
    std::sort(d.begin(), d.end());

   	int tot = 0;
   	for (int i = 0, ans = 0; i < n; ++i, ans = 0) {
   		std::vector<int> sum(2010);
   		for (int j = 0, k = 0; j < n; ++j) {
   			for (; k < n and d[k].val <= c1 * a[i] + c2 * c[j].val; ++k) {
   				if (a[d[k].id] >= a[i] and b[d[k].id] >= c[j].val) {
   					ans++;  
   					sum[b[d[k].id]]++;
   				}
   			}
            if (j) {
       			ans -= sum[c[j - 1].val];
       			sum[c[j - 1].val] = 0;
            }
   			tot = std::max(tot, ans);
   		}
   	}
   	std::cout << tot;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
