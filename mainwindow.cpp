#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
int pic = 1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_binaryTreeView = new BinaryTreeView(this);
    ui->comboBox_terminals->setIconSize(QSize(100, 100));
    for (int i = 0; i < 5; i++) {
        ui->comboBox_terminals->addItem(QIcon(m_binaryTreeView->v_pixmaps[i]), m_binaryTreeView->grammar[i]);
    }
    ui->listWidget_grammar->addItem("P:");
    map<vector<QString>, QString> grammar_map = m_binaryTreeView->get_grammar_map();
    map<int, vector<QString>> index_map = m_binaryTreeView->get_index_map();
    for (int i = m_binaryTreeView->mp_sz - 1; i >= 0; i--) {
        QString por = grammar_map[index_map[i]] + " -> ";
        vector<QString> v_pair = index_map[i];
        for (int j = 0; j < v_pair.size(); j++) {
            if (j + 1 == v_pair.size())
                por += v_pair[j];
            else
                por += v_pair[j] + " и ";
        }
        ui->listWidget_grammar->addItem(por);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_show_tree_clicked()
{
    vector<int> v;
    switch (pic = ui->spinBox_pic_num->value()) {
    case 1:
        m_binaryTreeView->buildTree(v = m_binaryTreeView->runAnalysis(m_binaryTreeView->drawPicture1(false)));
        break;
    case 2:
        m_binaryTreeView->buildTree(v = m_binaryTreeView->runAnalysis(m_binaryTreeView->drawPicture2(false)));
        break;
    case 3:
        m_binaryTreeView->buildTree(v = m_binaryTreeView->runAnalysis(m_binaryTreeView->drawPicture3(false)));
        break;
    default:
        break;
    }
    if (!v.empty()) {
        ui->label_info->setText("<font color='green' size='+2'>Выполнено успешно</font>");
    }
    else {
        ui->label_info->setText("<font color='red' size='+2'>ОШИБКА!</font>");
    }
}


void MainWindow::on_pushButton_apply_image_clicked()
{
    switch (pic = ui->spinBox_pic_num->value()) {
    case 1:
        m_binaryTreeView->drawPicture1(true);
        break;
    case 2:
        m_binaryTreeView->drawPicture2(true);
        break;
    case 3:
        m_binaryTreeView->drawPicture3(true);
        break;
    default:
        break;
    }
}

