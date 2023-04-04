#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <memory>

/**
 * @brief A class that reprensents the screen, which is in this case the terminal
 * 
 */
class Screen
{
public:
    static long unsigned frame_count;

    Screen();
    Screen(int w, int h);

    /**
     * @brief Get the width of the screen
     * 
     * @return int 
     */
    int get_w();

    /**
     * @brief Get the height of the screen
     * 
     * @return int 
     */
    int get_h();

    /**
     * @brief Get the ratio of the dimensions of the screen
     * 
     * @return double 
     */
    double get_ratio();

    /**
     * @brief puts a char at a certain position on the screen
     * 
     * @param x the x position
     * @param y the y position
     * @param ascii the char to put
     */
    bool put_pixel(int x, int y, char ascii);

    /**
     * @brief Gets the char at a certain position on the screen
     * 
     * @param x the x position
     * @param y the y position
     * @return char the ascii char at the position
     */
    char get_pixel(int x, int y);

    /**
     * @brief Clears the screen with only whitespaces
     * 
     */
    void clear();

    /**
     * @brief Displays the screen on the terminal
     * 
     */
    void display();

private:
    int w_;
    int h_;

    double ratio_;

    std::unique_ptr<char[]> buf_;
};