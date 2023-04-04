#include <gtest/gtest.h>

#include "utils/libutils.hh"

TEST(ray, ctor)
{
    Ray r;
    ASSERT_EQ(r.get_origin(), point3(0, 0, 0));
    ASSERT_EQ(r.get_dir(), Vector(0, 0, 0));
}

TEST(ray, ctor_2)
{
    Ray r(point3(1, 2, 3), Vector(4, 5, 6));
    ASSERT_EQ(r.get_origin(), point3(1, 2, 3));
    ASSERT_EQ(r.get_dir(), Vector(4, 5, 6));
}

TEST(ray, at)
{
    Ray r(point3(1, 2, 3), Vector(4, 5, 6));
    ASSERT_EQ(r.at(0), point3(1, 2, 3));
    ASSERT_EQ(r.at(1), point3(5, 7, 9));
    ASSERT_EQ(r.at(2), point3(9, 12, 15));
}