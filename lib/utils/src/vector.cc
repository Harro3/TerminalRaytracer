#include "vector.hh"

#include <cmath>

Vector::Vector() : x_(0), y_(0), z_(0) {}
Vector::Vector(double x, double y) : x_(x), y_(y), z_(0) {}
Vector::Vector(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Vector::x() const { return x_; }
double Vector::y() const { return y_; }
double Vector::z() const { return z_; }

void Vector::set_x(double x) { x_ = x; }
void Vector::set_y(double y) { y_ = y; }
void Vector::set_z(double z) { z_ = z; }

Vector &Vector::operator+=(const Vector &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    z_ += rhs.z_;
    return *this;
}
Vector &Vector::operator-=(const Vector &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    z_ -= rhs.z_;
    return *this;
}
Vector &Vector::operator*=(const Vector &rhs)
{
    int x = y_ * rhs.z_ - z_ * rhs.y_;
    int y = z_ * rhs.x_ - x_ * rhs.z_;
    int z = x_ * rhs.y_ - y_ * rhs.x_;
    x_ = x;
    y_ = y;
    z_ = z;
    return *this;
}
Vector &Vector::operator*=(const int &rhs)
{
    x_ *= rhs;
    y_ *= rhs;
    z_ *= rhs;
    return *this;
}
Vector &Vector::operator*=(const double &rhs)
{
    x_ *= rhs;
    y_ *= rhs;
    z_ *= rhs;
    return *this;
}

Vector &Vector::operator/=(const int &rhs)
{
    x_ /= rhs;
    y_ /= rhs;
    z_ /= rhs;
    return *this;
}

Vector &Vector::operator/=(const double &rhs)
{
    x_ /= rhs;
    y_ /= rhs;
    z_ /= rhs;
    return *this;
}

Vector Vector::operator+(const Vector &rhs) const
{
    Vector v(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_);
    return v;
}
Vector Vector::operator-(const Vector &rhs) const
{
    Vector v(x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_);
    return v;
}

Vector Vector::operator*(const Vector &rhs) const
{
    int x = y_ * rhs.z_ - z_ * rhs.y_;
    int y = z_ * rhs.x_ - x_ * rhs.z_;
    int z = x_ * rhs.y_ - y_ * rhs.x_;
    Vector v(x, y, z);
    return v;
}

Vector Vector::operator*(const int rhs) const
{
    Vector v(x_ * rhs, y_ * rhs, z_ * rhs);
    return v;
}

Vector Vector::operator*(const double rhs) const
{
    Vector v(x_ * rhs, y_ * rhs, z_ * rhs);
    return v;
}

Vector Vector::operator/(const int rhs) const
{
    Vector v(x_ / rhs, y_ / rhs, z_ / rhs);
    return v;
}

Vector Vector::operator/(const double rhs) const
{
    Vector v(x_ / rhs, y_ / rhs, z_ / rhs);
    return v;
}

void Vector::normalize()
{
    double length = sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    x_ /= length;
    y_ /= length;
    z_ /= length;
}

double Vector::dot(Vector a, Vector b)
{
    return a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_;
}

bool Vector::operator==(const Vector &rhs) const
{
    return x_ == rhs.x_ && y_ == rhs.y_ && z_ == rhs.z_;
}

double Vector::length()
{
    return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
    return os;
}