#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

class Cmd {
public:
    int cmdType;
    int duration;
    int requestId;

    Cmd(int type, int dur, int reqId) : cmdType(type), duration(dur), requestId(reqId) {}

    std::string toString() const {
        std::ostringstream oss;
        oss << "[" << cmdType << ", " << duration << ", " << requestId << "]";
        return oss.str();
    }
};

class Solution {
public:
    int calcTotalCycles(const std::vector<Cmd>& rcvCmds) const {
        int ans = 0;
        std::set<int> apply;
        std::map<int, int> st, ed;
        std::vector<Cmd> a;
        for (const auto& cmd : rcvCmds) {
            if (cmd.cmdType == 0) {
                if (!apply.count(cmd.requestId)) {
                    apply.insert(cmd.requestId);
                    a.push_back(cmd);
                }
            } else {
                if (apply.count(cmd.requestId)) {
                    apply.erase(cmd.requestId);
                    a.push_back(cmd);
                }
            }
        }
        int res = 0;
        for (const auto& cmd : a) {
            std::cout << cmd.toString() << std::endl;
            if (cmd.cmdType == 0) {
                ans = std::max(ans, ed[cmd.requestId]) + cmd.duration;
                st[cmd.requestId] = ans;
            } else {
                res = std::max(res, st[cmd.requestId]) + cmd.duration;
                ed[cmd.requestId] = res;
            }
        }
        return std::max(ans, res);
    }
};

int main() {
    // 示例，创建Cmd对象并调用Solution的方法
    std::vector<Cmd> cmds = {Cmd(0, 500, 20), Cmd(0, 1000, 15), Cmd(0, 100, 20), Cmd(1, 500, 14), Cmd(1, 600, 15), Cmd(0, 1000, 10),
    Cmd(1, 500, 20), Cmd(0, 600, 20), Cmd(1, 600, 15), Cmd(1, 500, 20), Cmd(0, 600, 20) };
    Solution solution;
    int result = solution.calcTotalCycles(cmds);

    std::cout << "Total Cycles: " << result << std::endl;

    return 0;
}