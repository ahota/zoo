#include "libnameothy.h"

std::pair<std::string, std::string> libnameothy(std::string &path)
{
    // hue, https://stackoverflow.com/a/4318543/4765406
    std::string bn(basename(&path[0]));
    
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ts(bn);
    while(std::getline(ts, token, '.')) {
        tokens.push_back(token);
    }

    std::string libname(tokens[0].substr(3));
    // in a REAL project this would be aliased with using
    return std::pair<std::string, std::string>(
            libname,
            (char)(std::toupper(libname[0])) + libname.substr(1)
    );
}
