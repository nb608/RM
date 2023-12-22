#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList()<<"力量");
    ui->treeWidget->addTopLevelItem(item);

    QStringList hh1;
    hh1<<"sdgflal"<<"hsdkjfdh";
    QTreeWidgetItem * h1 = new QTreeWidgetItem(hh1);
    item->addChild(h1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

