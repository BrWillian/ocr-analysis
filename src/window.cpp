#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    SetQlabelBorder();

    Detect::Init_Detection_Model("res/pr.cfg", "res/pr.weights");
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
    Clear_Label();
    Clear_LineEdit();
    QPixmap img(img_path);

    std::vector<QPixmap> pix_maps_of_chars;
    std::vector<char> plate_chars_vector;

    ui->label_8->setAlignment(Qt::AlignCenter);
    ui->label_8->setPixmap(img.scaled(ui->label_8->width(), ui->label_8->height(), Qt::KeepAspectRatio));

    cv::Mat img_plate = cv::imread(img_path.toStdString());

    const char classes[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // Detect plate and construct annotation
    auto chars = Detect::Detect_Plate(img_plate);

    if(chars.size() > 6){
        //Annotation::img_shape = std::make_pair(img.width(), img.height());
        //Annotation::plate = chars;
        //Annotation::Get_Pos_Crop(&chars);

        for(auto it=chars.begin(); it< chars.end(); it++){
            cv::Rect roi(cv::Point(it->x, it->y), cv::Point(it->width, it->height));
            cv::Mat img_plate_roi = img_plate(roi);

            QPixmap chr = QPixmap::fromImage(QImage((uchar*) img_plate_roi.data, img_plate_roi.cols, img_plate_roi.rows, img_plate_roi.step, QImage::Format_RGB888));

            pix_maps_of_chars.push_back(chr);
            plate_chars_vector.push_back(classes[it->classe]);
        }

        Set_Plate_Pixmap(pix_maps_of_chars);
        Set_Chars_LineEdit(plate_chars_vector);
    }

}
void Window::Set_Plate_Pixmap(std::vector<QPixmap> plate_char){

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(plate_char.at(0).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(plate_char.at(1).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->setPixmap(plate_char.at(2).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_4->setPixmap(plate_char.at(3).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_5->setPixmap(plate_char.at(4).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_6->setPixmap(plate_char.at(5).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));

    ui->label_7->setAlignment(Qt::AlignCenter);
    ui->label_7->setPixmap(plate_char.at(6).scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio));
}
void Window::Set_Chars_LineEdit(std::vector<char> plate_chars){
    ui->lineEdit->setText(QChar(plate_chars[0]));
    ui->lineEdit_2->setText(QChar(plate_chars[1]));
    ui->lineEdit_3->setText(QChar(plate_chars[2]));
    ui->lineEdit_4->setText(QChar(plate_chars[3]));
    ui->lineEdit_5->setText(QChar(plate_chars[4]));
    ui->lineEdit_6->setText(QChar(plate_chars[5]));
    ui->lineEdit_7->setText(QChar(plate_chars[6]));
}
void Window::Clear_LineEdit(){
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}
void Window::Clear_Label(){
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
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
            Annotation::Build_Annotation(File::list_of_imgs.at(File::npos));
            File::npos += 1;
            try {
                Display_Image(QString::fromStdString(File::list_of_imgs.at(File::npos)));
            } catch (const std::out_of_range& err) {
                std::cout<<err.what()<<std::endl;
            }
        }
        if(event->key() == Qt::Key_Left){
            if(File::npos >= 0){
                Annotation::Build_Annotation(File::list_of_imgs.at(File::npos));
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
