#include <bits/stdc++.h>

using namespace std;
#define maxn 100005

#define ll long long
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define g(x) (x - (ll)(sqrt(x)))

int n, q, a[100005], b[100005], c[100005];

struct node{
    int l,r,val,lazy;
}tree[maxn*4];

int read()
{
	int x = 0, fl = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') fl = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
	return x * fl;
}
void pushup(int x){
    tree[x].val=max(tree[x<<1].val+tree[x<<1].lazy,tree[x<<1|1].val+tree[x<<1|1].lazy);
    return;
}
void pushdown(int root){
    if(tree[root].lazy){
        tree[root<<1].lazy+=tree[root].lazy;
        tree[root<<1|1].lazy+=tree[root].lazy;
        tree[root].lazy=0;
    }
}
void build(int root,int l,int r){
    tree[root].l=l;
    tree[root].r=r;
    tree[root].lazy=0;
    if(tree[root].l==tree[root].r){
        tree[root].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    pushup(root);
}
void update(int root,int tl,int tr,int c){ //区间(tl,tr)修改+c
    if(tl<=tree[root].l&&tree[root].r<=tr){
        //tree[root].val+=c;
        tree[root].lazy+=c;
        return;
    }
    pushdown(root);
    int mid=(tree[root].l+tree[root].r)/2;
    if(tl<=mid)update(root<<1,tl,tr,c);
    if(tr>mid)update(root<<1|1,tl,tr,c);
    pushup(root);
}
int query(int root,int tl,int tr){
    if(tl<=tree[root].l&&tree[root].r<=tr){
        return tree[root].val+tree[root].lazy;
    }
    pushdown(root);
    int mid=(tree[root].l+tree[root].r)/2;
    int res=-1;
    if(tl<=mid){
        res=max(res,query(root<<1,tl,tr));
    }
    if(tr>mid){
        res=max(res,query(root<<1|1,tl,tr));
    }
    return res;
}
                        
int main()
{
	n = read(); q = read();
	map<int, set<int>> pos[2];

	for (int i = 1; i <= n; i ++ ) {
		a[i] = read();
	}
	for (int i = 1; i <= n; ++i) {
		b[i] = read();
		pos[b[i]][a[i]].insert(i);
		if (b[i]) {
			c[i] = a[i];
			a[i] = 0;
		}
	}

	vector<array<int, 4>> qry[2];
	vector<vector<int>> ans(q);

	for (int i = 0; i < q; ++i)
	{
		int l = read(), r = read(), t = read(), k = read();
		qry[t].push_back(array<int, 4>{l, r, k, i});
	}

	for (int i = 0; i < 2; ++i) {
		if (i) {
			for (int j = 1; j <= n; ++j) {
				swap(a[j], c[j]);
			}
		}

		build(1, 1, n);

		for (auto qr : qry[i]) {
			int l = qr[0], r = qr[1], k = qr[2], id = qr[3];
			for (int j = 0; j < k; ++j) {
				int p = query(1, l, r);
				if (p == 0) {
					ans[id].push_back(-1);
					break;
				}
				auto it = pos[i][p].lower_bound(l);
				ans[id].push_back(*it);	
				update(1, *it, *it, -p);
				pos[i][p].erase(*it);
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		for (auto x : ans[i]) {
			std::cout << x << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
