#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct room {
    int area, price, rooms;
    int x, y, id;
};

class Room {
public:
    bool addRoom(int id, int area, int price, int rooms, std::array<int, 2> address) {
        auto rm = room{area, price, rooms, address[0], address[1], id};
        bool ok = true;
        if (dict.count(id)) {
            ok = false;
        }
        // key->val
        // id->room
        dict[id] = rm;
        return ok;
    }

    bool deleteRoom(int id) {
        if (dict.count(id)) {
            dict.erase(id);
            return true;
        }
        return false;
    }

    //dx+dy
    int getDist(int x1, int y1, int x2, int y2) {
        return abs(x1 - y1) + abs(x2 - y2);
    }

    std::vector<int> queryRoom(int area, int price, int rooms, std::array<int, 2> address, std::vector<std::array<int, 2>> orderBy) {
        std::vector<int> a;
//        for (auto [k, v] : dict) {
        for (auto t : dict) {
            auto v = t.second;
            if (v.area >= area and v.price <= price and v.rooms == rooms) {
                a.push_back(v.id);
            }
        }
        int x = address[0], y = address[1];
        // sort 默认接受小于号
        std::sort(a.begin(), a.end(), [&](auto i, auto j) ->bool {
            auto lhs = dict[i], rhs = dict[j];
            for (auto [p, v] : orderBy) {
                if (p == 1 and lhs.area != rhs.area) {
                    return v == 1 ? lhs.area < rhs.area : lhs.area > rhs.area;
                }
                if (p == 2 and lhs.price != rhs.price) {
                    return v == 1 ? lhs.price < rhs.price : lhs.price > rhs.price;
                }
                int d1 = getDist(lhs.x,lhs.y, x,y), d2 = getDist(rhs.x, rhs.y, x, y);
                if (p == 3 and d1 != d2) {
                    return v == 1 ? d1 < d2 : d1 > d2;
                }
            }
            return i < j;
        });
        return a;
    }
private:
    // id -> room
    std::unordered_map<int, room> dict;
    //<int, vector<room>>
    // set unordered_set multiset
    // {1, 2, 3}  {1, 1, 3}
    // .erase(x)
    // .erase(.find(x))
};

void solve() {
    Room r;
    std::cout << r.deleteRoom(10) << "\n";
    std::cout << r.addRoom(3, 24, 500, 2, {0, 1}) << "\n";
    std::cout << r.addRoom(3, 24, 500, 2, {0, 1})  << "\n";
    std::cout << r.addRoom(3, 27, 500, 4, {1, 1}) << "\n";
    std::cout << r.addRoom(1, 27, 500, 4, {20, 43}) << "\n";
    std::cout << r.addRoom(6, 35, 227, 4, {2, 4}) << "\n";
    std::cout << r.addRoom(9, 20, 3540, 4, {4, 321}) << "\n";
    auto t = r.queryRoom(25, 900, 4, {10, 1}, {{1, 1}, {2, -1}, {3, 1}});
    for (int x : t) {
        std::cout << x << "\n";
    }

    std::cout << *it << "\n";
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
