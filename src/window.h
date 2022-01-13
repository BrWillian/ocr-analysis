#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <file.h>
#include <detect.h>
#include <QFileDialog>
#include <QStringListModel>
#include <QtWidgets>
#include <thread>
#include <annotation.h>
#include <opencv2/opencv.hpp>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    Ui::Window *ui;
    void SetQlabelBorder();
    void Display_Image(QString img_path);
    void Set_Plate_Pixmap(std::vector<QPixmap> plate_chars);
    void Clear_Label();
    void Set_Chars_LineEdit(std::vector<char> plate_chars);
    void Clear_LineEdit();
    bool Check_LineEdit();

private slots:
    void on_actionAbrir_4_triggered();
    void on_listView_doubleClicked(const QModelIndex &index);
    void keyPressEvent(QKeyEvent *event);
    void on_pushButton_clicked();
};

#endif // WINDOW_H
