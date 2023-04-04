#pragma once

#include "../../objects/libobjects.hh"
#include "../../utils/libutils.hh"

#include <fstream>
#include <sstream>
#include <string>

class Config
{
public:
    static bool parse_double(std::istringstream &line, double &value);

    static bool parse_range(std::istringstream &line, double &inf, double &sup, double &step);

    static bool parse_sphere(std::istringstream &line, std::unique_ptr<HittableList> &list);

    static std::unique_ptr<HittableList> parse_config(std::string filename);
};