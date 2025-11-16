#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    label = new QLabel(this);
    ui->setupUi(this);
    file_entered = false;
    changed_after_saving = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_WEB_page()
{
    changed_after_saving = true;
    label->clear();
    label->setText("Changes unsaved.");


    auto HTMLdata = textEdit->toPlainText();
    webPage->setHtml(HTMLdata);
}

void MainWindow::save_to_file()
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&file);
    out << textEdit->toPlainText();
    file.close();
    label->clear();
    label->setText("Saving to " + file.fileName() +  " successful.");
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_S)
    {
        if(!file_entered)
        {
            filePath = QFileDialog::getSaveFileName(nullptr, "Enter path to save your page", "/");
            filePath = filePath.append(".html");
            file_entered = true;
        }
        save_to_file();
    }
}
