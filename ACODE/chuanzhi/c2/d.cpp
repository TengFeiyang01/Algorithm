#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
#include <bits/stdc++.h>

template<class T>
struct Point {
    T x;
    T y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}

    template<class U>
    operator Point<U>() {
        return Point<U>(U(x), U(y));
    }
    Point &operator+=(Point p) & {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(Point p) & {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(T v) & {
        x *= v;
        y *= v;
        return *this;
    }
    Point operator-() const {
        return Point(-x, -y);
    }
    friend Point operator+(Point a, Point b) {
        return a += b;
    }
    friend Point operator-(Point a, Point b) {
        return a -= b;
    }
    friend Point operator*(Point a, T b) {
        return a *= b;
    }
    friend Point operator*(T a, Point b) {
        return b *= a;
    }
    friend bool operator==(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
    }
    friend std::istream &operator>>(std::istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, Point p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T>
T dot(Point<T> a, Point<T> b) {
    return a.x * b.x + a.y * b.y;
}

template<class T>
T cross(Point<T> a, Point<T> b) {
    return a.x * b.y - a.y * b.x;
}


template<class T>
struct Line {
    Point<T> a;
    Point<T> b;
    Line(Point<T> a_ = Point<T>(), Point<T> b_ = Point<T>()) : a(a_), b(b_) {}
};


template<class T>
bool pointOnLineLeft(Point<T> p, Line<T> l) {
    return cross(l.b - l.a, p - l.a) > 0;
}

template<class T>
bool pointOnLineRight(Point<T> p, Line<T> l) {
    return cross(l.b - l.a, p - l.a) < 0;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<Point<long double>> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) {
    	std::cin >> a[i].x >> a[i].y;
    }
    if (n == 1) {
        if (a[0].x == a[1].x and a[1].x == a[2].x) {
            std::vector<long double> b{a[0].y, a[1].y, a[2].y};
            std::sort(b.begin(), b.end());
            std::cout << 0 << " " << 1 << " " << -b[1] << "\n";
            return;
        } 
        if (a[0].y == a[1].y and a[1].y == a[2].y) {
            std::vector<long double> b{a[0].x, a[1].x, a[2].x};
            std::sort(b.begin(), b.end());
            std::cout << 0 << " " << 1 << " " << -b[1] << "\n";
            return;
        } 
        auto [x1, y1] = a[0];
        long double x2 = (a[1].x + a[2].x) / 2;
        long double y2 = (a[1].y + a[2].y) / 2;
        long double dx = x2 - x1, dy = y2 - y1;
        std::cout << dy << " " << -dx << " " << (dx * y1 - dy * x1) << "\n";
        return;
    }

    // 枚举直线
    for (int i = 0; i < 3 * n; ++i) {
    	for (int j = i + 1; j < 3 * n; ++j) {
    		int on_line = 0, left = 0, right = 0;
    		Line<long double> l(a[i], a[j]);
    		for (auto p : a) {
    			if (pointOnLineRight(p, l)) {
    				right++;
    			} else if (pointOnLineLeft(p, l)) {
    				left++;
    			} else {
                    on_line++;
    			}
    		}
    		if (left == right and right == on_line and right == n) {
    			auto [x1, y1] = a[i];
    			auto [x2, y2] = a[j];
    			long double dx = x2 - x1, dy = y2 - y1;
                std::cout << dy << " " << -dx << " " << (dx * y1 - dy * x1) << "\n";
    			return;
    		}
    	}
    }
    std::cout << "-1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
