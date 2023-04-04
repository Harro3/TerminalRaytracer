#include "ray.hh"

#include <cmath>

Ray::Ray() : origin_(point3(0, 0, 0)), dir_(vec3(0, 0, 0)) {}
Ray::Ray(const point3& origin, const vec3& dir) : origin_(origin), dir_(dir) {}

point3 Ray::get_origin() const
{
    return origin_;
}

vec3 Ray::get_dir() const
{
    return dir_;
}

point3 Ray::at(double t) const
{
    return origin_ + dir_ * t;
}