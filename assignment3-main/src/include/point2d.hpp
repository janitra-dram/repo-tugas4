#ifndef __POINT2D_HPP__
#define __POINT2D_HPP__

class Point2D {
private:
    float _x, _y;

public:
    Point2D();
    Point2D(float x, float y);

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    void SetX(float x) { _x = x; }
    void SetY(float y) { _y = y; }

    Point2D operator+(const Point2D inp);
    Point2D operator-(const Point2D inp);
    Point2D operator*(const Point2D inp);
};

#endif