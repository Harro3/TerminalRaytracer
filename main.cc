#include "utils/libutils.hh"
#include "objects/libobjects.hh"

#include <cmath>

#include "config-parser/libconfig-parser.hh"

/**
 * \brief Main function
 * 
 * \return int 
 */
int main()
{

    auto world = Config::parse_config("../config.txt");


    while (true)
    {
        ObjectRenderer::instance()->render(*world);
        for (auto& sphere : world->objects)
        {
            double t = sin(0.02 * Screen::frame_count + (sphere->x() + sphere->y()) * M_PI) * 0.75;
            sphere.get()->set_z(t - 1.45);
        }

        usleep(20000);
    }
 
}