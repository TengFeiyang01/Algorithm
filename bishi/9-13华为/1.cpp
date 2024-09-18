#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

long long parse(const vector<string>& cmds, int s, int e) {
    if (s > e) return 0;
    if (cmds[s] == "F0") {
        return 4 + parse(cmds, s + 5, e);
    } else if (cmds[s] == "F1") {
        int cnt = stoi(cmds[s + 1], nullptr, 16);
        int len = stoi(cmds[s + 2] + cmds[s + 3] + cmds[s + 4] + cmds[s + 5], nullptr, 16);
        long long acc = parse(cmds, s + 6, s + 6 + len - 1) * cnt;
        return acc + parse(cmds, s + 6 + len, e);
    } else {
    	throw runtime_error("IVV");
    }
}

int main() {
    string line;
    getline(cin, line);
    
    line = line.substr(line.find_first_not_of(" "), line.find_last_not_of(" ") + 1); // trim
    
    if (line.empty()) {
        cout << -1 << endl;
    } else {
        vector<string> lines;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            lines.push_back(word);
        }

        try {
            long long res = parse(lines, 0, lines.size() - 1);
            cout << res << endl;
        } catch (...) {
            cout << -1 << endl;
        }
    }

    return 0;
}
