#include <bits/stdc++.h>
#include "../Struct/myList.h"

int main() {
    List l{};
    l.init();

    for (int i = 0; i < 20; ++i) {
        l.insert(i);
    }

    l.traverse();
    Node* x = l.search(5);
    std::cout << x->d << "\n";

    l.destory();
    l.traverse();

    return 0;
}
