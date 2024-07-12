#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    std::map<char, int> cnts, cntt;
    for (auto c : s) cnts[c]++;
    for (auto c : t) cntt[c]++;
    
    int ans = 0, res = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnts.count(c) and cntt.count(c)) {
            int x = std::min(cnts[c], cntt[c]);
            ans += x;
            cnts[c] -= x;
            cntt[c] -= x;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (cnts.count(c) and cntt.count(c)) {
            int x = std::min(cnts[c], cntt[c]);
            ans += x;
            cnts[c] -= x;
            cntt[c] -= x;
        }
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnts.count(c) and cntt.count(toupper(c))) {
            int x = std::min(cnts[c], cntt[toupper(c)]);
            res += x;
            cnts[c] -= x;
            cntt[toupper(c)] -= x;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (cnts.count(c) and cntt.count(tolower(c))) {
            int x = std::min(cnts[c], cntt[tolower(c)]);
            res += x;
            cnts[c] -= x;
            cntt[tolower(c)] -= x;
        }
    }
    

    std::cout << ans << " " << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}