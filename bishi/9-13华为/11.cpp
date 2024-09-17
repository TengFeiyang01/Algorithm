#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

void solve() {
    auto parse = [](const vector<string>& cmds, int s, int e, auto& parse_ref) -> long long {
        if (s > e) return 0;
        if (cmds[s] == "F0") {
            return 4 + parse_ref(cmds, s + 5, e, parse_ref);
        } else if (cmds[s] == "F1") {
            int cnt = stoi(cmds[s + 1], nullptr, 16);
            int len = stoi(cmds[s + 2] + cmds[s + 3] + cmds[s + 4] + cmds[s + 5], nullptr, 16);
            long long acc = parse_ref(cmds, s + 6, s + 6 + len - 1, parse_ref) * cnt;
            return acc + parse_ref(cmds, s + 6 + len, e, parse_ref);
        } else {
            throw runtime_error("Invalid command");
        }
    };

    string line;
    getline(cin, line);

    line.erase(0, line.find_first_not_of(" \t\n\r"));
    line.erase(line.find_last_not_of(" \t\n\r") + 1);

    if (line.empty()) {
        cout << 0 << endl;
    } else {
        vector<string> cmds;
        stringstream ss(line);
        string cmd;
        while (ss >> cmd) {
            cmds.push_back(cmd);
        }

        try {
            long long result = parse(cmds, 0, cmds.size() - 1, parse);
            cout << result << endl;
        } catch (const exception& e) {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
