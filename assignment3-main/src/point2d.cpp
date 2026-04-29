#include "include/point2d.hpp"

Point2D::Point2D() : _x(0), _y(0) {}

Point2D::Point2D(float x, float y) : _x(x), _y(y) {}

Point2D Point2D::operator+(const Point2D inp) {
    Point2D out;
    out.SetX(this->_x + inp.GetX());
    out.SetY(this->_y + inp.GetY());
    return out;
}

Point2D Point2D::operator-(const Point2D inp) {
    Point2D out;
    out.SetX(this->_x - inp.GetX());
    out.SetY(this->_y - inp.GetY());
    return out;
}

Point2D Point2D::operator*(const Point2D inp) {
    Point2D out;
    out.SetX(this->_x * inp.GetX());
    out.SetY(this->_y * inp.GetY());
    return out;
}