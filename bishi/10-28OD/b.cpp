#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int parseStr(const string& s) {
    int h = 0, m = 0, sec = 0, ms = 0;
    int i = 0;

    while (i < s.size() && s[i] != ':') {
        h = h * 10 + (s[i] - '0');
        i++;
    }
    i++; 
    while (i < s.size() && s[i] != ':') {
        m = m * 10 + (s[i] - '0');
        i++;
    }
    i++; 
    while (i < s.size() && s[i] != '.') {
        sec = sec * 10 + (s[i] - '0');
        i++;
    }
    i++;  
    while (i < s.size()) {
        ms = ms * 10 + (s[i] - '0');
        i++;
    }

    return h * 3600000 + m * 60000 + sec * 1000 + ms;
}

int main() {
    int n;
    cin >> n; 

    vector<string> res(n);

    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }

    sort(res.begin(), res.end(), [](const string& a, const string& b) {
        return parseStr(a) < parseStr(b);
    });

    for (const auto& timeStr : res) {
        cout << timeStr << endl;
    }

    return 0;
}
