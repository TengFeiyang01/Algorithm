#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

class OrderSystem {
public:
    OrderSystem() {}

    void Order(int customerId, const std::vector<std::string>& goods) {
        for (const auto& good : goods) {
            orders[good].push(customerId);
            cnt[customerId]++;
        }
    }

    void Deliver(const std::vector<std::string>& goods) {
        for (const auto& good : goods) {
            if (orders.count(good) && !orders[good].empty()) {
                int customerId = orders[good].front();
                orders[good].pop();
                cnt[customerId]--;
                if (cnt[customerId] == 0) {
                    cnt.erase(customerId);
                }
            }
        }
    }

    int Query() {
        int maxCustomerId = -1;
        int maxOrderCount = 0;

        for (const auto& entry : cnt) {
            if (entry.second > maxOrderCount || 
               (entry.second == maxOrderCount && entry.first < maxCustomerId)) {
                maxOrderCount = entry.second;
                maxCustomerId = entry.first;
            }
        }

        return maxCustomerId == 0 ? -1 : maxCustomerId;
    }

private:
    std::unordered_map<std::string, std::queue<int>> orders;
    std::unordered_map<int, int> cnt;
};


void solve() {
	OrderSystem os;
    int n, op, m, x;
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
    	std::cin >> op;
    	if (op == 1) {
    		std::cout << os.Query() << "\n";
    	} else if (op == 0) {
    		std::cin >> x >> m;
    		std::vector<std::string> tmp;
    		for (int i = 0; i < m; ++i) {
    			std::cin >> s;
    			tmp.push_back(s);
    		}
    		os.Order(x, tmp);
    	} else {
    		std::cin >> m;
    		std::vector<std::string> tmp;
    		for (int i = 0; i < m; ++i) {
    			std::cin >> s;
    			tmp.push_back(s);
    		}
    		os.Deliver(tmp);    	
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
