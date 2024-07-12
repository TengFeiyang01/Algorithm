#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct point {
	int x = 0, y = 0;
};

double dist(point A, point B) {
	return std::sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void solve() {
	point a, b, p, o;
	std::cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y;

	double ans = std::min({
		std::max(dist(o, a), dist(a, p)),
		std::max(dist(o, b), dist(b, p)),
		std::max({dist(o, a), dist(a, b) / 2, dist(b, p)}),
		std::max({dist(o, b), dist(b, a) / 2, dist(a, p)}),
	});

	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cout << std::fixed << std::setprecision(10);

    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}