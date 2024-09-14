#include <iostream>
#include <vector>
#include <stack>
#include <map>

using i64 = long long;  
const int P = 13331;

int main() {
    int n;
    std::cin >> n;
    std::map<i64, int> mp;           
    std::stack<std::string> st;      
    std::vector<i64> h(1, 0);      
    int cnt = 0;                  

    for (int i = 0; i < n; ++i) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "push") {
            std::string k;
            std::cin >> k;
            st.push(k);
            for (char ch : k) {
                ++cnt;  
                i64 new_hash = h[cnt - 1] * P + ch;
                h.push_back(new_hash);
            }
            ++mp[h[cnt]];  
        } else if (cmd == "pop" && !st.empty()) {
            std::string k = st.top();
            st.pop();
            cnt -=int(k.size());
        }
    }
    
    std::cout << mp.size() << std::endl; 
    return 0;
}
