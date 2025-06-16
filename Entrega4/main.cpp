#include <QApplication>
#include <QStyleFactory>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(QStyleFactory::create("Fusion"));

    a.setStyleSheet(R"(
        QSpinBox {
            background-color: white;
            color: black;
            border: 1px solid gray;
            padding: 2px 4px;
        }

        QSpinBox::up-arrow, QSpinBox::down-arrow {
            width: 10px;
            height: 10px;
        }

        QMenuBar {
            background-color: white;
            color: black;
        }

        QMenuBar::item:selected {
            background-color: #f0f0f0;
        }

        QMenu {
            background-color: white;
            color: black;
            border: 1px solid gray;
        }

        QMenu::item {
            padding: 5px 20px;
        }

        QMenu::item:selected {
            background-color: #f0f0f0;
            color: black;
        }

        QCheckBox {
            color: black;
        }

        QCheckBox::indicator {
            width: 13px;
            height: 13px;
        }

        QCheckBox::indicator:unchecked {
            border: 1px solid black;
            background-color: white;
        }

        QCheckBox::indicator:checked {
            border: 1px solid black;
            background-color: black;
        }

        QMessageBox {
            background-color: white;
        }

        QMessageBox QLabel {
            color: black;
        }

        QMessageBox QPushButton {
            color: black;
            background-color: #f0f0f0;
            border: 1px solid gray;
            padding: 5px 10px;
        }

        QMessageBox QPushButton:hover {
            background-color: #dcdcdc;
        }

        QLabel {
            color: black;
        }

        QComboBox {
            background-color: white;
            color: black;
            border: 1px solid gray;
            padding: 4px;
        }

        QComboBox QAbstractItemView {
            background-color: white;
            color: black;
            selection-background-color: #f0f0f0;
        }

        QPushButton {
            background-color: #e0e0e0;
            color: black;
            border: 1px solid gray;
            padding: 6px 12px;
            font-size: 14px;
            font-weight: bold;
            border-radius: 4px;
        }

        QPushButton:hover {
            background-color: #d0d0d0;
        }
    )");

    MainWindow w;
    w.show();
    return a.exec();
}
