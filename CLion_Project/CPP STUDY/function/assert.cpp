#include <iostream>
#include <vector>
#include <cassert>
//assert是一个预处理宏

void print(const std::vector<int> &arr) {
    //assert(expr) 若expr为假， assert输出信息并且终止程序
    assert(!arr.empty());
    std::cout << "arr: " << std::endl;
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " \n"[i == arr.size() - 1];
}

int main() {
    std::vector a{1, 2, 3};
    std::vector<int> b;
    print(a);
    print(b);

    return 0;
}
