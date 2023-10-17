//
// Created by trudbot on 2022/7/21.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int l[N], r[N], p[N], d[N];//左、右、父、深度

//获取各结点的深度
void dfs(int root, int depth)
{
    if(root == -1) return;
    d[root] = depth;
    dfs(l[root], depth+1);
    dfs(r[root], depth+1);
}

//获取两个结点的最近公共祖先
int getParent(int x1, int x2)
{
    if(d[x1] < d[x2]) return getParent(x2, x1);//维护x1为较深的那个
    while(d[x1] > d[x2]) x1 = p[x1];//x1往上走， 直到与x2深度相同
    while(x1 != x2) x1 = p[x1], x2 = p[x2]; //同时往上走， 直到两结点相同
    return x1;
}

int main() {

    int t; cin >> t;
    while ( t -- )
    {
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            int left, right;
            cin >> left >> right;
            l[i] = left, r[i] = right;
            if(left != -1) p[left] = i;
            if(right != -1) p[right] = i;
        }
        dfs(1, 1);//从根结点1开始遍历， 获取深度

        int x1, x2;
        while( m -- )
        {
            cin >> x1 >> x2;
            int parent = getParent(x1, x2);
            cout << d[x1] + d[x2] - 2 * d[parent] << endl;
        }
    }

    return 0;
}
