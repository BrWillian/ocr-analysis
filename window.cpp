#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    SetQlabelBorder();
}

Window::~Window()
{
    delete ui;
}

void Window::SetQlabelBorder(){
    ui->label->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_2->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_3->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_4->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_5->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_6->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_7->setStyleSheet("border-radius: 5px; background: white;");
    ui->label_8->setStyleSheet("border-radius: 5px; background: white;");
}
void Window::on_actionAbrir_4_triggered(){
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    File *file = new File();

    if(!(path.toStdString() == ""))
    {
        std::thread t1(&File::List_Directory, file, path.toStdString());
        t1.join();

        QStringList list;

        for(auto it = File::list_of_imgs.begin(); it != File::list_of_imgs.end(); it++)
        {
            list << QString::fromStdString(*it);
        }
        ui->listView->setModel(new QStringListModel(list));
    }

    if(!(File::list_of_imgs.empty()))
    {
        File::npos = 0;
        QString strtmp = QString::fromStdString(File::list_of_imgs.at(File::npos));
        Display_Image(strtmp);
        ui->label_8->setStyleSheet("background: transparent;");
        QModelIndex ind = ui->listView->model()->index(int(File::npos), 0);
        ui->listView->setCurrentIndex(ind);
        ui->listView->selectionModel()->select(ind, QItemSelectionModel::Select);
    }
}
void Window::Display_Image(QString img_path){
    QPixmap img(img_path);
    ui->label_8->setAlignment(Qt::AlignCenter);
    ui->label_8->setPixmap(img.scaled(ui->label_8->width(), ui->label_8->height(), Qt::KeepAspectRatio));
}

void Window::on_listView_doubleClicked(const QModelIndex &index)
{
    Display_Image(index.data().toString());
    File::npos = index.row();
}
void Window::keyPressEvent(QKeyEvent *event){
    if(!File::list_of_imgs.empty()){
        std::string img_path;
        if(event->key() == Qt::Key_Right){
            File::npos += 1;
            try {
                Display_Image(QString::fromStdString(File::list_of_imgs.at(File::npos)));
            } catch (const std::out_of_range& err) {
                std::cout<<err.what()<<std::endl;
            }
        }
        if(event->key() == Qt::Key_Left){
            if(File::npos >= 0){
                File::npos -= 1;
            }
            try {
                Display_Image(QString::fromStdString(File::list_of_imgs.at(File::npos)));
            } catch (const std::out_of_range& err) {
                std::cout<<err.what()<<std::endl;
            }

        }

        QModelIndex index = ui->listView->model()->index(File::npos, 0);
        ui->listView->setCurrentIndex(index);
        ui->listView->selectionModel()->select(index, QItemSelectionModel::Select);
    }
}
