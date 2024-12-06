#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 结构体表示会议室
struct Room {
    int capacity;  // 会议室容量
    vector<bool> occupied;  // 记录会议室的每个时间点是否被占用
    Room(int cap, int max_time) : capacity(cap), occupied(max_time, false) {}
};

// 结构体表示会议需求
struct Meeting {
    int attendees;  // 参会人数
    int start_time; // 会议开始时间
    int duration;   // 会议时长
};

int main() {
    int N;  // 会议室数量
    cin >> N;
    
    vector<int> capacities(N);  // 每个会议室的容量
    for (int i = 0; i < N; ++i) {
        cin >> capacities[i];
    }
    
    int M;  // 会议需求数量
    cin >> M;
    
    vector<Meeting> meetings(M);  // 会议需求列表
    for (int i = 0; i < M; ++i) {
        cin >> meetings[i].attendees >> meetings[i].start_time >> meetings[i].duration;
    }
    
    // 最大的时间点，假设每个会议时长最多200，会议时间最大200
    const int MAX_TIME = 200;
    
    // 会议室列表
    vector<Room> rooms;
    for (int i = 0; i < N; ++i) {
        rooms.push_back(Room(capacities[i], MAX_TIME));
    }

    int failed_meetings = 0;  // 无法安排的会议次数
    int failed_people = 0;    // 无法参加会议的总人次

    // 处理每个会议需求
    for (auto &meeting : meetings) {
        bool assigned = false;
        int best_room = -1;  // 最优会议室索引
        int min_diff = MAX_TIME;  // 容量差值，最小值
        
        // 尝试分配会议室
        for (int i = 0; i < N; ++i) {
            // 判断会议室是否满足要求
            if (rooms[i].capacity >= meeting.attendees) {
                bool can_assign = true;
                // 检查会议室是否在会议时间段内被占用
                for (int t = meeting.start_time; t < meeting.start_time + meeting.duration; ++t) {
                    if (rooms[i].occupied[t]) {
                        can_assign = false;
                        break;
                    }
                }
                
                // 如果会议室可以安排，选择容量差最小的会议室
                if (can_assign) {
                    int diff = rooms[i].capacity - meeting.attendees;
                    if (diff < min_diff) {
                        min_diff = diff;
                        best_room = i;
                    }
                }
            }
        }
        
        // 如果找到合适的会议室
        if (best_room != -1) {
            // 分配该会议室
            for (int t = meeting.start_time; t < meeting.start_time + meeting.duration; ++t) {
                rooms[best_room].occupied[t] = true;
            }
            assigned = true;
        }
        
        // 如果没有合适的会议室，记录无法安排的会议
        if (!assigned) {
            ++failed_meetings;
            failed_people += meeting.attendees;
        }
    }
    
    // 输出结果
    cout << failed_meetings << " " << failed_people << endl;

    return 0;
}