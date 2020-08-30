#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include "my_funca.cpp"
using namespace std;

QString txt_box = "C:/";
QString out_box = "C:/";
QString problems = "";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
        QString file_name = QFileDialog::getOpenFileName(this,"Open file",txt_box);
        ui->lineEdit->setText( file_name);
        txt_box = file_name;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
 //   txt_box = arg1;
}

void MainWindow::on_my_ok_clicked()
{
    //runmy function
    QString num_matrices = "1000 Matrices were computed!";
    QMessageBox my_box;
    my_box.setWindowTitle("Results");
    my_box.setFixedWidth((1000));
    QString nums_comp = QString::number(parse(txt_box.toStdString()));
    my_box.setText("Number of matrices computed : " +nums_comp + " \n" + problems);
    my_box.exec();
}


void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
     out_box = arg1;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getExistingDirectory(0, ("Select Output Folder"), QDir::currentPath());
    ui->lineEdit_3->setText( file_name);
    out_box = file_name;

}
