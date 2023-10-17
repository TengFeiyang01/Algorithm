#include <bits/stdc++.h>

int main() {
    int *m;
    int n;

    m = reinterpret_cast<int*> (n);
//    n = reinterpret_cast<int> (m);

    int arr[5] = {1, 2, 3, 4, 5};

//    std::cout << std::hex << *((int*)((int)arr+1));

    std::cout << std::hex << *(reinterpret_cast<int*>(reinterpret_cast<int>(arr) + 1) + 1);

    return 0;
}
