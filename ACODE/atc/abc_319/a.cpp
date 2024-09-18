#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::map<std::string, int> mp {
    	{"tourist", 3858},
		{"ksun48", 3679},
		{"Benq", 3658},
		{"Um_nik", 3648},
		{"apiad", 3638},
		{"Stonefeang", 3630},
		{"ecnerwala", 3613},
		{"mnbvmar", 3555},
		{"newbiedmy", 3516},
		{"semiexp", 3481}
    };
    std::string s;
    std::cin >> s;
    std::cout << mp[s] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}