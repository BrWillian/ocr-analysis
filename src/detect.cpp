#include "detect.h"

Detect::Detect(const char* cfg_path, const char* weight_path)
{
    this->cfg_path = cfg_path;
    this->weight_path = weight_path;
    Init_Detection_Model();
}
Detect::~Detect(){

}
void Detect::Init_Detection_Model(){
    try {
        net = load_network_custom(const_cast<char*>(cfg_path.c_str()), const_cast<char*>(weight_path.c_str()),1, 1);
    } catch (const std::exception& err) {
        LOG(ERROR)<<err.what()<<std::endl;
        net = nullptr;
    }
}

