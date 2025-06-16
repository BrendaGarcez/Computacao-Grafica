#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "areadesenho.h"
#include "objeto.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void mostrarSobre();
    void aplicarTransformacoes();
    void atualizarComboObjetos();
    void resetarSliders();
    void carregarObjeto3D();

private:
    Ui::MainWindow *ui;
    AreaDesenho* areaDesenho;
};

#endif
