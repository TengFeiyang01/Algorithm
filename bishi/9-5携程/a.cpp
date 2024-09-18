#include <bits/stdc++.h>

using namespace std;

vector<int> digits;
int dp[20][2][2];

// 数位DP的递归函数
int dfs(int pos, bool isLimit, bool isNum, int n, int m) {
    if (pos == m) return isNum;  // 如果已经构成m位数且是有效数，返回1
    if (dp[pos][isLimit][isNum] != -1) return dp[pos][isLimit][isNum];
    
    int res = 0;
    int down = isNum ? 0 : 1; // 下界：如果已经开始构建数字，最低可以是0，否则避免前导零从1开始
    int up = isLimit ? digits[pos] : n; // 上界：如果受限，则当前位最大值为digits[pos]，否则为n
    
    // 遍历当前位可以取的所有数值
    for (int i = down; i <= up; i++) {
        res += dfs(pos + 1, isLimit && (i == up), isNum || (i != 0), n, m);
    }

    return dp[pos][isLimit][isNum] = res;
}

// 处理主问题的函数
int solve(int n, int m, int k) {
    digits.clear();
    
    // 将k分解为各个位数存入digits数组
    while (k > 0) {
        digits.push_back(k % 10);
        k /= 10;
    }
    
    // 如果k的位数不足m位，用0补足
    while (digits.size() < m) digits.push_back(0);
    
    // 反转digits数组，使其从高位到低位排列
    reverse(digits.begin(), digits.end());

    memset(dp, -1, sizeof(dp));  // 初始化dp数组
    return dfs(0, true, false, n, m);  // 从第0位开始，初始时受限且尚未形成数字
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int result = solve(n, m, k);
    cout << result << endl;

    return 0;
}
