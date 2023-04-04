#include "config-parser/libconfig-parser.hh"
#include <gtest/gtest.h>

std::unique_ptr<HittableList> parse(std::string config)
{
    return Config::parse_config("../tests/assets/" + config);
}

TEST(config_parser, parse_doube)
{
    std::istringstream line("1.0");
    double value;
    ASSERT_TRUE(Config::parse_double(line, value));
    ASSERT_EQ(value, 1.0);
}

TEST(config_parser, parse_doube_zero)
{
    std::istringstream line("0");
    double value;
    ASSERT_TRUE(Config::parse_double(line, value));
    ASSERT_EQ(value, 0);
}

TEST(config_parser, parse_doube_zero_float)
{
    std::istringstream line("0.0");
    double value;
    ASSERT_TRUE(Config::parse_double(line, value));
    ASSERT_EQ(value, 0.0);
}

TEST(config_parser, parse_double_negative)
{
    std::istringstream line("-1.0");
    double value;
    ASSERT_TRUE(Config::parse_double(line, value));
    ASSERT_EQ(value, -1.0);
}

TEST(config_parser, parse_double_invalid)
{
    std::istringstream line("invalid");
    double value;
    ASSERT_FALSE(Config::parse_double(line, value));

    std::string tok;
    line >> tok;
    ASSERT_EQ(tok, "invalid");
}

TEST(config_parser, file_not_found)
{
    ASSERT_EQ(parse("file_not_found.txt"), nullptr);
}

TEST (config_parser, simple_comments)
{
    ASSERT_EQ(parse("simple_comments.txt")->objects.size(), 0);
}

TEST(config_parser, simple_sphere)
{
    auto world = parse("simple_sphere.txt");

    ASSERT_NE(world, nullptr);
    ASSERT_EQ(world->objects.size(), 1);
    ASSERT_EQ(world->objects[0]->x(), 0);
    ASSERT_EQ(world->objects[0]->y(), 0);
    ASSERT_EQ(world->objects[0]->z(), -1);
} 

TEST(config_parser, invalid_sphere_1)
{
    ASSERT_EQ(parse("invalid_sphere_1.txt"), nullptr);
}

TEST(config_parser, invalid_sphere_2)
{
    ASSERT_EQ(parse("invalid_sphere_2.txt"), nullptr);
}

TEST(config_parser, invalid_sphere_3)
{
    ASSERT_EQ(parse("invalid_sphere_3.txt"), nullptr);
}

TEST(config_parser, simple_range)
{
    auto world = parse("simple_range.txt");

    ASSERT_NE(world, nullptr);

    ASSERT_EQ(world->objects.size(), 3);

    ASSERT_EQ(world->objects[0]->x(), -1);
    ASSERT_EQ(world->objects[0]->y(), 0);
    ASSERT_EQ(world->objects[0]->z(), -1);

    ASSERT_EQ(world->objects[1]->x(), 0);
    ASSERT_EQ(world->objects[1]->y(), 0);
    ASSERT_EQ(world->objects[1]->z(), -1);

    ASSERT_EQ(world->objects[2]->x(), 1);
    ASSERT_EQ(world->objects[2]->y(), 0);
    ASSERT_EQ(world->objects[2]->z(), -1);
} 

TEST(config_parser, sphere_range_invalid_1)
{
    ASSERT_EQ(parse("sphere_range_invalid.txt"), nullptr);
}

TEST(config_parser, sphere_range_invalid_2)
{
    ASSERT_EQ(parse("sphere_range_invalid_2.txt"), nullptr);
}

TEST(config_parser, sphere_range_invalid_3)
{
    ASSERT_EQ(parse("sphere_range_invalid_3.txt"), nullptr);
}

TEST(config_parser, sphere_range_invalid_4)
{
    ASSERT_EQ(parse("sphere_range_invalid_4.txt"), nullptr);
}