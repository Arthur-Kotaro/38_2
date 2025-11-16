#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Ui::MainWindow caller;
    caller.setupUi(&w);
    w.textEdit = caller.plainTextEdit;
    w.webPage = caller.webEngineView;
    w.label = caller.label;
    w.show();
    return a.exec();
}
