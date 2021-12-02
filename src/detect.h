#ifndef DETECT_H
#define DETECT_H
#include <string>
#include <vector>


class Detect
{
public:
    Detect();
private:
    std::string cfg_path;
    std::string weight_path;
    std::string class_path;

    std::vector<std::string> classes;

};

#endif // DETECT_H
