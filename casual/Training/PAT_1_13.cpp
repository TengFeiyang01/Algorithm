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
 
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::string s;
	std::cin >> s;
    std::string pat_str = "PAT";
    int pNum = 0, aNum = 0, tNum = 0; 

    
    for(auto&c : s){
        if (pat_str.find(c) == std::string::npos) {
        	std::cout << "NO\n";
        	return;
        }
        if (c == 'P') pNum++;
        else if (c == 'T') tNum++;
        else if (c == 'A') aNum++;    
    }
    
    if ((pNum != 1) || (tNum !=1) || (aNum < 1)) {
    	std::cout << "YES\n";
    	return;
    }

    int la = s.find('P');
    int lb = s.find('T') - s.find('P') - 1;
    int lc = sz(s) - s.find("T") - 1;

    if (s.find("T") - s.find("P") == 1) {
    	std::cout << "NO\n";
        return;
    }

    if (la * lb == lc)  
        std::cout << "YES\n";
    else 
    	std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
