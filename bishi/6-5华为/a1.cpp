#include <bits/stdc++.h>

using namespace std;
const int N = 2000;

string dir[N], act[N], type[N];
int id[N], ans[N], cnt = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id[i] >> dir[i] >> act[i] >> type[i];
	}
	char op;
	string t;
	cin >> op >> t;
	for (int i = 0; i < n; i++) {
		if (op == 'D' && dir[i] == t) {
			ans[cnt++] = id[i];
		} else if (op == 'A' && act[i] == t) {
			ans[cnt++] = id[i];
		} else if (op == 'T' && type[i] == t) {
			ans[cnt++] = id[i];
		}
	}
	if (cnt == 0) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < cnt; ++i) {
			cout << ans[i] << " \n"[i == cnt - 1];
		}
	}

    return 0;
}
