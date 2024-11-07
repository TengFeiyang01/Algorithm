#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n, int x, const vector<int>& d) {
    long long coin_sum = 0;  // 当前金币数
    int left_idx = 0, left_num = 1;  // 左边界
    int right_idx = 0, right_num = 1;  // 右边界

    // 一、 扩大窗口到 x
    int window = 0;
    while (window < x && right_idx < n) {
        if (right_num == 1 && window + d[right_idx] <= x) {
            coin_sum += (1 + d[right_idx]) * d[right_idx] / 2;
            window += d[right_idx];
            right_idx++;
        } else {   // 按天进行右移右指针
            if (right_num <= d[right_idx]) {
                coin_sum += right_num;
                window++;
                right_num++;
            }

            if (right_num > d[right_idx]) {  // 当前月已过，跳到下个月
                right_idx++;
                right_num = 1;
            }
        }
    }

    // 二、保持窗口(同时左右指针右移动)，尝试将最大金币数记录下来
    long long max_coin = coin_sum;  // 最大金币数
    while (right_idx < n) {
        int left_step = d[left_idx] - left_num + 1;     // 左指针可以移动的步数
        int right_step = d[right_idx] - right_num + 1;  // 右指针可以移动的步数

        int step = min(left_step, right_step);  // 取最小步数
        // 总金币变化 = 右侧增加的金币 - 左侧减少的金币
        coin_sum += (right_num - left_num) * step;
        max_coin = max(max_coin, coin_sum);
        
        // 窗口向右移动 step
        left_num += step;
        right_num += step;

        if (left_num > d[left_idx]) {  // 当前月已过，跳到下个月
            left_idx++;
            left_num = 1;
        }
        if (right_num > d[right_idx]) {  // 当前月已过，跳到下个月
            right_idx++;
            right_num = 1;
        }
    }

    return static_cast<int>(max_coin);
}

int main() {
    // 一年中的月数和连续登陆的天数
    int n, x;
    cin >> n >> x;
    // 每月份的天数[]]