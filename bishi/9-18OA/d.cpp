#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stdexcept>

struct LogEntry {
    char type; 
    int id;    
};

void assign_ids(std::vector<LogEntry>& logs) {
    std::list<int> unmatched_As; 
    std::unordered_map<int, std::list<int>::iterator> id_iterators; 

    for (auto& log : logs) {
        if (log.type == 'A') {
            unmatched_As.push_back(log.id);
            id_iterators[log.id] = --unmatched_As.end();
        } else if (log.type == 'B') {
            if (unmatched_As.empty()) {
                throw std::runtime_error("No unmatched 'A' to assign 'B' log");
            }
            log.id = unmatched_As.front();
        } else if (log.type == 'C') {
            auto it = id_iterators.find(log.id);
            if (it == id_iterators.end()) {
                throw std::runtime_error("No matching 'A' for 'C' log with ID " + std::to_string(log.id));
            }
            unmatched_As.erase(it->second);
            id_iterators.erase(it);
        } else {
            throw std::runtime_error("Unknown log type '" + std::string(1, log.type) + "'");
        }
    }
}

int main() {
    std::vector<LogEntry> logs = {
        {'A', 1},
        {'B', 0}, 
        {'A', 2},
        {'C', 1},
        {'B', 0}, 
        {'C', 2}
    };

    try {
        assign_ids(logs);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    for (const auto& log : logs) {
        if (log.type == 'B') {
            std::cout << log.type << log.id << " ";
        } else {
            std::cout << log.type << log.id << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
