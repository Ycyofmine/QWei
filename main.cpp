#include "mainwindow.h"

#include <QApplication>
#include <QFile>

/************************
* @file main.cpp
* @brief 主窗口
*
* @author Ycyofmine
* @date 2025/02/24
* @history
************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QIODevice::ReadOnly | QIODevice::Text)) // 添加Text模式自动处理编码
    {
        qDebug() << "Successfully loaded QSS from:" << qss.fileName();
        QString style = QString::fromUtf8(qss.readAll());
        qApp->setStyleSheet(style); // qApp指向全局QApplication实例
        qss.close();
    }
    else
    {
        qWarning() << "Failed to open QSS file:" << qss.errorString();
    }


    MainWindow w;
    w.show();
    return a.exec();
}
