#include <bits/stdc++.h>

class Server {
public:
    Server(char name) : serverNname_(name) {}

    void serveOne() {
        if (openFlag_ and lastServedIdx < curNum_) {
            lastServedIdx++;
            std::cout << "Server" << serverNname_ << " serve for " << lastServedIdx << std::endl;
        }

        if (lastServedIdx >= curNum_) {
            openFlag_ = false;
        }
    }

    static int &getTurn() {
        return curNum_;
    }

    static bool &stillOpen() {
        return openFlag_;
    }

private:
    char serverNname_;
    static int curNum_;
    static bool openFlag_;
    static int lastServedIdx;
};

int Server::curNum_ = 0;
bool Server::openFlag_ = true;
int Server::lastServedIdx = 0;

int main() {
    Server a('A'), b('B'), c('c');

    std::cout << "How many people in the group: ";
    int num;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        std::cout << "idx: " << ++Server::getTurn() << std::endl;
    }

    do {
        a.serveOne();
        b.serveOne();
        c.serveOne();
    } while (Server::stillOpen());

    return 0;
}
