#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

bool isWhitelisted(const std::set<std::string>& whitelist, const std::string& phoneNumber) {
    for (const auto& entry : whitelist) {
        if (entry.back() == '*') { 
            std::string prefix = entry.substr(0, entry.size() - 1);
            // 123456*
            // 123456789
            if (phoneNumber.substr(0, prefix.size()) == prefix) {
                return true;
            }
        } else {
            if (phoneNumber == entry) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;

    std::set<std::string> whitelist;

    std::unordered_map<std::string, std::pair<int, int>> callStats;
    
    std::vector<std::string> callOrder;

    for (int i = 0; i < n; ++i) {
    	std::string type, number;
    	std::cin >> type >> number;

        if (type == "W") {
            whitelist.insert(number);
        } else if (type == "C") {
            // 初始化
            if (!callStats.count(number)) {
                callStats[number] = {0, 0};
                callOrder.push_back(number);
            }

            if (isWhitelisted(whitelist, number)) {
                callStats[number].first++;
            } else {
                callStats[number].second++; 
            }
        }
    }

    for (const auto& number : callOrder) {
        std::cout << number << " " << callStats[number].first << " " << callStats[number].second << std::endl;
    }

    return 0;
}


/*
7
C 13300000000 [0, 1]  [] 
W 13144444444         [13144444444]
C 13144444444         [13144444444]
C 03712832444 [0, 1]  [13144444444]
C 03712832233 [0, 1]  [13144444444]
W 03712832*           [13144444444, 03712832*]
C 03712832444   
  [03712832]*


  12334 12335 23455 2353
*/