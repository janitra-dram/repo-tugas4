/* 
Anda diminta untuk mengimplementasikan class dengan nama Triangle 
yang didalamnya memuat 3 data dalam class Point2D yang telah diimplementasikan

Tujuan dari program adalah menentukan apakah suatua Triangle adalah 
sama kaki, sama sisi, siku-siku, dan sembarang

Input:
    vector dari suatu Triangle (dengan banyak sebesar 3*N) --> N = total Triangle

Output
    print setiap line dengan "sama kaki", "sama sisi", "siku-siku", atau "sembarang"


Silahkan gunakan teori dan implementasi yang telah diajarkan dikelas
*/

#ifndef __TRIANGLES_HPP__
#define __TRIANGLES_HPP__

#include "point2d.hpp"
#include <string>

class Triangle {
private:
    Point2D p1, p2, p3;

public:
    Triangle(Point2D _p1, Point2D _p2, Point2D _p3);
    float hitungJarak(Point2D a, Point2D b);
    std::string cekJenis();
};

#endif