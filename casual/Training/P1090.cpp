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
#define all(x) bg(x), end(x)
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

int heap[N], len;

void push(int x) {
	heap[++len] = x;
	int i = len;
	while (i > 1 && heap[i] < heap[i / 2]) {
		std::swap(heap[i], heap[i / 2]);
		i >>= 1;
	}
}

void pop() {
	heap[1] = heap[len--];
	int i = 1;
	while (i * 2 <= len) {
		int son = 2 * i;
		if (son < len && heap[son + 1] < heap[son]) {
			son++;
		}
		if (heap[son] < heap[i]) {
			std::swap(heap[i], heap[son]);
			i = son;
		} else break;
	}
}

inline int top() { return heap[1]; }

void solve() {
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	push(x);
    }
    int ans = 0;
    while (len > 1) {
    	int a = top();
    	pop();
    	int b = top();
    	pop();
    	push(a + b);
    	ans += a + b;

    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
