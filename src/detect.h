#ifndef DETECT_H
#define DETECT_H
#include <string>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>

#define LOG(x) std::cerr

extern "C" {
#include <darknet.h>
}


class Detect
{
public:
    Detect(const char* cfg_path, const char* weight_path);
    void Init_Detection_Model();

    virtual ~Detect();
private:
    std::string cfg_path;
    std::string weight_path;

    std::map<std::string, cv::Rect> *result;
    network *net;
};

#endif // DETECT_H
