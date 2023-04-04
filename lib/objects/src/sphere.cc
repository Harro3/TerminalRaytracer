#include "sphere.hh"

#include <cmath>

Sphere::Sphere(point3 center, double radius) : Hittable(center)
{
    radius_ = radius;
}

point3 Sphere::center() { return position(); }

double Sphere::radius() { return radius_; }

void Sphere::set_center(point3 center) { position_ = center; }

void Sphere::set_radius(double radius) { radius_ = radius; }

bool Sphere::hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const
{
    vec3 oc = r.get_origin() - position_;

    double a = Vector::dot(r.get_dir(), r.get_dir());
    double b = Vector::dot(oc, r.get_dir());
    double c = Vector::dot(oc, oc) - radius_ * radius_;

    double discriminant = b * b - a * c;
    if (discriminant < 0)
        return false;

    auto sqrtd = sqrt(discriminant);
    auto root = (-b - sqrtd) / a;
    if (root < t_min || t_max < root)
    {
        root = (-b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - position_) / radius_;

    return true;
}