#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

// Helper function to simplify the path
string simplify(string path) {
    vector<string> parts;
    deque<string> stack;
    stringstream ss(path);
    string part;
    
    // Split the path by "/"
    while (getline(ss, part, '/')) {
        if (part == "" || part == ".") {
            // Skip empty or current directory
            continue;
        } else if (part == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            // Normal directory name
            stack.push_back(part);
        }
    }

    // Construct the simplified path
    string result;
    if (path[0] == '/') {
        result += "/";
    }
    
    while (!stack.empty()) {
        result += stack.front();
        stack.pop_front();
        if (!stack.empty()) {
            result += "/";
        }
    }

    if (result.empty()) {
        return "/";
    }
    
    return result;
}

// Function to combine and simplify paths
string simplifyPath(string cwd, string path) {
    if (path[0] == '/') {
        return simplify(path);
    } else {
        if (cwd.back() != '/') {
            cwd += "/";
        }
        return simplify(cwd + path);
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        // Find the space separator between CWD and PATH
        size_t spaceIndex = line.find(' ');
        string cwd = line.substr(0, spaceIndex);
        string path = line.substr(spaceIndex + 1);

        string result = simplifyPath(cwd, path);
        cout << result << endl;
    }

    return 0;
}
