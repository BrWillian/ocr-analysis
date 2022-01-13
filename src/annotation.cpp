#include "annotation.h"

std::string Annotation::Yolo_Formart(int index, double x, double y, double w, double h){
    std::string result = std::to_string(index) + " " + std::to_string(x) \
            + " " + std::to_string(y) + " " + std::to_string(w) \
                                   + " " + std::to_string(h) + "\n";

    std::replace(result.begin(), result.end(), ',', '.');

    return result;
}

void Annotation::Build_Annotation(std::string filename){
    if(plate.size() > 1){
        std::ofstream outfile;

        filename = Remove_Stem(filename);

        outfile.open(filename+".txt", std::ios_base::out);

        if(outfile.is_open() && outfile.good()){
            for(auto &it: plate){
                outfile << Annotation::Yolo_Formart(it.classe, it.x, it.y, it.width, it.height);
            }
            outfile.close();
        }
    }
}
std::string Annotation::Remove_Stem(std::string str)
{
    const size_t period_idx = str.rfind('.');
    if (std::string::npos != period_idx)
    {
        str.erase(period_idx);
    }
    return str;
}
void Annotation::Get_Pos_Crop(std::vector<Char>* plate){

    const int width = img_shape.first;
    const int height = img_shape.second;
    for(auto &p: *plate){
        int x = (p.x - p.width / 2.) * width;
        int w = (p.x + p.width / 2.) * width;
        int y = (p.y - p.height / 2.) * height;
        int h = (p.y + p.height / 2.) * height;

        x < 0 ? x = 0 : x;
        w > width - 1 ? w = width - 1 : w;
        y < 0 ? y = 0 : y;
        h > height - 1 ? h = height - 1 : h;

        p.x = x;
        p.y = y;
        p.width = w + 1;
        p.height = h + 1;
    }
}
