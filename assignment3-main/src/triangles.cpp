#include "include/triangles.hpp"
#include <cmath>
#include <string>

using namespace std;

// Hapus underscore (_) di sini sesuai saran compiler lo tadi
Triangle::Triangle(Point2D p1, Point2D p2, Point2D p3) : p1(p1), p2(p2), p3(p3) {}

float Triangle::hitungJarak(Point2D a, Point2D b) {
    return sqrt(pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2));
}

string Triangle::cekJenis() {
    float s1 = hitungJarak(p1, p2);
    float s2 = hitungJarak(p2, p3);
    float s3 = hitungJarak(p3, p1);

    if (abs(s1 - s2) < 0.001 && abs(s2 - s3) < 0.001) return "sama sisi";
    if (abs(s1 - s2) < 0.001 || abs(s2 - s3) < 0.001 || abs(s1 - s3) < 0.001) return "sama kaki";
    
    float a = s1*s1, b = s2*s2, c = s3*s3;
    if (abs(a+b-c) < 0.1 || abs(a+c-b) < 0.1 || abs(b+c-a) < 0.1) return "siku-siku";

    return "sembarang";
}