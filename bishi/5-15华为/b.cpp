#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

using namespace std;
 string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '(') {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } else {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "(") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }


 int strStr(string haystack, string needle) {
        // 构建next数组
        int next[needle.size()];
        next[0] = -1;
        if (needle.size() > 1)  next[1] = 0;
        int i = 1,  j = 0;
        while(i < needle.size()-1){
            if(needle[i] == needle[j]){
                next[++i] = ++j;
            }
            else{
                j = next[j];
                if(j == -1){
                    next[++i] = 0;
                    j = 0;
                }
            }
        }
        // 匹配字符串(i为主串，j为模式串)
        i = 0, j = 0;
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++;
                if(++j == needle.size())
                    return i - needle.size();
            }
            else{
                j = next[j];
                if(j == -1){
                    i++;
                    j = 0;
                }
            }
        }
        return -1;
    }


void solve() {
    std::string s, t;
    std::cin >> t >> s;
    auto original = s;
          t = decodeString(t);
          for (auto &c : t) {
                  if (c == 'A') {
                          c = '1';
                  } else {
                          c = '0';
                  }
          }
          for (auto &c : s) {
                  if (isalpha(c)) {
                          c = '1';
                  } else {
                          c = '0';
                  }
          }

          int j = strStr(s, t);
          if (j == -1) {
                  std::cout << "!\n";
                  return;
          } else {
                  int n = t.size();
                  std::cout << original.substr(j, n) << "\n";
          }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
