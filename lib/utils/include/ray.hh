#pragma once

#include "vector.hh"

/**
 * @brief A class that represents a ray of light
 * to be used for ray tracing
 * 
 */
class Ray
{
public:
    /**
     * @brief Default constructor with origin at (0, 0, 0)
     * 
     */
    Ray();

    /**
     * @brief Construct a new Ray object
     * 
     * @param origin the origin point where the ray is cast from
     * @param dir the direction of the ray
     */
    Ray(const point3& origin, const vec3& dir);

    /**
     * @brief Get the origin of the ray
     * 
     * @return Vector 
     */
    point3 get_origin() const;

    /**
     * @brief Get the dir of the ray
     * 
     * @return Vector 
     */
    vec3 get_dir() const;

    /**
     * @brief Get the point at a certain distance from the origin following the ray direction
     * 
     * @param t the distance from the origin
     * @return Vector 
     */
    point3 at(double t) const;

private:
    point3 origin_;
    vec3 dir_;
};