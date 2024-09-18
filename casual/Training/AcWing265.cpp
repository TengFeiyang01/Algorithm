#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct node {
	int l, r;
	int key, val;
	int cnt, size;
}tr[N];

int root, idx = 0;

void pushup(int p) {
	tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_Node(int key) {
	tr[++idx].key = key;
	tr[idx].val = rand();
	tr[idx].cnt = tr[idx].size = 1;
	return idx; 
}

void zig(int &p) {
	int q = tr[p].l;
	tr[p].l = tr[q].r;
	tr[q].r = p;
	p = q;
	pushup(tr[p].r);
	pushup(p);
}

void zag(int &p) {
	int q = tr[p].r;
	tr[p].r = tr[q].l;
	tr[q].l = p;
	p = q;
	pushup(tr[p].l);
	pushup(p);
}

void build() {
	get_Node(-inf);
	get_Node(inf);
	root = 1;
	tr[1].r = 2;
	pushup(root);
	if (tr[1].val < tr[2].val) zag(root);
}


void insert(int &p, int key) {
	if (!p) {
		p = get_Node(key);
	} else if (tr[p].key == key) {
		tr[p].cnt += 1;
	} else if (tr[p].key > key) {
		insert(tr[p].l, key);
		if (tr[tr[p].l].val > tr[p].val) {
			zig(p);
		}
	} else if (tr[p].key < key) {
		insert(tr[p].r, key);
		if (tr[tr[p].r].val > tr[p].val) {
			zag(p);
		}
	}
	pushup(p);
}

void remove(int &p, int key) {
	if (!p) return;
	if (tr[p].key == key) {
		if (tr[p].cnt > 1) {
			tr[p].cnt -= 1;
		} else if (tr[p].l or tr[p].r) {
			if (!tr[p].r or tr[tr[p].l].val > tr[tr[p].r].val) {
				zig(p);
				remove(tr[p].r, key);
			} else {
				zag(p);
				remove(tr[p].l, key);
			}
		} else { 
			p = 0;
		}
	} else if (tr[p].key > key) {
		remove(tr[p].l, key);
	} else {
		remove(tr[p].r, key);
	}
	pushup(p);
}

int get_rank_by_key(int p, int key) {
	if (!p) return 0;  //一般不会发生
	if (tr[p].key == key) {
		return tr[tr[p].l].size + 1;
	} else if (tr[p].key > key) {
		return get_rank_by_key(tr[p].l, key);
	} else {
		return get_rank_by_key(tr[p].r, key) + tr[tr[p].l].size + tr[p].cnt;
	}
}

int get_rank_by_key(int x) {
	return get_rank_by_key(root, x) - 1;
}

int get_key_by_rank(int p, int rank) {
	if (!p) return inf;  //一般不会发生
	if (rank <= tr[tr[p].l].size) {
		return get_key_by_rank(tr[p].l, rank);
	} else if (tr[tr[p].l].size + tr[p].cnt >= rank) {
		return tr[p].key;
	} else if (tr[tr[p].l].size + tr[p].cnt < rank) {
		return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
	} 
}

int get_key_by_rank(int x) {
	return get_key_by_rank(root, x + 1);
}

int get_pre(int p, int key) {
	if (!p) return -inf;
	if (tr[p].cnt >= 1 and tr[p].key == key) return key;
	if (tr[p].key >= key) return get_pre(tr[p].l, key);
	return std::max(tr[p].key, get_pre(tr[p].r, key));
}

int get_next(int p, int key) {
	if (!p) return inf;
	if (tr[p].cnt >= 1 and tr[p].key == key) return key;
	if (tr[p].key <= key) return get_next(tr[p].r, key);
	return std::min(tr[p].key, get_next(tr[p].l, key));
}

void solve() {
    int n, x;
    std::cin >> n;
    build();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	if (i) {
			ans += std::min(abs(get_pre(root, x) - x), abs(get_next(root, x) - x));
    	} else {
    		ans += x;
    	}
    	insert(root, x);
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
