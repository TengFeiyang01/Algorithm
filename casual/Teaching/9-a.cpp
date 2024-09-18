#include <bits/stdc++.h>
#include <iostream> // 输入
#include <string>
#include <map> // O(log n)
#include <vector>
#include <unordered_map> //O(1)
#include <algorithm>


const int inf = 0x3f3f3f3f;
using i64 = long long;

class MiniDhcpServer{
public:
    MiniDhcpServer() {
    	for (int i = 0; i < 256; ++i) {
    		unUsedIPs.insert(i);
    	}
    }

    std::string IP(int i) {
    	return "192.168.0." + std::to_string(i);
        /*
         * .0
         * .1
         * .12
         *
         * */
    }

    std::string Request(const std::string& macAddr) {
        // 如果对应的IP已分配并未释放，则为重复申请，直接返回对应已分配的IP地址。
    	if (macToIp.count(macAddr)) {
    		return IP(macToIp[macAddr]);
    	}

        // 如果一个MAC地址已申请过并已释放，即：
        // 当前未分配IP地址，则为再申请，优先分配最近一次曾经为其分配过的IP地址，请返回此IP地址。
    	if (macToReleasedIP.count(macAddr)) {
    		auto last = macToReleasedIP[macAddr];
    		macToIp[macAddr] = last;
    		return IP(last);
    	}

        // 按升序分配从未被分配过的IP地址
    	if (!unUsedIPs.empty()) {
    		auto newIp = *unUsedIPs.begin(); // 取出最小的
    		unUsedIPs.erase(unUsedIPs.begin());
    		macToIp[macAddr] = newIp;
    		return IP(newIp);
    	} else if (!usedIPs.empty()) {
            // 如果地址池中地址都已被分配过，则按升序分配已释放出来的IP地址；
            // 若可分配成功，则返回此IP地址。
    		auto newIp = *usedIPs.begin();
    		usedIPs.erase(usedIPs.begin()); // 从已分配 移除
    		macToIp[macAddr] = newIp;
	    	return IP(newIp);
    	}
    	return "NA";
    }

    void Release(const std::string& macAddr) {
    	if (macToIp.count(macAddr)) {
            // 如果申请释放的对应IP地址已分配，则释放此IP地址
    		auto released = macToIp[macAddr];
    		usedIPs.insert(released);
    		macToReleasedIP[macAddr] = released;
    		macToIp.erase(macAddr);
    	}
    }
private:
	std::set<int> usedIPs;
	std::set<int> unUsedIPs;

    std::unordered_map<std::string, int> macToIp;
    std::unordered_map<std::string, int> macToReleasedIP;
};

void solve() {
	int n;
	std::cin >> n;
	std::string s;

	MiniDhcpServer ms;

	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		auto op = s.substr(0, 7), mac = s.substr(8);
		if (op[2] == 'Q') {
			auto ans = ms.Request(mac);
			std::cout << ans << "\n";
		} else {
			ms.Release(mac);
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
