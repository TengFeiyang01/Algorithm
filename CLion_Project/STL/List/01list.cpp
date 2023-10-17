#include <bits/stdc++.h>

void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    //双向链表
    std::list<int> li = {13, 1, 3, 4, 5, 6, 7, 9, 8};

    std::cout << li.front() << " " << li.back() << std::endl;

//    li.push_front(15);

//    li.sort();
//    li.pop_front();

//    print(li);
//    li.insert(li.begin(), 4, 2);

    li.insert(li.begin(), {1, 2, 3, 4, 5});
    print(li);

    return 0;
}
