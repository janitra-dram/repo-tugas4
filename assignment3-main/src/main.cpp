#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;

int main(int argc, char ** argv)
{
    int N;
    // Membaca jumlah segitiga
    if (!(cin >> N)) return 0;

    vector<Triangle> triangles;

    /*----------------------------
    Buat loop untuk membuat menginputkan data triangle (3 buah X Y Z data) ke dalam
    variable triangles
    ----------------------------*/
    for (int i = 0; i < N; ++i) {
        float x1, y1, z1, x2, y2, z2, x3, y3, z3;
        
        // Membaca 9 input float untuk 3 titik (p1, p2, p3)
        if (!(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3)) break;
        
        Point2D p1(x1, y1, z1);
        Point2D p2(x2, y2, z2);
        Point2D p3(x3, y3, z3);
        
        // Memasukkan objek Triangle ke dalam vector
        triangles.push_back(Triangle(p1, p2, p3));
    }

    /*----------------------------
    Implementasikan kode untuk melakukan pengecekan apakah data pada variable triangles
    adalah "sama kaki", "sama sisi", "siku-siku", atau "sembarang"
    ----------------------------*/
    for (int i = 0; i < triangles.size(); ++i) {
        cout << triangles[i].cekJenis() << endl;
    }

    return 0;
}