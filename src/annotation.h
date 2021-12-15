#ifndef ANNOTATION_H
#define ANNOTATION_H
#include <string>
#include <QStringListModel>
#include <sstream>
#include <QDir>
#include <fstream>
#include <vector>
#include <detect.h>


class Annotation
{
public:
    static std::vector<Char> plate;
    static std::pair<int, int> img_shape;
    static void Build_Annotation(std::string filename);
    static void Get_Pos_Crop(std::vector<Char>* plate);
private:
    static std::string Yolo_Formart(int index, double x, double y, double w, double h);
    static std::string Remove_Stem(std::string filename);
};

#endif // ANNOTATION_H
