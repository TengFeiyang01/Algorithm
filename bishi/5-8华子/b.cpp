#include <iostream>
#include <unordered_map>
#include <queue>

class NeighborCache {
public:
    int capacity;
    std::unordered_map<int, int> cache;
    std::unordered_map<int, int> access_count;
    std::unordered_map<int, int> access_time;
    int timestamp;
    NeighborCache(int capacity) {
        this->capacity = capacity;
        this->timestamp = 0;
    }

    void write(int x, int y) {
        if (cache.find(x) != cache.end()) {
            cache[x] = y;
            access_count[x]++;
            access_time[x] = timestamp;
        } else {
            if (cache.size() >= capacity) {
                evict();
            }
            cache[x] = y;
            access_count[x] = 1;
            access_time[x] = timestamp;
        }
    }

    void evict() {
        int min_count = INT_MAX;
        int least_used_cell = -1;
        for (auto& kv : access_count) {
            if (kv.second < min_count || (kv.second == min_count && access_time[kv.first] < access_time[least_used_cell])) {
                min_count = kv.second;
                least_used_cell = kv.first;
            }
        }
        cache.erase(least_used_cell);
        access_count.erase(least_used_cell);
        access_time.erase(least_used_cell);
    }

    int read(int x) {
        if (cache.find(x) != cache.end()) {
            access_count[x]++;
            access_time[x] = timestamp;
            return cache[x];
        } else {
            return -1;
        }
    }

    int query(int x) {
        if (cache.find(x) != cache.end()) {
            return cache[x];
        } else {
            return -1;
        }
    }
};

int main() {
    std::string t;
    std::cin >> t;
    int capacity;
    std::cin >> capacity;
    NeighborCache cache(capacity);

    std::string line;
    std::cin.ignore(); 
    while (getline(std::cin, line)) {
        if (line == "write:") {
            int n;
            std::cin >> n;
            for (int i = 0; i < n; ++i) {
                int x, y;
                std::cin >> x >> y;
                cache.write(x, y);
                cache.timestamp++; 
            }
        } else if (line == "read:") {
            int x;
            std::cin >> x;
            cache.read(x);
            cache.timestamp++; 
        } else if (line == "query:") {
            int x;
            std::cin >> x;
            int y = cache.query(x);
            if (y != -1) {
                std::cout << y << std::endl;
            } else {
                std::cout << "-1" << std::endl;
            }
            cache.timestamp++; 
            break; 
        }
    }
    return 0;
}
