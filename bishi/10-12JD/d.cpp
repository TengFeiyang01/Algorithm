#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Window {
public:
    int id, row, col, width, height;
    // 添加默认构造函数
    Window() : id(0), row(0), col(0), width(0), height(0) {}
    Window(int id, int row, int col, int width, int height)
        : id(id), row(row), col(col), width(width), height(height) {}

    bool contains(int r, int c) const {
        return r >= row && r < row + height && c >= col && c < col + width;
    }
};

class MultiWindowSys {
private:
    std::unordered_map<int, Window> windows;
    std::vector<int> layers;
    const int maxRows = 1000;  // 假设窗口管理系统的最大行数
    const int maxCols = 1000;  // 假设窗口管理系统的最大列数

public:
    MultiWindowSys() {
    }

    bool createWindow(int id, int row, int col, int width, int height) {
        if (windows.find(id) != windows.end() ||
            row < 0 || col < 0 || row + height <= 0 || col + width <= 0 || row >= maxRows || col >= maxCols) {
            return false;
        }
        Window newWindow(id, row, col, width, height);
        windows[id] = newWindow;
        layers.push_back(id);
        return true;
    }

    bool destroyWindow(int id) {
        if (windows.find(id) == windows.end()) {
            return false;
        }
        windows.erase(id);
        layers.erase(std::remove(layers.begin(), layers.end(), id), layers.end());
        return true;
    }

    bool moveWindow(int id, int dstRow, int dstCol) {
        if (windows.find(id) == windows.end() ||
            dstRow + windows[id].height <= 0 || dstCol + windows[id].width <= 0 ||
            dstRow >= maxRows || dstCol >= maxCols) {
            return false;
        }
        windows[id].row = dstRow;
        windows[id].col = dstCol;

        // 移动窗口到最上层
        layers.erase(std::remove(layers.begin(), layers.end(), id), layers.end());
        layers.push_back(id);

        return true;
    }

    int dispatchClickEvent(int row, int col) {
        for (auto it = layers.rbegin(); it != layers.rend(); ++it) {
            int id = *it;
            if (windows[id].contains(row, col)) {
                // 点击的窗口移动到最上层
                layers.erase(std::remove(layers.begin(), layers.end(), id), layers.end());
                layers.push_back(id);
                return id;
            }
        }
        return -1;
    }
}
int main() {
    MultiWindowSys mws;
    // std::cout << mws.createWindow(2, 70, 80, 15, 17) << std::endl; // Output: 1
    // std::cout << mws.createWindow(1, 0, 10, 999, 100) << std::endl; // Output: 1
    // std::cout << mws.moveWindow(2, 5, 6) << std::endl; // Output: 1
    // std::cout << mws.dispatchClickEvent(20, 20) << std::endl; // Output: 1
    // std::cout << mws.destroyWindow(2) << std::endl; // Output: 1
//     // 调用示例
    std::cout << mws.createWindow(1, 3, 4, 9, 7) << std::endl; // Output: 1
    std::cout << mws.createWindow(2, 7, 8, 11, 7) << std::endl; // Output: 1
    std::cout << mws.createWindow(3, 12, 6, 6, 5) << std::endl; // Output: 1
    std::cout << mws.moveWindow(2, 950, 1000) << std::endl; // Output: 0
    std::cout << mws.dispatchClickEvent(7, 8) << std::endl; // Output: 2
    std::cout << mws.dispatchClickEvent(7, 7) << std::endl; // Output: 2
    std::cout << mws.dispatchClickEvent(7, 8) << std::endl; // Output: 2
    std::cout << mws.dispatchClickEvent(10, 7) << std::endl; // Output: 1

    return 0;
}