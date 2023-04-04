#pragma once

#include <iostream>

/**
 * @brief A class that represents a 3D vector
 * with all the basic operations
 * 
 */
class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);
    Vector(double x, double y);

    double x() const;
    double y() const;
    double z() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    Vector &operator+=(const Vector& rhs);
    Vector &operator-=(const Vector& rhs);
    Vector &operator*=(const Vector& rhs);
    Vector &operator*=(const int &l);
    Vector &operator*=(const double &l);
    Vector &operator/=(const int &l);
    Vector &operator/=(const double &l);

    Vector operator+(const Vector& rhs) const;
    Vector operator-(const Vector& rhs) const;
    Vector operator*(const Vector& rhs) const;
    Vector operator*(const int l) const;
    Vector operator*(const double l) const;
    Vector operator/(const int l) const;
    Vector operator/(const double l) const;

    bool operator==(const Vector& rhs) const;

    void normalize();

    static double dot (Vector a, Vector b);

    double length();

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);


private:
    double x_;
    double y_;
    double z_;
};


using vec3 = Vector;
using point3 = Vector;