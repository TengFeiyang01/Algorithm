#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <sstream>
using namespace std;

// 获取输入函数
vector<int> get_input() {
    string s;
    cin >> s;
    vector<int> v;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        v.push_back(stoi(token));
    }
    return v;
}

int main() {
    // 获取司机数据
    vector<int> distance = get_input();
    vector<int> jam = get_input();
    vector<int> light = get_input();
    vector<int> quality = get_input();

    int n = distance.size();
    double min_time = INT_MAX;
    int best_index = -1;

    // 存储司机的信息
    vector<pair<double, int>> driver_info;

    // 计算每个司机的接载时间
    for (int i = 0; i < n; i++) {
        double travel_time = (jam[i] / 2.0) + ((distance[i] - jam[i]) / 10.0) + (light[i] * 15 * 0.5);
        driver_info.push_back({travel_time, quality[i]});
    }

    // 查找最短时间司机
    for (int i = 0; i < n; i++) {
        if (driver_info[i].first < min_time) {
            min_time = driver_info[i].first;
            best_index = i;
        }
    }

    // 检查60秒内的其他司机
    double final_time = min_time;
    for (int i = 0; i < n; i++) {
        if (i != best_index && driver_info[i].first < min_time + 60) {
            if (driver_info[i].second > driver_info[best_index].second) {
                final_time = driver_info[i].first;
                best_index = i;
            }
        }
    }

    // 输出结果
    cout << best_index + 1 << "," << static_cast<int>(final_time) << endl;
    return 0;
}
