#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Inverse Calculator");
    w.show();
    return a.exec();
}
