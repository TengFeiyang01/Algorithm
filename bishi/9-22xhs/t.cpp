#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 贪心算法解决问题，并记录每个站点覆盖的区间范围
int minTotalDistance(int n, int m, vector<int>& stations, vector<pair<int, int>>& intervals, map<int, vector<pair<int, int>>>& coverageMap) {
    // 对区间按照右端点排序
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; // 按右端点升序排列
    });

    // 对站点进行排序，方便选择
    sort(stations.begin(), stations.end());

    int stationIndex = 0;
    int lastCovered = 0;
    int totalDistance = 0;
    int selectedStation = -1;

    // 遍历每个区间
    for (int i = 0; i < m; ++i) {
        int l = intervals[i].first;
        int r = intervals[i].second;

        // 找到覆盖该区间的最远站点
        while (stationIndex < n && stations[stationIndex] <= r) {
            if (stations[stationIndex] >= l) {
                selectedStation = stations[stationIndex];
            }
            stationIndex++;
        }

        // 如果没有找到能覆盖该区间的站点，则返回 -1
        if (selectedStation == -1) {
            return -1;
        }

        // 如果当前区间已经被覆盖，我们跳过
        if (selectedStation <= lastCovered) {
            continue;
        }

        // 记录站点覆盖的区间
        coverageMap[selectedStation].push_back(intervals[i]);

        // 计算从上次覆盖到现在的最远站点之间的行程
        totalDistance += 2 * (selectedStation - lastCovered);
        lastCovered = selectedStation;
    }

    // 最后返回到起点
    totalDistance += lastCovered * 2;

    return totalDistance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> stations(n);
    vector<pair<int, int>> intervals(m);
    map<int, vector<pair<int, int>>> coverageMap; // 记录每个站点覆盖的区间范围

    // 读取加油站的站点位置
    for (int i = 0; i < n; i++) {
        cin >> stations[i];
    }

    // 读取区间的左右边界
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // 计算最小的总行程
    int result = minTotalDistance(n, m, stations, intervals, coverageMap);

    if (result == -1) {
        cout << "无法覆盖所有区间" << endl;
    } else {
        cout << "最小总行程: " << result << endl;

        // 输出每个站点覆盖的区间
        for (const auto& entry : coverageMap) {
            int station = entry.first;
            cout << "站点 " << station << " 覆盖的区间: ";
            for (const auto& interval : entry.second) {
                cout << "[" << interval.first << ", " << interval.second << "] ";
            }
            cout << endl;
        }
    }

    return 0;
}
