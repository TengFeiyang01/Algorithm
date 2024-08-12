#include <bits/stdc++.h>

using i64 = long long;

	

using namespace std;

std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

const int inf = 0x3f3f3f3f;
int cardPackets(vector<int> cardTypes) {
	int ans = inf;
	sieve(501);
	for (int p : primes) {
		int res = 0;
		for (int x : cardTypes) {
			res += (p - x % p) % p;
		}
		ans = min(ans, res);
	}
	return ans;
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::cout << cardPackets(a) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
