#include "parser.hh"

#include <cstdlib>

/**
 * @brief Parse a double from a line
 * and puts the token back if no double is found
 * 
 * @param line stringstream to be parsed
 * @param value reference to the double to be filled
 * @return true if a double is found
 * @return false if no double is found
 */
bool Config::parse_double(std::istringstream &line, double &value)
{
    std::string token;

    auto pos = line.tellg();

    if (!(line >> token))
    {
        line.seekg(pos);
        std::cerr << "Error: Could not parse double" << std::endl;
        return false;
    }

    if (atof(token.c_str()) || atoi(token.c_str()) || token == "0" || token == "0.0")
    {
        value = atof(token.c_str());
        return true;
    }
    line.seekg(pos);

    return false;
}

/**
 * @brief Parse a range from a line
 * a range is of the form: range( inf sup step )
 * or simply a double
 * 
 * @param line stringstream to be parsed
 * @param inf reference to the inferior limit
 * @param sup reference to the superior limit
 * @param step reference to the step
 * @return true if the range is parsed successfully
 * @return false otherwise
 */
bool Config::parse_range(std::istringstream &line, double &inf, double &sup, double &step)
{
    std::string token;

    bool is_range = !parse_double(line, inf);

    if (!is_range)
    {
        sup = inf;
        step = 1;
        return true;
    }

    
    
    if (!(line >> token))
    {
        std::cerr << "Error: Could not parse range attributes, tok not found" << std::endl;
        return false;
    }


    if (token != "range(")
    {

        std::cerr << "Error: Could not parse range attributes" << std::endl;
        return false;
    }

    if (!(line >> inf >> sup >> step))
    {

        std::cerr << "Error: Could not parse range attributes" << std::endl;
        return false;
    }

    line >> token;
    if (token != ")")
    {
        std::cerr << "Error: Could not parse range attributes" << std::endl;
        return false;
    }

    return true;
}

/**
 * @brief Parse a sphere from a stringstream
 * A sphere is of the form: sphere range range range double
 * respectively for the x, y, z coordinates and the radius
 * 
 * @param line the stringstream to be parsed
 * @param world the list of objects to be filled
 * @return true if the sphere is parsed successfully
 * @return false otherwise
 */
bool Config::parse_sphere(std::istringstream &line, std::unique_ptr<HittableList> &world)
{
    double infx, supx, stepx;
    double infy, supy, stepy;
    double infz, supz, stepz;

    double r;

    if (!parse_range(line, infx, supx, stepx))
        return false;
    if (!parse_range(line, infy, supy, stepy))
        return false;
    if (!parse_range(line, infz, supz, stepz))
        return false;
    if (!parse_double(line, r))
    {
        std::cerr << "Error: Could not parse sphere radius" << std::endl;
        return false;
    }

    for (double x = infx; x <= supx; x += stepx)
        for (double y = infy; y <= supy; y += stepy)
            for (double z = infz; z <= supz; z += stepz)
                world->add(std::make_shared<Sphere>(point3(x, y, z), r));

    return true;
}

/**
 * @brief Parse a config file
 * 
 * @param filename the name of the file to be parsed
 * @return std::unique_ptr<HittableList> the list of parsed objects
 */
std::unique_ptr<HittableList> Config::parse_config(std::string filename)
{
    auto res = std::make_unique<HittableList>();

    std::ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file: " << filename << std::endl;
        return nullptr;
    }


    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;

        iss >> token;

        if (token[0] == '#')
            continue;
        if (token == "sphere" && !parse_sphere(iss, res))
            return nullptr;

        if ((iss >> token))
        {
            std::cerr << "Error: Could not parse line: " << line << std::endl;
            return nullptr;
        }
    }


    return res;
}