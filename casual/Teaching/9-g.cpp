#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_set>

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

class Solution {
public:
    // 将MAC地址标准化，转换为统一的小写并使用'-'作为分隔符
    std::string normalizeMac(const std::string& mac) {
        std::string normalized = mac;
        // 将分隔符统一替换为'-'
        // 可以修改这段代码
        for (int i = 2; i < 17; i += 3) {
            normalized[i] = '-';
        }
//        std::replace(normalized.begin(), normalized.end(), ':', '-');
        // 将所有字符转换为小写
//        std::transform(normalized.begin(), normalized.end(), normalized.begin(), ::tolower);
        for (int i = 0; i < 17; ++i) {
//            if (isalpha(normalized[i])) {
//                normalized[i] = tolower(normalized[i]);
//            }

            if ('A' <= normalized[i] and normalized[i] <= 'Z') {
                normalized[i] += 32;
            }
        }
        return normalized;
    }

    // abcdef len=3
    // abc
    // bcd
    // cde
    // def

    // 012345678
    // xx-xx-xx-..
    // xx:xx:xx:..
    // 12+5=17

    // 判断一个字符串是否为有效的MAC地址
    bool isValidMac(const std::string& mac) {
        if (mac.length() != 17) return false;

        char separator = mac[2];
        if (separator != '-' && separator != ':') return false;

        for (int i = 0; i < 17; i++) {
            if (i % 3 == 2) {
                // xx-x- x x
                // xx-xx : x
                if (mac[i] != separator) return false;  // 分隔符必须一致
            } else {
                if (!isHex(mac[i])) return false;  // 非分隔符字符必须是十六进制数
            }
        }
        return true;
    }
    // ABCDEFG
    // ABC
    // BCD
    // CDE

    int GetMacNum(std::string& ins) {
        std::unordered_set<std::string> macAddresses;
        std::string mac;
        // O(17*n)
        // (n-17+1)*(17)
        for (int i = 0; i + 17 <= ins.size(); i++) {
            mac = ins.substr(i, 17);
            if (isValidMac(mac)) {
               macAddresses.insert(normalizeMac(mac));
                // macAddresses.insert(mac);
            }
        }
        // print(macAddresses);
        return macAddresses.size();
    }

private:
    bool isHex(char ch) {
        return isalnum(ch);
//        return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
    }
};


int main() {
    std::string instr;
    std::cin >> instr;
    Solution solu;
    int res = solu.GetMacNum(instr);
    std::cout << res << std::endl;
    return 0;
}
