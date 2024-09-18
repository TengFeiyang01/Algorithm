#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d;
    cin >> d; // 读取项数

    vector<long long> a(d + 1); // 创建一个足够大的向量存储序列值

    // 计算序列的每一项
    for (int n = 1; n <= d; ++n) {
        if (n % 2 == 0) { // n 是偶数
            a[n] = 2 * (n / 2) * (n / 2) + (n / 2) + 1; // 使用给定的公式计算偶数项
        } else { // n 是奇数
            a[n] = 2 * (n / 2 + 1) * (n / 2 + 1); // 使用给定的公式计算奇数项
        }
    }

    return 0;
}
