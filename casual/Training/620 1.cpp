#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::vector<int> cnt(10);
    int s = 0, mx = 0;
    for (int i = 0; i < 10; ++i) {
    	std::cin >> cnt[i];
    	s += cnt[i];
    	mx = std::max(mx, cnt[i]);
    }
    if (cnt[0] == 1 and s == 1) {
    	std::cout << "0\n";
    	return;
    } 
    std::vector<int> ans;


    std::function<bool()> dfs = [&]() ->bool {
    	int sum = 0, maxx = 0, id = -1;
    	for (int i = 0; i < 10; ++i) {
    		if (cnt[i] > maxx) {
    			maxx = cnt[i];
    			id = i;
    		}
    		sum += cnt[i];
    	}
    	if (sum == 0) return true;
    	sum -= maxx;
    	if (maxx > sum + 1) return false;

    	if (maxx == sum + 1) {
    		// 需要放两边 而 0 不能放两边
    		if (id == 0 and ans.empty()) {
    			return false;
    		} else {
    			ans.push_back(id);
    			cnt[id]--;
    		}
    	} else {
    		int u = ans.empty() ? 1 : 0; //从 u 开始选数字
    		int k = u ? -1 : ans.back();  //不能和 k 相同
    		for (int i = u; i < 10; ++i) {
    			if (cnt[i] and i != k) {
    				ans.push_back(i);
    				cnt[i]--;
    				break;
    			}
    		}
    	}
    	return dfs(); //放下一个数
    };

    if (dfs()) {
    	if (ans.size() == 0) std::cout << "-1\n";
    	else {
    		for (int x : ans) {
    			std::cout << x;
    		}
    		std::cout << "\n";
    		return;
    	}
    } else {
    	std::cout << "-1\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
