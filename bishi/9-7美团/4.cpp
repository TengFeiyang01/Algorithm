#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;

    map<int, int> hp;
    while (q-- > 0) {
        int x, s;
        cin >> x >> s;
        int y = x + s - 1;

        auto ent = hp.upper_bound(x);
        if (ent != hp.begin()) {
            ent--;
            int r = ent->second;
            if (r >= x) {
                x = ent->first;
                y = ent->second + s;
                hp.erase(ent->first);
            }
        }

        while (true) {
            auto e2 = hp.upper_bound(x);
            if (e2 == hp.end()) {
                hp[x] = y;
                break;
            } else if (e2->first > y) {
                hp[x] = y;
                break;
            } else if (e2->second <= y) {
                y += (e2->second - e2->first + 1);
                hp.erase(e2->first);
            } else if (e2->second > y) {
                y = e2->second + (y - e2->first + 1);
                hp.erase(e2->first);
            }
        }

        cout << y << endl;
    }

    return 0;
}
