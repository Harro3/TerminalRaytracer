#pragma once

#include "hittable.hh"

#include <memory>
#include <vector>

/**
 * @brief A list of hittable objects
 * 
 */
class HittableList : public Hittable
{
public:
    HittableList() : objects() {}

    void clear() { objects.clear(); }
    void add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

    bool hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const override;

    std::vector<std::shared_ptr<Hittable>> objects;
};