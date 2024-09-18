#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int w[N], f[N];
int que[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        while (hh <= tt && i - que[hh] > m) hh ++ ;
        f[i] = f[que[hh]] + w[i];
        while (hh <= tt && f[que[tt]] >= f[i]) tt -- ;
        que[ ++ tt] = i;
    }

    if (n + 1 - m > que[hh]) hh ++ ;   //滑动窗口往后滑动一位

    printf("%d\n", f[que[hh]]);

    return 0;
}
