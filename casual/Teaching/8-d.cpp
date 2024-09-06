#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

std::string hexCharToBinary(char hexChar) {
    switch (toupper(hexChar)) {
        case '0':
            return "0000";
        case '1':
            return "0001";
        case '2':
            return "0010";
        case '3':
            return "0011";
        case '4':
            return "0100";
        case '5':
            return "0101";
        case '6':
            return "0110";
        case '7':
            return "0111";
        case '8':
            return "1000";
        case '9':
            return "1001";
        case 'A':
            return "1010";
        case 'B':
            return "1011";
        case 'C':
            return "1100";
        case 'D':
            return "1101";
        case 'E':
            return "1110";
        case 'F':
            return "1111";
        default:
            return ""; // Invalid hex character
    }
}


void solve() {
    std::string t, s;
    std::cin >> t;
    for (auto c: t) {
        s += hexCharToBinary(c);
    }
    std::cout << s << "\n";
    i64 n = s.size(), ans = 0;
    bool ok = true;

    std::cout << s << "\n";
    if (s[0] == '0') {
        if (n != 8) {
            ok = false;
        } else {
            for (int i = 1; i < n; ++i) {
                ans = ans * 2 + (s[i] - '0');
            }
            //101
            //1
            //2+0=2
            //2*2+1=5
        }
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            break;
        }
        cnt++;
    }
    if (cnt * 8 != n) {
        ok = false;
        return;
    }

    // 判断后续是否合法
    for (int i = 8; i < n; i += 8) {
        if (s[i] != '1' or s[i + 1] != '0') {
            ok = false;
        }
    }
    // 计算前8位
    for (int i = cnt + 1; i < 8; ++i) {
        ans = ans * 2 + (s[i] - '0');
    }

    // 计算后续有效位
    for (int i = 10; i < n; i += 8) {
        for (int j = 0; j < 6; ++j) {
            ans = ans * 2 + (s[i + j] - '0');
        }
    }
    if (!ok) ans = -1;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
