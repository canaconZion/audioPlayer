#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    slider = ui->slider;
    play = ui->play;
    stop = ui->stop;
    select = ui->select;

    connect(select,QPushButton::clicked,this,&MainWindow::selectFile);
    connect(play, QPushButton::clicked,this,&MainWindow::playAudio);

    decode_thread = new QThread;
    do_decode = new AudioDecod;
    do_decode->moveToThread(decode_thread);

    connect(decode_thread, &QThread::finished, do_decode, &QObject::deleteLater);
    connect(this, SIGNAL(sigStartPlay(QString)), do_decode, SLOT(decodeThread(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFile()
{
    QString source_path = "D:/video/videos";
    QString s = QFileDialog::getOpenFileName(
                this, QStringLiteral("选择要播放的文件"),
                source_path,
                QStringLiteral("视频文件 (*.flv *.rmvb *.avi *.MP4 *.mkv);;") + QStringLiteral("音频文件 (*.mp3 *.wma *.wav);;") + QStringLiteral("所有文件 (*.*)"));
    if (!s.isEmpty())
    {
        source_file = s;
        qDebug() << source_file;

    }
}

void MainWindow::playAudio()
{
    decode_thread->start();
    emit sigStartPlay(source_file);
    play->setEnabled(false);

}

