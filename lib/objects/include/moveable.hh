#pragma once

#include "../../utils/libutils.hh"


/**
 * @brief Abstract class to represent a moveable object
 * 
 */
class Moveable
{
public:
    Moveable() = default;
    Moveable(point3 position) : position_(position) {}

    /**
     * @brief Get the position of the object
     * 
     * @return Vector 
     */
    point3 position() const { return position_; }

    double x() const { return position_.x(); }
    double y() const { return position_.y(); }
    double z() const { return position_.z(); }

    /**
     * @brief Set the position of the object
     * 
     * @param position the new position
     */
    void set_position(point3 position) { position_ = position; }

    /**
     * @brief Move the object by a certain vector
     * 
     * @param offset the vector to move the object by
     */
    void move(vec3 offset) { position_ += offset; }

    /**
     * @brief Move the object by a certain offset in the x, y or z axis
     * 
     * @param offset 
     */
    void move_x(double offset) { position_.set_x(position_.x() + offset); }

    /**
     * @brief Move the object by a certain offset in the x, y or z axis
     * 
     * @param offset 
     */
    void move_y(double offset) { position_.set_y(position_.y() + offset); }

    /**
     * @brief Move the object by a certain offset in the x, y or z axis
     * 
     * @param offset 
     */
    void move_z(double offset) { position_.set_z(position_.z() + offset); }

    /**
     * @brief Set the x coordinate of the object
     * 
     * @param x 
     */
    void set_x(double x) { position_.set_x(x); }


    /**
     * @brief Set the y coordinate of the object
     * 
     * @param y 
     */
    void set_y(double y) { position_.set_y(y); }

    /**
     * @brief Set the z coordinate of the object
     * 
     * @param z 
     */
    void set_z(double z) { position_.set_z(z); }

protected:
    point3 position_;
};