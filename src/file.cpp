#include "file.h"

File::File()
{

}
void File::List_Directory(std::string path){
    list_of_imgs.clear();
    QStringList nameFilter;
    nameFilter << "*.png" << "*.jpg" << "*.gif" << "*.jpeg";
    QDir dir(QString::fromStdString(path));
    dir.setSorting(QDir::Name);
    dir.setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    dir.setNameFilters(nameFilter);

    foreach(const QFileInfo& fi, dir.entryList())
    {
        if(!QFileInfo::exists(QString::fromStdString(path)+QDir::separator()+fi.completeBaseName()+".txt")){
            QString strtmp = QString::fromStdString(path)+"/"+fi.fileName();
            list_of_imgs.push_back(strtmp.toStdString());
        }
    }
}
