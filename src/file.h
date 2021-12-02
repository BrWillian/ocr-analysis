#ifndef FILE_H
#define FILE_H
#include <vector>
#include <fstream>

class File
{
public:
    // Constructor
    File();

    // Methods
    void List_Directory(std::string path);

    // Static Attributes
    inline static std::vector<std::string> list_of_imgs;
    inline static size_t npos = 0;
private:


};

#endif // FILE_H
