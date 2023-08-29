#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QThread>
#include "audio_decode.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSlider *slider;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *select;

    QString source_file;

    void selectFile();
    void playAudio();

    QThread *decode_thread;
    AudioDecod *do_decode;

private:
    Ui::MainWindow *ui;
    //    QThread *decode_thread;

signals:
    void sigStartPlay(QString file);

};

#endif // MAINWINDOW_H
