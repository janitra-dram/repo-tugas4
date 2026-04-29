#include "include/triangles.hpp"
#include <cmath>

Triangle::Triangle(Point2D _p1, Point2D _p2, Point2D _p3) : p1(_p1), p2(_p2), p3(_p3) {}

float Triangle::hitungJarak(Point2D a, Point2D b) {
    return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2) + pow(a.GetZ() - b.GetZ(), 2));
}

std::string Triangle::cekJenis() {
    float s1 = hitungJarak(p1, p2);
    float s2 = hitungJarak(p2, p3);
    float s3 = hitungJarak(p3, p1);

    if (s1 == s2 && s2 == s3) return "sama sisi";
    if (s1 == s2 || s2 == s3 || s1 == s3) return "sama kaki";
    
    float a2 = s1 * s1;
    float b2 = s2 * s2;
    float c2 = s3 * s3;
    if (std::abs(a2 + b2 - c2) < 0.01 || std::abs(a2 + c2 - b2) < 0.01 || std::abs(b2 + c2 - a2) < 0.01) {
        return "siku-siku";
    }
    return "sembarang";
}