#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
vector<int> org, a, sum;

bool check(int idx, int mid)
{
	// 第二层二分多少人可以超过当前竞选者
	int cnt = 0, cur = org[idx] + mid, rest = k - mid;
	int p = upper_bound(a.begin() + 1, a.end(), cur) - (a.begin() + 1);
	if (org[idx] < a[n - m + 1]) // idx不在前m大的人当中
	{
		if (p < n - m + 1)
		{
			return false;
		}
		return (p - n + m) * (cur + 1) - (sum[p] - sum[n - m]) > rest; // 让前边每个人的票都比cur多1，看剩下的票够不够
	}
	// 往外扩一个
	return (p - n + m) * (cur + 1) - (sum[p] - sum[n - m - 1]) + org[idx] > rest; // sum里面多减了所以org[idx]要加回来

}

void solve()
{
	cin >> n >> m >> k;
	if (n == m)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "0 ";
		}
		return;
	}
	org.resize(n + 1);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> org[i];
		k -= org[i]; // k是剩下的票
	}
	a = org;
	sort(a.begin() + 1, a.end());
	sum.resize(n + 1);
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = k, res = -1;
		while (l <= r) // 第一层二分需要的票数
		{
			int mid = (l + r) >> 1;
			if (check(i, mid))
			{
				res = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans[i] = res;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T = 1;
	//cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}

