#include "object_renderer.hh"


#include <limits>

char ObjectRenderer::normalize_to_ascii(double val)
{
    if (val < 0.0)
        return ' ';
    std::string ascii = " .:-=+*#%@&$";

    int index = (int)(val * ascii.length());
    if (index >= (int)ascii.length())
        index = ascii.length() - 1;
    return ascii[ascii.length() - 1 - index];
}

Screen &ObjectRenderer::get_screen()
{
    return screen_;
}

void ObjectRenderer::render(Hittable &sphere)
{
    screen_.clear();
    for (int j = screen_.get_h() - 1; j >= 0; --j)
    {
        for (int i = 0; i < screen_.get_w(); ++i)
        {
            double u = double(i) / (screen_.get_w() - 1);
            double v = double(j) / (screen_.get_h() - 1);
            Ray r(origin_, lower_left_corner_ + horizontal_ * u + vertical_ * v - origin_);

            HitRecord rec;
            if (sphere.hit(r, 0, std::numeric_limits<double>::infinity(), rec))
            {
                //vec3 color = (rec.normal + vec3(1, 1, 1)) * 0.5 / 3;
                screen_.put_pixel(i, j, normalize_to_ascii(rec.t * distance_scaling_));
                continue;
            }
        }
    }

    screen_.display();
}