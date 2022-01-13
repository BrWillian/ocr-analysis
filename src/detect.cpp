#include "detect.h"

void Detect::Init_Detection_Model(const char* cfg_path, const char* weight_path){
    try {
        net = load_network_custom(const_cast<char*>(cfg_path), const_cast<char*>(weight_path),1, 1);
    } catch (const std::exception& err) {
        LOG(ERROR)<<err.what()<<std::endl;
        net = nullptr;
    }
}
std::vector<Char> Detect::Detect_Plate(cv::Mat img){
#ifndef NDEBUG
    assert(!img.empty());
#endif

    image im = make_image(img.cols, img.rows, 3);
    for (int c=0; c < img.channels(); c++) {
        for (int h=0;h<img.rows; h++) {
            for (int w=0; w<img.cols; w++) {
                int dst = w + img.cols * h + img.cols * img.rows * c;
                im.data[dst] = static_cast<float>(img.ptr<unsigned char>(h)[w * img.channels() + c] / 255.0);
            }
        }
    }

    image sized;


    if(net->w == im.w && net->h == im.h){
        sized = make_image(im.w, im.h, im.c);
        memcpy(sized.data, im.data, im.w * im.h * im.c * sizeof(float));
    }else {
        sized = resize_image(im, net->w, net->h);
    }

    layer l = net->layers[net->n - 1];

    float *im_sized = sized.data;

    network_predict(*net, im_sized);

    int boxes = 0;

    detection *detections = get_network_boxes(net, im.w, im.h, static_cast<float>(0.1), 0.5, nullptr, 1, &boxes, 0);

    do_nms_obj(detections, boxes, l.classes, static_cast<float>(0.45));

    std::vector<Char> plate;
    std::vector<Char> plate_crop;

    for (int i=0; i< boxes; i++) {
        int _class = -1;
        for (int j = 0; j < l.classes; j++) {
            if(detections[i].prob[j] > 0.01) if(_class < 0) _class = j;
        }
        if(_class >= 0){
            box b = detections[i].bbox;

            int x = (b.x - b.w / 2.) * im.w;
            int w = (b.x + b.w / 2.) * im.w;
            int y = (b.y - b.h / 2.) * im.h;
            int h = (b.y + b.h / 2.) * im.h;

            x < 0 ? x = 0 : x;
            w > im.w - 1 ? w = im.w - 1 : w;
            y < 0 ? y = 0 : y;
            h > im.h - 1 ? h = im.h - 1 : h;

            Char chr;
            chr.x = b.x;
            chr.y = b.y;
            chr.width = b.w;
            chr.height = b.h;
            chr.classe = _class;

            plate.push_back(chr);
        }
    }

    Detect::Build_Plate(&plate, img.cols, img.rows);

    free_detections(detections, boxes);
    free_image(im);
    free_image(sized);

    return plate;
}
bool Detect::Compare_By_Length(const Char &a, const Char &b){
    return a.x < b.x;
}
bool Detect::Compare_By_Height(const Char &a, const Char &b){
    return a.y < b.y;
}
bool Detect::Is_Motorcycle(int cols, int rows){
    if(cols < rows * 1.4){
       return true;
    }
    return false;
}
void Detect::Build_Plate(std::vector<Char>* plate, int cols, int rows){
    std::sort(plate->begin(), plate->end(), Detect::Compare_By_Length);

    if(Detect::Is_Motorcycle(cols, rows)){
        std::vector<Char> topRow;
        std::vector<Char> bottomRow;

        std::sort(plate->begin(), plate->end(), Detect::Compare_By_Height);

        for (size_t k = 0; k < plate->size(); k++) {
            if (k < 3){
                topRow.push_back(plate->at(k));
            }else {
                bottomRow.push_back(plate->at(k));
            }
        }

        plate->clear();

        std::sort(topRow.begin(), topRow.end(), Detect::Compare_By_Length);
        std::sort(bottomRow.begin(), bottomRow.end(), Detect::Compare_By_Length);

        for (auto a: topRow) {
            plate->push_back(a);
        }
        for (auto a: bottomRow){
            plate->push_back(a);
        }
    }
}
