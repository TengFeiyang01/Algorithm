#include <iostream>
#include <string>
#include <map>

int main(void) {
    std::map<int, std::string> m{
            {1, "lucy"},
            {2, "lily"},
            {3, "tom"}
    };

    for (auto &item: m) {
        // item.first 是一个常量
//        std::cout << "id: " << item.first++ << ", name: " << item.second << std::endl;  // error
    }

    return 0;
}

