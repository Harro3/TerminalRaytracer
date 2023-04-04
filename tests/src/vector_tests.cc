#include <gtest/gtest.h>

#include "utils/libutils.hh"

TEST(vector, ctor)
{
    Vector v;
    ASSERT_EQ(v.x(), 0);
    ASSERT_EQ(v.y(), 0);
    ASSERT_EQ(v.z(), 0);
}

TEST(vector, ctor_2)
{
    Vector v(1, 2);
    ASSERT_EQ(v.x(), 1);
    ASSERT_EQ(v.y(), 2);
    ASSERT_EQ(v.z(), 0);
}

TEST(vector, ctor_3)
{
    Vector v(1, 2, 3);
    ASSERT_EQ(v.x(), 1);
    ASSERT_EQ(v.y(), 2);
    ASSERT_EQ(v.z(), 3);
}

TEST(vector, set_x)
{
    Vector v;
    v.set_x(1);
    ASSERT_EQ(v.x(), 1);
}

TEST(vector, set_y)
{
    Vector v;
    v.set_y(1);
    ASSERT_EQ(v.y(), 1);
}

TEST(vector, set_z)
{
    Vector v;
    v.set_z(1);
    ASSERT_EQ(v.z(), 1);
}

TEST(vector, add)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    Vector v3 = v1 + v2;
    ASSERT_EQ(v3.x(), 5);
    ASSERT_EQ(v3.y(), 7);
    ASSERT_EQ(v3.z(), 9);
}

TEST(vector, sub)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    Vector v3 = v1 - v2;
    ASSERT_EQ(v3.x(), -3);
    ASSERT_EQ(v3.y(), -3);
    ASSERT_EQ(v3.z(), -3);
}

TEST(vector, mul)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    Vector v3 = v1 * v2;
    ASSERT_EQ(v3.x(), -3);
    ASSERT_EQ(v3.y(), 6);
    ASSERT_EQ(v3.z(), -3);
}

TEST(vector, mul_int)
{
    Vector v1(1, 2, 3);
    Vector v2 = v1 * 2;
    ASSERT_EQ(v2.x(), 2);
    ASSERT_EQ(v2.y(), 4);
    ASSERT_EQ(v2.z(), 6);
}

TEST(vector, add_assign)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    v1 += v2;
    ASSERT_EQ(v1.x(), 5);
    ASSERT_EQ(v1.y(), 7);
    ASSERT_EQ(v1.z(), 9);
}

TEST(vector, sub_assign)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    v1 -= v2;
    ASSERT_EQ(v1.x(), -3);
    ASSERT_EQ(v1.y(), -3);
    ASSERT_EQ(v1.z(), -3);
}

TEST(vector, mul_assign)
{
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    v1 *= v2;
    ASSERT_EQ(v1.x(), -3);
    ASSERT_EQ(v1.y(), 6);
    ASSERT_EQ(v1.z(), -3);
}

TEST(vector, mul_assign_int)
{
    Vector v1(1, 2, 3);
    v1 *= 2;
    ASSERT_EQ(v1.x(), 2);
    ASSERT_EQ(v1.y(), 4);
    ASSERT_EQ(v1.z(), 6);
}