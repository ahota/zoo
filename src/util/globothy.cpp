#include "globothy.h"

// based on https://stackoverflow.com/a/8615450/4765406
std::vector<std::string> globothy(const std::string &pattern)
{
    glob_t glob_result;
    memset(&glob_result, 0, sizeof(glob_result));

    int glob_ret = glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
    if(glob_ret != 0) {
        globfree(&glob_result);
        std::cerr << "ERROR: glob failed, return value " << glob_ret;
        std::cerr << std::endl;
        // no exceptions here, hue hue hue
        return std::vector<std::string>(0);
    }

    std::vector<std::string> filenames;
    for(size_t i = 0; i < glob_result.gl_pathc; i++) {
        filenames.push_back(std::string(glob_result.gl_pathv[i]));
    }

    globfree(&glob_result);

    return filenames;
}
