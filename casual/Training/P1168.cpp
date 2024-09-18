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
#include <stack>
#include <numeric>
#include <cmath>

/*
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
*/


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
	使用两个堆，大根堆维护较小的值，小根堆维护较大的值

	即小根堆的堆顶是较大的数中最小的，大根堆的堆顶是较小的数中最大的
	
	将大于大根堆堆顶的数（比所有大根堆中的元素都大）的数放入小根堆.
	小于等于大根堆堆顶的数（比所有小根堆中的元素都小）的数放入大根堆
	
	那么就保证了所有大根堆中的元素都小于小根堆中的元素

	于是我们发现对于大根堆的堆顶元素，有【小根堆的元素个数】个元素比该元素大，【大根堆的元素个数-1】个元素比该元素小；

	同理，对于小跟堆的堆顶元素，有【大根堆的元素个数】个元素比该元素小，【小根堆的元素个数-1】个元素比该元素大；
*/

void solve() {
    int n, x;
    std::cin >> n;
   	std::priority_queue<int> pq1;
   	std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;
/*   	std::vector<int> a;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> x;
    	a.insert(lb(all(a), x), x);
    	if (i % 2) std::cout << a[i / 2] << "\n";
    }
*/
   	int mid = 0;
   	std::cin >> x;
   	pq1.push(x);
   	std::cout << x << "\n";
   	for (int i = 2; i <= n; ++i) {
   		std::cin >> x;
   		if (x > pq1.top()) pq2.push(x);
   		else pq1.push(x);
   		while (std::abs(sz(pq1) - sz(pq2)) > 1) {
   			if (sz(pq1) > sz(pq2)) {
   				pq2.push(pq1.top());
   				pq1.pop();
   			} else {
   				pq1.push(pq2.top());
   				pq2.pop();
   			}
   		}
   		if (i % 2) {
   			if (sz(pq1) > sz(pq2)) std::cout << pq1.top() << "\n";
   			else std::cout << pq2.top() << "\n";
   		}
   	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
