#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include "./ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPlainTextEdit* textEdit = nullptr;
    QWebEngineView* webPage;
    QLabel* label;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void update_WEB_page();

private slots:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QString filePath;
    bool file_entered;
    bool changed_after_saving;
    void save_to_file();
};
#endif // MAINWINDOW_H
