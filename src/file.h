#ifndef FILE_H
#define FILE_H
#include <vector>
#include <fstream>
#include <QStringList>
#include <QDir>
#include <sstream>

class File
{
public:
    // Constructor
    File();

    // Methods
    void List_Directory(std::string path);
    void Write_Annotation(std::string dir, std::string file_name, std::string annotation);

    // Static Attributes
    inline static std::vector<std::string> list_of_imgs;
    inline static size_t npos = 0;
private:


};

#endif // FILE_H
