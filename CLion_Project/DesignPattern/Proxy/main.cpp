#include <iostream>
#include <unistd.h>

class Text {
public:
    void showText() {
        std::cout
                << "abcdefghijklmnopqrstuvwxyzabcdefghij\n"
                   "klmnopqrstuvwxyzabcdefghijklmnopqrst\n"
                   "uvwxyzabcdefghijklmnopqrstuvwxyzabcde\nf"
                   "ghijklmnopqrstuvwxyzabcdefghijklmnopq\n"
                   "rstuvwxyzabcdefghijklmnopqrstuvwxyzabcd\nefg"
                   "hijklmnopqrstuvwxyzabcdefghijklmnopqrstu\n"
                   "vwxyzabcdefghijklmnopqrstuvwxyzabcdefgh\n"
                   "ijklmnopqrstuvwxyzabcdefghijklmnopqrstu\n"
                   "vwxyzabcdefghijklmnopqrstuvwxyz"
                << std::endl;
    }
};

class ImageSubject {
public:
    virtual void showImage() = 0;
};

class BigImage : public ImageSubject {
public:
    BigImage() {
        sleep(6);
        std::cout << "The picture has benn show!!!" << std::endl;
    }

    void showImage() {
        std::cout << "Show Qingming Shang He Tu" << std::endl;
    }
};

class ProxyImage : public ImageSubject {
public:
    ProxyImage() {
        bi = nullptr;
    }

    void showImage() {
        if (bi == nullptr) {
            bi = new BigImage;
        }
        bi->showImage();
    }

private:
    BigImage *bi;
};

class Doc {
public:
    Doc() {
        pi = new ProxyImage;
        t = new Text;
    }

    void show() {
        t->showText();
        pi->showImage();
    }

private:
    Text *t;
    ProxyImage *pi;
};

int main() {
    Doc d;
    d.show();


    return 0;
}
