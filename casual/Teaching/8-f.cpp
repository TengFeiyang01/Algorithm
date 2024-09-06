#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using namespace std;
/*
为了净化网络环境，需要开发一个简易的敏感词屏蔽功能：给定敏感词，按如下规则对待检字符串进行匹配和替换：
敏感词中的各个字符顺序地出现在待检查字符串中，[且第一个字符和最后一个字符之间的其他字符个数小于敏感词长度]，从其他字符一起替换为星号＊。如敏感词135可匹配字符串1?3?5、1??35，不匹配1?3??5
支持[贪婪匹配]，在每次b从左到右扫描，一旦遇到可匹配的情况就开始进行匹配，且匹配尽可能长的字符，例如
敏感词为ab时，字符串abbc应替换为*c，而不是*bc
敏感词为abc时，字符串aabcbc应该替换为*bc，而不是a*（遇到首个a时就开始进行匹配）
支持全量匹配，即：有多处符合匹配规则时，则需要全部进行匹配和替换
请输出屏蔽后的字符串

x
x+x-2

输入
第一行字符串：表示待检查字符串，仅含英文字母和数字，长度范围[2，20]
第二行字符串：表示敏感词，长度范围[2，20]
输出
屏蔽后的字符串

样例1
输入
ABCdfgABC
ABC
输出
*dfg*

样例2
输入
abbdefghjjk
bdfhj
输出
a*k

样例3
输入
abbbbbcde
abc
输出
abbbbbcde
*/

// b [b d e f g h j] j
// b dfhj    j
//   4
///
bool check(string &checkSub, string &senSub) {
    int j = 0;
    for (int i = 0; i < checkSub.size(); i++) {
        if (checkSub[i] == senSub[j]) {
            j++;
        }
    }
    if (j == senSub.size()) {
        return true;
    }
    return false;
}

/*
    4e8

    n*n*n

    a[bbdefghjjk
    bdfhj

    a

*/
string GetMaskedStr(const string &checkedStr, const string &sensitiveStr) {
    string ans;
    int n = sensitiveStr.size();
   
    char f = sensitiveStr[0];
    char e = sensitiveStr[n - 1];


    string senSub = sensitiveStr.substr(1, n - 2);
    int m = checkedStr.size();
    
    for (int i = 0; i < m; ) { 
        if (checkedStr[i] == f) { // 匹配敏感词首
            bool endFit = false;
            // [且第一个字符和最后一个字符之间的其他字符个数小于敏感词长度]
            // n| [i, i + (n-1) + (n-2) + 1
            // 敏感词长度 n
            // (n-1): 其他字符
            // (n-2): 敏感词除去首位的长度
            // 1 末尾长度
            // [i, i+(n-1)*2]
            //[i, i+n-1]
            for (int j = min(m - 1, i + (n - 1) * 2); j >= min(m - 1, i + (n - 1)); j--) {
                //f[***]e
                string subCheck = checkedStr.substr(i + 1, j - (i + 1));
                // [l, r]
                // l-r+1
                // l-r-1
                // (]
                // l-r

                if (checkedStr[j] == e && check(subCheck, senSub)) { //尾部匹配并且中间部分也匹配
                    // [i, j]
                    i = j + 1;
                    ans += '*';
                    endFit = true;
                    break;
                }
            }
            if (!endFit) {
                ans += checkedStr[i];
                i++;
            }
        } else {
            ans += checkedStr[i];
            i++;
        }
    }
    return ans;
}
                    

void solve() {
    std::string s, p;
    std::cin >> s >> p;
    std::string res;
    std::cout << GetMaskedStr(s, p);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
