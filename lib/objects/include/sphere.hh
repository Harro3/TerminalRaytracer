#pragma once

#include "hittable.hh"
#include "moveable.hh"
#include "../../utils/libutils.hh"

/**
 * @brief A sphere object
 * 
 */
class Sphere : public Hittable
{
public:
    Sphere(point3 center, double radius);

    /**
     * @brief Get the center of the sphere
     * 
     * @return point3 
     */
    point3 center();

    /**
     * @brief Get the radius of the sphere
     * 
     * @return double 
     */
    double radius();


    /**
     * @brief Set the center of the sphere
     * 
     * @param center 
     */
    void set_center(point3 center);

    /**
     * @brief Set the radius of the sphere
     * 
     * @param radius 
     */
    void set_radius(double radius);

    bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

private:
    double radius_;
};
