#include <iostream>
#include <vector>
#include "include/point2d.hpp"
#include "include/triangles.hpp"

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<Triangle> triangles;

    for (int i = 0; i < N; ++i) {
        float x1, y1, x2, y2, x3, y3;
        if (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)) break;

        Point2D p1(x1, y1);
        Point2D p2(x2, y2);
        Point2D p3(x3, y3);

        triangles.push_back(Triangle(p1, p2, p3));
    }

    for (size_t i = 0; i < triangles.size(); ++i) {
        cout << triangles[i].cekJenis() << endl;
    }

    return 0;
}