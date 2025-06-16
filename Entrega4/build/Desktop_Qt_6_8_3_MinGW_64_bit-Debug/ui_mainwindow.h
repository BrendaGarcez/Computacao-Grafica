/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "areadesenho.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalvar;
    QAction *actionSobre;
    QWidget *centralwidget;
    AreaDesenho *areaDesenho;
    QPushButton *botaoFechar;
    QCheckBox *checkPonto;
    QCheckBox *checkTriangulo;
    QCheckBox *checkReta;
    QComboBox *comboObjetos;
    QSlider *sliderTransX;
    QSlider *sliderTransY;
    QLabel *label;
    QSlider *sliderEscalaX;
    QSlider *sliderEscalaY;
    QLabel *label_2;
    QComboBox *comboPivo;
    QSlider *sliderRotacao;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSlider *sliderEscalaProporcional;
    QSpinBox *spinWindowXmin;
    QSpinBox *spinWindowYmax;
    QSpinBox *spinWindowXmax;
    QSpinBox *spinWindowYmin;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QSpinBox *spinViewportYmin;
    QLabel *label_15;
    QSpinBox *spinViewportXmin;
    QSpinBox *spinViewportYmax;
    QSpinBox *spinViewportXmax;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_Arquivo;
    QMenu *menu_Informa_es;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1094, 620);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName("actionAbrir");
        actionSalvar = new QAction(MainWindow);
        actionSalvar->setObjectName("actionSalvar");
        actionSobre = new QAction(MainWindow);
        actionSobre->setObjectName("actionSobre");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        areaDesenho = new AreaDesenho(centralwidget);
        areaDesenho->setObjectName("areaDesenho");
        areaDesenho->setGeometry(QRect(9, 19, 611, 531));
        areaDesenho->setStyleSheet(QString::fromUtf8("white"));
        areaDesenho->setFrameShape(QFrame::Shape::Box);
        areaDesenho->setFrameShadow(QFrame::Shadow::Sunken);
        botaoFechar = new QPushButton(centralwidget);
        botaoFechar->setObjectName("botaoFechar");
        botaoFechar->setGeometry(QRect(635, 520, 151, 29));
        botaoFechar->setStyleSheet(QString::fromUtf8("background-color: lightgray;\n"
"color: black;\n"
""));
        checkPonto = new QCheckBox(centralwidget);
        checkPonto->setObjectName("checkPonto");
        checkPonto->setGeometry(QRect(630, 20, 141, 26));
        checkTriangulo = new QCheckBox(centralwidget);
        checkTriangulo->setObjectName("checkTriangulo");
        checkTriangulo->setGeometry(QRect(630, 60, 151, 26));
        checkReta = new QCheckBox(centralwidget);
        checkReta->setObjectName("checkReta");
        checkReta->setGeometry(QRect(630, 100, 111, 26));
        comboObjetos = new QComboBox(centralwidget);
        comboObjetos->setObjectName("comboObjetos");
        comboObjetos->setGeometry(QRect(630, 150, 141, 31));
        sliderTransX = new QSlider(centralwidget);
        sliderTransX->setObjectName("sliderTransX");
        sliderTransX->setGeometry(QRect(630, 220, 160, 18));
        sliderTransX->setMinimum(-50);
        sliderTransX->setMaximum(50);
        sliderTransX->setOrientation(Qt::Orientation::Horizontal);
        sliderTransX->setTickPosition(QSlider::TickPosition::NoTicks);
        sliderTransY = new QSlider(centralwidget);
        sliderTransY->setObjectName("sliderTransY");
        sliderTransY->setGeometry(QRect(630, 250, 160, 18));
        sliderTransY->setMinimum(-50);
        sliderTransY->setMaximum(50);
        sliderTransY->setOrientation(Qt::Orientation::Horizontal);
        sliderTransY->setTickPosition(QSlider::TickPosition::NoTicks);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 190, 71, 20));
        sliderEscalaX = new QSlider(centralwidget);
        sliderEscalaX->setObjectName("sliderEscalaX");
        sliderEscalaX->setGeometry(QRect(630, 300, 160, 18));
        sliderEscalaX->setMinimum(5);
        sliderEscalaX->setMaximum(20);
        sliderEscalaX->setValue(10);
        sliderEscalaX->setOrientation(Qt::Orientation::Horizontal);
        sliderEscalaY = new QSlider(centralwidget);
        sliderEscalaY->setObjectName("sliderEscalaY");
        sliderEscalaY->setGeometry(QRect(630, 320, 160, 18));
        sliderEscalaY->setMinimum(5);
        sliderEscalaY->setMaximum(20);
        sliderEscalaY->setValue(10);
        sliderEscalaY->setOrientation(Qt::Orientation::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(680, 280, 63, 20));
        comboPivo = new QComboBox(centralwidget);
        comboPivo->setObjectName("comboPivo");
        comboPivo->setGeometry(QRect(630, 400, 82, 28));
        sliderRotacao = new QSlider(centralwidget);
        sliderRotacao->setObjectName("sliderRotacao");
        sliderRotacao->setGeometry(QRect(630, 460, 160, 18));
        sliderRotacao->setMinimum(-180);
        sliderRotacao->setMaximum(180);
        sliderRotacao->setValue(0);
        sliderRotacao->setOrientation(Qt::Orientation::Horizontal);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(810, 220, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(810, 250, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(800, 300, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(800, 320, 63, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(630, 440, 63, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(630, 370, 63, 20));
        sliderEscalaProporcional = new QSlider(centralwidget);
        sliderEscalaProporcional->setObjectName("sliderEscalaProporcional");
        sliderEscalaProporcional->setGeometry(QRect(630, 340, 160, 18));
        sliderEscalaProporcional->setMinimum(5);
        sliderEscalaProporcional->setMaximum(20);
        sliderEscalaProporcional->setValue(10);
        sliderEscalaProporcional->setOrientation(Qt::Orientation::Horizontal);
        spinWindowXmin = new QSpinBox(centralwidget);
        spinWindowXmin->setObjectName("spinWindowXmin");
        spinWindowXmin->setGeometry(QRect(810, 60, 61, 29));
        spinWindowXmin->setMaximum(2000);
        spinWindowYmax = new QSpinBox(centralwidget);
        spinWindowYmax->setObjectName("spinWindowYmax");
        spinWindowYmax->setGeometry(QRect(950, 60, 61, 29));
        spinWindowYmax->setMaximum(2000);
        spinWindowYmax->setValue(500);
        spinWindowXmax = new QSpinBox(centralwidget);
        spinWindowXmax->setObjectName("spinWindowXmax");
        spinWindowXmax->setGeometry(QRect(880, 60, 61, 29));
        spinWindowXmax->setMaximum(2000);
        spinWindowXmax->setValue(500);
        spinWindowYmin = new QSpinBox(centralwidget);
        spinWindowYmin->setObjectName("spinWindowYmin");
        spinWindowYmin->setGeometry(QRect(1020, 60, 61, 29));
        spinWindowYmin->setMaximum(2000);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(820, 40, 63, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(890, 40, 63, 20));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(960, 40, 63, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(1020, 40, 63, 20));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(860, 10, 161, 20));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1022, 140, 51, 20));
        spinViewportYmin = new QSpinBox(centralwidget);
        spinViewportYmin->setObjectName("spinViewportYmin");
        spinViewportYmin->setGeometry(QRect(950, 160, 61, 29));
        spinViewportYmin->setMaximum(2000);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(960, 140, 41, 20));
        spinViewportXmin = new QSpinBox(centralwidget);
        spinViewportXmin->setObjectName("spinViewportXmin");
        spinViewportXmin->setGeometry(QRect(810, 160, 61, 29));
        spinViewportXmin->setMaximum(2000);
        spinViewportYmax = new QSpinBox(centralwidget);
        spinViewportYmax->setObjectName("spinViewportYmax");
        spinViewportYmax->setGeometry(QRect(1020, 160, 61, 29));
        spinViewportYmax->setMaximum(2000);
        spinViewportYmax->setValue(500);
        spinViewportXmax = new QSpinBox(centralwidget);
        spinViewportXmax->setObjectName("spinViewportXmax");
        spinViewportXmax->setGeometry(QRect(880, 160, 61, 29));
        spinViewportXmax->setMaximum(2000);
        spinViewportXmax->setValue(500);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(890, 140, 63, 20));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(860, 110, 161, 20));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(820, 140, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1094, 25));
        menu_Arquivo = new QMenu(menuBar);
        menu_Arquivo->setObjectName("menu_Arquivo");
        menu_Informa_es = new QMenu(menuBar);
        menu_Informa_es->setObjectName("menu_Informa_es");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_Arquivo->menuAction());
        menuBar->addAction(menu_Informa_es->menuAction());
        menu_Arquivo->addAction(actionAbrir);
        menu_Arquivo->addAction(actionSalvar);
        menu_Informa_es->addAction(actionSobre);

        retranslateUi(MainWindow);
        QObject::connect(botaoFechar, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbrir->setText(QCoreApplication::translate("MainWindow", "&Abrir", nullptr));
        actionSalvar->setText(QCoreApplication::translate("MainWindow", "&Salvar e sair", nullptr));
        actionSobre->setText(QCoreApplication::translate("MainWindow", "&Sobre", nullptr));
        botaoFechar->setText(QCoreApplication::translate("MainWindow", "Fechar", nullptr));
        checkPonto->setText(QCoreApplication::translate("MainWindow", "Mostrar pontos", nullptr));
        checkTriangulo->setText(QCoreApplication::translate("MainWindow", "Mostrar poligonos", nullptr));
        checkReta->setText(QCoreApplication::translate("MainWindow", "Mostrar retas", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Transla\303\247\303\243o", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Escala", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Rota\303\247\303\243o", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Pivo", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "x min", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "x max", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "y min", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "y max", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Par\303\242metros da Window", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "y max", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "y min", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "x max", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Par\303\242metros da viewport", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "x min", nullptr));
        menu_Arquivo->setTitle(QCoreApplication::translate("MainWindow", "&Arquivo", nullptr));
        menu_Informa_es->setTitle(QCoreApplication::translate("MainWindow", "Detalhes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
