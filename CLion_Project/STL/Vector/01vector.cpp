#include <iostream>
#include <vector>

//capacity >= size
//resize 改变size的大小 capacity只会变大
//当capacity>=size时 shrink_to_fit()使得capacity==size

//预留空间 reserve

int main() {
/*    std::vector<int> vi;
    vi.reserve(16);
    for (int i = 0 ; i < 10; ++i) {
        vi.push_back(i);
        std::cout << "capacity: " << vi.capacity() << "\n";  //realloc()
        std::cout << "size: " << vi.size() << "\n";  //realloc()
    }

    //砍掉多余的空间
    vi.shrink_to_fit();
    std::cout << "capacity: " << vi.capacity() << "\n";  //realloc()*/

    std::vector vi{1, 2, 3, 4, 5};
    std::cout << vi.capacity() << std::endl;
    vi.resize(10);
    std::cout << vi.capacity() << std::endl;
    vi.resize(1);
    //capacity只会增大不会减少
    std::cout << vi.capacity() << std::endl;


    return 0;
}
