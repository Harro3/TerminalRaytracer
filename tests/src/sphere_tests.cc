#include "objects/libobjects.hh"
#include "utils/libutils.hh"

#include <gtest/gtest.h>

TEST(Sphere, ctor)
{
    Sphere s(point3(0, 0, 0), 1);
    ASSERT_EQ(s.center(), point3(0, 0, 0));
    ASSERT_EQ(s.radius(), 1);
}

TEST(Sphere, hit)
{
    Sphere s(point3(0, 0, 0), 1);
    Ray r(point3(0, 0, -5), vec3(0, 0, 1));
    HitRecord rec;
    ASSERT_TRUE(s.hit(r, 0, 10, rec));
    ASSERT_EQ(rec.t, 4);
    ASSERT_EQ(rec.p, point3(0, 0, -1));
    ASSERT_EQ(rec.normal, vec3(0, 0, -1));
}

TEST(Sphere, miss)
{
    Sphere s(point3(0, 0, 0), 1);
    Ray r(point3(0, 0, -5), vec3(0, 1, 0));
    HitRecord rec;
    ASSERT_FALSE(s.hit(r, 0, 10, rec));
}