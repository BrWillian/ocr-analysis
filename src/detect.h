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

typedef struct{
    int classe;
    float x;
    float y;
    float width;
    float height;
}Char;


class Detect
{
public:

    static std::vector<Char> Detect_Plate(cv::Mat img);
    static void Init_Detection_Model(const char* cfg_path, const char* weight_path);
private:
    static inline network *net;
    static bool Compare_By_Length(const Char &a, const Char &b);
    static bool Compare_By_Height(const Char &a, const Char &b);
    static bool Is_Motorcycle(int cols, int rows);
    static void Build_Plate(std::vector<Char>* plate, int cols, int rows);
};

#endif // DETECT_H
