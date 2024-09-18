#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int t[N * 40][2];
int tot;

void insert(int x)
{
    int p = 0;
    for (int i = 29; i >= 0; i -- )
    {
        int k = x >> i & 1;
        if (!t[p][k]) t[p][k] = ++ tot;
        p = t[p][k];
    }
}

int query(int p, int k)
{
    int ans = 0;
    for (int i = k; i >= 0; i -- )
    {
        if (t[p][0] && t[p][1]) 
        {
            ans += 1 << i;
            ans += min(query(t[p][0], i - 1), query(t[p][1], i - 1));
            return ans;
        }
        else if (t[p][0]) p = t[p][0];
        else p = t[p][1];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), insert(a[i]);

    printf("%d", query(0, 29));

    return 0;
}