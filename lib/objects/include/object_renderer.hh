#pragma once

#include <string>

#include "../../utils/libutils.hh"
#include "sphere.hh"

class Hittable;

/**
 * @brief A Singleton class that renders hittable objects onto a screen
 * 
 */
class ObjectRenderer : public Singleton<ObjectRenderer>
{
    friend class Singleton<ObjectRenderer>;

public:
    /**
     * @brief renders a hittable object onto the screen
     * by casting rays from the camera to the object
     * and using the hit method of the object to determine
     * if the ray hit the object
     * 
     * @param hittable the hittable object to render
     */
    void render(Hittable &hittable);

    /**
     * @brief is used to convert a double between 0 and 1 to an ascii character
     * that will simulate brightness of a pixel
     * 
     * @param value the value to convert
     * @return char the corresponding ascii character
     */
    static char normalize_to_ascii(double value);
    
    /**
     * @brief gets the screen object
     * 
     * @return Screen& the screen object
     */
    Screen &get_screen();


protected:
    ObjectRenderer() : screen_()
    {
        viewport_height_ = 2.0;
        viewport_width_ = screen_.get_ratio() * viewport_height_;
        focal_length_ = 1.0;

        distance_scaling_ = 0.5;

        origin_ = point3(0, 0, 0);
        horizontal_ = vec3(viewport_width_, 0, 0);
        vertical_ = vec3(0, viewport_height_, 0);
        lower_left_corner_ = origin_ - horizontal_ / 2 - vertical_ / 2 - vec3(0, 0, focal_length_);
    }

private:
    Screen screen_;
    double viewport_height_;
    double viewport_width_;
    double focal_length_;

    double distance_scaling_;

    point3 origin_;
    vec3 horizontal_;
    vec3 vertical_;
    point3 lower_left_corner_;
};