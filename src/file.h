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

    // Static Attributes
    static std::vector<std::string> list_of_imgs;
    static size_t npos;
private:


};

#endif // FILE_H
