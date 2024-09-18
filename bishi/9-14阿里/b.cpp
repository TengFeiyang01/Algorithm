#include <iostream>
#include <vector>

using namespace std;

void spiralOrder(vector<vector<int>>& matrix, std::vector<int> &result) {

    if (matrix.empty() || matrix[0].empty()) return;

    int m = matrix.size();    // 行数
    int n = matrix[0].size(); // 列数

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // 从左到下
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][left]);
        }
        left++;

        if (left > right) break;

        // 从下到右
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;

        if (top > bottom) break;

        // 从右到上
        for (int i = bottom; i >= top; i--) {
            result.push_back(matrix[i][right]);
        }
        right--;

        if (left > right) break;

        // 从上到左
        for (int i = right; i >= left; i--) {
            result.push_back(matrix[top][i]);
        }
        top++;
    }

    return;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> re;
    spiralOrder(matrix, re);

    for (int num : re) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
