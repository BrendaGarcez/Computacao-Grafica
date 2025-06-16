#ifndef AREADESENHO_H
#define AREADESENHO_H

#include <QFrame>
#include <QPainter>
#include <QList>
#include "objeto.h"
#include "ponto.h"
#include "displayfile.h"
#include <QCheckBox>
#include "coordenadas.h"


class AreaDesenho : public QFrame
{
    Q_OBJECT

public:
    explicit AreaDesenho(QWidget *parent = nullptr);
    void configurarCheckboxes(QCheckBox* ponto, QCheckBox* reta, QCheckBox* triangulo);
    DisplayFile* getDisplayFile();
    Window window;
    Viewport viewport;
    void recalcularMatrizes();



protected:
    void paintEvent(QPaintEvent *event) override;

private:
    DisplayFile displayFile;

    QCheckBox* checkPonto = nullptr;
    QCheckBox* checkReta = nullptr;
    QCheckBox* checkTriangulo = nullptr;
    Matriz matrizSCN;
    Matriz matrizViewport;
    Matriz matrizTotal;

};

#endif

