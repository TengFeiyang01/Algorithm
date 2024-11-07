#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int getDiffCharNum(const string& str) {
    unordered_set<char> charSet;
    for (char c : str) {
        charSet.insert(c);
    }
    return charSet.size();
}

vector<string> splitValidStrings(string s1) {
    vector<string> result;
    string currentSubstring;

    for (char c : s1) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')) {
            if (!currentSubstring.empty()) {
                result.push_back(currentSubstring);
                currentSubstring.clear();
            }
        } else {
            currentSubstring += c;
        }
    }

    if (!currentSubstring.empty()) {
        result.push_back(currentSubstring);
    }

    return result;
}

string getResult(const string& s1, const string& s2) {
    vector<string> validStrings = splitValidStrings(s1);
    int cnts2 = getDiffCharNum(s2);

    int maxDiffCharNum = -1;
    string validResultStr = "Not Found";

    for (const string& validString : validStrings) {
        if (validString.empty()) {
            continue;
        }

        int diffCharNum = getDiffCharNum(validString);

        if (diffCharNum > cnts2) {
            continue;
        }

        if (diffCharNum > maxDiffCharNum) {
            maxDiffCharNum = diffCharNum;
            validResultStr = validString;
        } else if (diffCharNum == maxDiffCharNum && validString > validResultStr) {
            validResultStr = validString;
        }
    }

    return validResultStr;
}


int main() {
    
	std::string s1, s2;
	std::cin >> s1 >> s2;
    string result = getResult(s1, s2);
    cout << result << endl; 

    return 0;
}
