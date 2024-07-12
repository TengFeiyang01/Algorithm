class Solution {
    static const int mod = 1000000007;
public:
    int getMethod(ListNode* head, string color) {
        ListNode* temp = head;
        int i = 0;
        int j = 1;
        int sum = 0;
        vector<int> arr(100005);
        while (temp != nullptr) {
            int ft = temp->val;
            if (color[i] == 'R') {
                sum += ft;
                sum %= 2;
            } else {
                arr[j] = ft;
                j++;
            }
            temp = temp->next;
            i++;
        }
        // j 代表节点个数
        // ans[i][j] 填到表示j个数 总和是奇/偶数的方案
        vector<vector<int>> ans(100005, vector<int>(2));
        // 不填显然是0 方案是1
        ans[0][0] = 1;
        ans[0][1] = 0;
        for (int x = 1; x < j; x++) {
            if (arr[x] % 2 == 1) {
                // 当前是奇数 
                ans[x][0] = (ans[x - 1][1] + ans[x - 1][0]) % mod; // 和前i-1个凑出奇数的加起来 凑偶数
                ans[x][1] = (ans[x - 1][1] + ans[x - 1][0]) % mod; // 和前i-1个凑出偶数的加起来 凑奇数
            } else {
                // 偶数
                ans[x][0] = (2 * ans[x - 1][0]) % mod;
                ans[x][1] = (2 * ans[x - 1][1]) % mod;
            }
        }
        return ans[j - 1][sum % 2]; 
    }
};
