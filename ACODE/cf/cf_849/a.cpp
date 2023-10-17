#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using namespace std;
using i64 = long long;


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    string s = "codeforces";
    unordered_set mySet(s.begin(), s.end());
    // unordered_set<char> mySet;
    // for (auto c : s)
    //     mySet.insert(c);    
    while (t--) {
        char c;
        cin >> c;
        cout << (mySet.count(c) ? "YES" : "NO") << "\n";
    }
    return 0;
}