#pragma once

#include "../../utils/libutils.hh"

#include "moveable.hh"


/**
 * @brief Struct for storing information after a ray hit a hittable object
 * 
 */
struct HitRecord
{
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
};

/**
 * @brief An abstract class for objects that can be hit by a ray
 * 
 */
class Hittable : public Moveable{
    public:
    Hittable(point3 position) : Moveable(position) {}
    Hittable() : Moveable() {}

    /**
     * @brief Handles the hit of a ray by a hittable object
     * 
     * @param r the ray
     * @param t_min the minimum distance from the ray origin to the hit point
     * @param t_max the maximum distance from the ray origin to the hit point
     * @param rec the hit record to store the hit information
     * @return true if the ray hit the object
     * @return false if the ray did not hit the object
     */
        virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};
