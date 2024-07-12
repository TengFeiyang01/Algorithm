#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct info{
	int r;
	char c;
};

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<int, info> interval;
    std::multiset<int> pq;

    std::map<int, std::set<int>> b;

    std::map<int, int> left, right;

    int i = 0, j = 0;
    while (i < n) {
    	j = i + 1;
    	while (j < n and s[j] == s[i]) {
    		j++;
    	}
    	interval[i] = {j - 1, s[i]};

    	b[j - i].insert(i);
    	left[i] = j - 1;
    	right[j - 1] = i;

    	pq.insert(j - i);

   		i = j;
    }
    int ans = 0;
    while (pq.size()) {
    	ans++;
    	int x = *pq.rbegin();
    	pq.erase(pq.find(x));
    	int cur = *b[x].begin();
    	b[x].erase(cur);
    	
    	int nl = interval[cur].r + 1, nr;
    	if (nl < n) {
	    	nr = left[nl];
    	} else {
    		continue;
    	}

    	if (!cur) {
    		continue;
    	}

    	int pr = cur - 1;
    	int pl = right[pr];
    	int curlen = right[cur] - cur + 1;

    	if (nl < n and cur) {
    		char pc = interval[pl].c;
    		char nc = interval[nl].c;
    		int prelen = pr - pl + 1;
    		int nextlen = nr - nl + 1;

    		if (pc == nc) {
    			b[prelen].erase(pl);
    			b[nextlen].erase(nl);
    			pq.erase(pq.find(prelen));
    			pq.erase(pq.find(nextlen));
    			interval[pl] = {nr, pc};

    			b[prelen + nextlen].insert(pl);
    			pq.insert(nextlen + prelen);

    			left[pl] = nr;
    			right[nr] = pl;
    			
    		}
    	}
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
