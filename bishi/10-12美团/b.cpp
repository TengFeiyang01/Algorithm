#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 比较函数，用于按降序排列字符串形式的大数字
bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() > b.length(); // 长度不同时，长度大的数字大
    }
    return a > b; // 长度相同时，按字典序比较
}

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    
    int n = s.length();
    vector<string> a;
    int i = 0, j = 0;

    // 解析字符串，提取数字
    while (i < n) {
        if (isdigit(s[i])) {
            j = i;
            while (j < n && isdigit(s[j])) {
                j++;
            }
            // 将提取的数字（以字符串形式）加入数组
            a.push_back(s.substr(i, j - i));
            i = j;
        } else {
            i++;
        }
    }

    // 按降序排序
    sort(a.begin(), a.end(), compare);

    // 输出第k大的数字，或者"N"如果没有k个数字
    if (a.size() >= k) {
        cout << a[k - 1] << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}
