#include <gtest/gtest.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <memory>

#include "utils/libutils.hh"

Screen s;

TEST(screen, ctor_window)
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    int w = size.ws_col;
    int h = size.ws_row;

    ASSERT_EQ(s.get_h(), h);
    ASSERT_EQ(s.get_w(), w);
}

TEST(screen, put_extreme_1)
{
    ASSERT_TRUE(s.put_pixel(0, 0, 'a'));
}

TEST(screen, put_extreme_2)
{
    ASSERT_TRUE(s.put_pixel(s.get_w() - 1, s.get_h() - 1, 'a'));
}

TEST(screen, put_extreme_3)
{
    ASSERT_FALSE(s.put_pixel(s.get_w(), s.get_h(), 'a'));
}

TEST(screen, put_extreme_4)
{
    ASSERT_FALSE(s.put_pixel(-1, -1, 'a'));
}



TEST(screen, get_extreme_2)
{
    s.clear();
    ASSERT_EQ(s.get_pixel(s.get_w() - 1, s.get_h() - 1), ' ');
}

TEST(screen, get_extreme_3)
{
    ASSERT_EQ(s.get_pixel(s.get_w(), s.get_h()), 0);
}

TEST(screen, get_extreme_4)
{
    ASSERT_EQ(s.get_pixel(-1, -1), 0);
}

TEST(screen, set_get_pixel)
{
    ASSERT_TRUE(s.put_pixel(0, 0, 'a'));
    ASSERT_EQ(s.get_pixel(0, 0), 'a'); 
}

TEST(screen, set_get_pixel_2)
{
    ASSERT_TRUE(s.put_pixel(s.get_w() - 1, s.get_h() - 1, 'a'));
    ASSERT_EQ(s.get_pixel(s.get_w() - 1, s.get_h() - 1), 'a'); 
}