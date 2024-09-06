#include <bits/stdc++.h>
#include <list>

const int inf = 0x3f3f3f3f;
using i64 = long long;

/*
 *
 * ip->macAddr
 *
 * ip1->ip2->ip3
*/

class ArpSys {
public:
    ArpSys(int _arpCap, int _cachedPktCap, int _perIpCap)
            : arpCap(_arpCap), cachedPktCap(_cachedPktCap), perIpCap(_perIpCap) {}

    std::vector<int> update(int ip, const std::string& macAddr) {
        std::vector<int> result;
        // 如果ARP表中已存在该IP，更新其MAC地址并移动到最近使用
        if (arpTable.count(ip)) {
            arpTable[ip] = macAddr;
            // lru 移动到最近使用
            moveToRecent(ip);
        } else {
            // ARP表已满，执行LRU替换策略
            if (arpTable.size() == arpCap) {
                // 取出最近最久未使用的
                int oldIp = recentIps.back();
                // 移除
                recentIps.pop_back();
                arpTable.erase(oldIp);
            }
            // 添加新表项
            arpTable[ip] = macAddr;
            recentIps.push_front(ip);
            // lru 维护
            ipPosition[ip] = recentIps.begin();
        }

        // 处理缓存的报文并清空缓存
        if (cachedPackets.count(ip)) {
            result = cachedPackets[ip];
            cachedPackets.erase(ip);
            totalCachedPackets -= result.size();
        }

        return result;
    }

    std::string forward(int ip, int pktId) {
        // 如果在ARP表中找到MAC地址，返回MAC地址
        if (arpTable.count(ip)) {
            moveToRecent(ip);
            return arpTable[ip];
        } else {
            // 尝试将报文pktId进行缓存，返回空字符串””:
            // 如果缓存超限，则缓存失败
            // 设备最多可缓存cachedPktCap个报文
            // 同一个IP最多缓存perIpCap个报文
            if (totalCachedPackets >= cachedPktCap ||
                cachedPackets[ip].size() >= perIpCap) {
                return "";
            }

            // 缓存报文
            cachedPackets[ip].push_back(pktId);
            totalCachedPackets++;
            return "";
        }
    }

private:
    int arpCap, cachedPktCap, perIpCap;
    int totalCachedPackets = 0;  // 报文总数

    std::unordered_map<int, std::string> arpTable;

    // x->y->z
    // x->z->y
    std::list<int> recentIps;
    // lru
    std::unordered_map<int, std::list<int>::iterator> ipPosition;

    std::unordered_map<int, std::vector<int>> cachedPackets;

    void moveToRecent(int ip) {
        // x->y->z
        recentIps.erase(ipPosition[ip]);
        // x->z

        recentIps.push_front(ip);
        // y->x->z
        ipPosition[ip] = recentIps.begin();
        // ip->[y]
    }
};


void solve() {
    int op, x, y, z, n;
    std::cin >> x >> y >> z;
    ArpSys as(x, y, z);
    std::string s;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int ip;
        std::cin >> op;
        if (op) {
            std::cin >> ip >> s;
            auto res = as.update(ip, s);
            std::sort(res.begin(), res.end());
            for (auto x : res) {
                std::cout << x << " ";
            }
            std::cout << "\n";
        } else {
            int id;
            std::cin >> ip >> id;
            std::cout << as.forward(ip, id) << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
