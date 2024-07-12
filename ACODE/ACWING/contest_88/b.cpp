#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int a, b;
    std::string s, t;
    std::cin >> a >> b >> s >> t;
    std::set<std::string> st;
    std::map<char, std::string> mp{{'>', "1"}, {'v', "2"}, {'<', "3"}, {'^', "4"}};
    st.insert("1234");
    st.insert("1432");

    st.insert("2143");
    st.insert("2341");
    
    st.insert("3412");
    st.insert("3214");
    st.insert("4123");
    st.insert("4321");

    std::string ans1 = mp[s.back()] + mp[s[0]] + mp[t.back()] + mp[t[0]];
    std::string ans2 = mp[s.back()] + mp[t[0]] + mp[t.back()] + mp[s[0]] ;
    ans1 += ans1;
    ans2 += ans2;
    int cnt = 0;
    std::cout << ans1 << "\n" << ans2;

    for (int i = 0; i < 4; ++i) {
    	if (st.count(ans1.substr(i, 4)) || st.count(ans2.substr(i, 4))) {
    		std::cout << "YES";
    		return;
    	}
    }
    std::cout << "NO";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
