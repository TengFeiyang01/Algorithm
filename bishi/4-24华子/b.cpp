#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<tuple<int, int, string, int>> a;

	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		int x = 0, y = 0, cnt = 0;
		for (int j = 0; j < m; ++j)
		{
			if (s[i][j] == '1')
			{
				cnt++;
				x++;
			}
			else
			{
				cnt = 0;
			}
			y = max(y, cnt);
		}
		a.emplace_back(-x, -y, s[i], i + 1);
	}

	sort(a.begin(), a.end(), [](const auto &t1, const auto &t2)
		 {
        if (get<0>(t1) != get<0>(t2)) return get<0>(t1) < get<0>(t2);
        if (get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
        if (get<2>(t1) != get<2>(t2)) return get<2>(t1) > get<2>(t2);
        return get<3>(t1) < get<3>(t2); });
	for (int i = 0; i < n - 1; ++i)
	{
		std::cout << get<3>(a[i]) << " ";
	}
	std::cout << get<3>(a[n - 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
