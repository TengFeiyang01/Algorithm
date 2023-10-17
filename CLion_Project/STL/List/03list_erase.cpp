#include <bits/stdc++.h>

void print(auto const &seq) {
    for (auto const &elem: seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::list<int> li{1, 3, 5, 7, 4, 9, 4};
    std::list<int> li2{2, 4, 6, 8};
    auto it = li.begin();
    std::advance(it, 2);

//    li.erase(li.begin(), it);
//    li.erase(li.begin(), ++li.begin());
//    print(li);

/*    li.remove_if([](int x){return x % 2;});
    print(li);*/
    li.unique();    //去重
    print(li);
    li.sort([](int x, int y){return y < x;});
    print(li);

    //moveli2到li1 的pos位置O（1）
//    li.splice(li.begin(), li2);
//    li.splice(li.end(), li2, li2.begin());  //li2的begin 放在li的pos
/*    li.splice(it, li2, li2.begin(), li2.end());  //再li的it位置之后 插入li2的范围
    print(li);
    print(li2);*/

//    li.merge(li2);
    li.sort();
    li2.merge(li);  //归并
    print(li2);

    return 0;
}
