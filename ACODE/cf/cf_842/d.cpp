#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

int cnt(std::vector<int> a, int &f)
{
    std::vector<int>tmp=a;//排序后的数组
    std::map<int,int>mp;
    int ans=0;
    std::sort(tmp.begin(),tmp.end());
    for(int i=0; i<tmp.size(); i++)
        mp[tmp[i]]=i;//记录每个对应的正确位置
    for(int i=0; i<a.size(); i++)
        while(i!=mp[a[i]])
        {
            if (std::abs(i - mp[a[i]]) == 1) f = 1;
            ans++;
            std::swap(a[i],a[mp[a[i]]]);
        }
        
    return ans;
}

void solve() {
    std::cin >> n;
    std::vector<int> v;
    int f = 0;
    for (int i = 1; i <= n; ++i) std::cin >> m, v.push_back(m);
    std::cout << cnt(v, f) + (f == 1 ? -1 : 1) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
