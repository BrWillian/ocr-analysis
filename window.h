#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <file.h>
#include <QFileDialog>
#include <QStringListModel>
#include <QtWidgets>
#include <thread>
#include <iostream>

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

private slots:
    void on_actionAbrir_4_triggered();
    void on_listView_doubleClicked(const QModelIndex &index);
    void keyPressEvent(QKeyEvent *event);
};

#endif // WINDOW_H
