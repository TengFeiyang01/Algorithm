#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

bool isRightTriangle(const Point& A, const Point& B, const Point& C) {
    // Calculate the vectors
    double ABx = B.x - A.x;
    double ABy = B.y - A.y;
    double BCx = C.x - B.x;
    double BCy = C.y - B.y;
    double CAx = A.x - C.x;
    double CAy = A.y - C.y;
    
    double dotAB_BC = ABx * BCx + ABy * BCy;
    double dotBC_CA = BCx * CAx + BCy * CAy;
    double dotCA_AB = CAx * ABx + CAy * ABy;
    
    // Check if any of the dot products is zero
    if (fabs(dotAB_BC) < 1e-6 || fabs(dotBC_CA) < 1e-6 || fabs(dotCA_AB) < 1e-6) {
        return true;
    }
    
    return false;
}

int main() {
    // Define the points
    Point A, B, C;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
    
    // Check if the triangle is a right triangle
    if (isRightTriangle(A, B, C)) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
    
    return 0;
}
