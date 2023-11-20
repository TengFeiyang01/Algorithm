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
const int N = 1e6 + 13;

int heap[N], len = 0;

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
		int son = i * 2;
		if (son < len && heap[son + 1] < heap[son]) {
			son++;
		}
		if (heap[i] > heap[son]) {
			std::swap(heap[i], heap[son]);
			i = son;
		} else break;
	}
}

void solve() {
	int n, op, x;
	std::cin >> n;
	while (n--) {
		std::cin >> op;
		if (op == 1) {
			std::cin >> x;
			push(x);
		} else if (op == 2) {
			std::cout << heap[1] << "\n";
		} else pop();
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
