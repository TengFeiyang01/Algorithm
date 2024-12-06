#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    string s;
    int n, q;
    std::cin >> n >> q;
    cin >> s;
    set<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        st.insert(make_pair(i + 1, i));
    }
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
    }
    return 0;
}