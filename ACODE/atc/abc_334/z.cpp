#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
	i64 atk = 0, atkper = 0, def = 0, spd = 0;
	for (int i = 0; i < 6; ++i) {
		i64 x;
		std::string s;
		std::cin >> s >> x;
		if (s == "atk") {
			atk += x;
		} else if (s == "atkper") {
			atkper += x;
		} else if (s == "def") {
			def += x;
		} else {
			spd += x;
		}
		int cnt;
		std::cin >> cnt;
		while (cnt--) {
			std::cin >> s >> x;
			if (s == "atk") {
				atk += x;
			} else if (s == "atkper") {
				atkper += x;
			} else if (s == "def") {
				def += x;
			} else {
				spd += x;
			}
		}
	}

	std::cout << "atk " << atk << "\n";
	std::cout << "atkper " << atkper << "\n";
	std::cout << "def " << def << "\n";
	std::cout << "spd " << spd << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
