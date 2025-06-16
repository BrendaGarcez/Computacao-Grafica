#include "areadesenho.h"
#include <QDebug>
#include <QMessageBox>
#include "poligono.h"
#include <QCheckBox>
#include "reta.h"

void AreaDesenho::configurarCheckboxes(QCheckBox* p, QCheckBox* r, QCheckBox* t) {
    checkPonto = p;
    checkReta = r;
    checkTriangulo = t;
}

AreaDesenho::AreaDesenho(QWidget *parent)
    : QFrame(parent),
    matrizSCN(3, 3),
    matrizViewport(3, 3),
    matrizTotal(3, 3)
{
    this->setStyleSheet("background-color: white;");

    // CASA
    displayFile.adicionar(new Poligono("parede", {
                                                     {200, 800, 1}, {600, 800, 1}, {600, 400, 1}, {200, 400, 1}
                                                 }));

    displayFile.adicionar(new Poligono("telhado", {
                                                      {200, 400, 1}, {600, 400, 1}, {400, 200, 1}
                                                  }));

    displayFile.adicionar(new Poligono("porta", {
                                                    {360, 800, 1}, {440, 800, 1}, {440, 640, 1}, {360, 640, 1}
                                                }));

    displayFile.adicionar(new Poligono("janela_esq", {
                                                         {240, 720, 1}, {320, 720, 1}, {320, 640, 1}, {240, 640, 1}
                                                     }));

    displayFile.adicionar(new Poligono("janela_dir", {
                                                         {480, 720, 1}, {560, 720, 1}, {560, 640, 1}, {480, 640, 1}
                                                     }));

    // RUA
    displayFile.adicionar(new Poligono("rua", {
                                                  {0, 1000, 1}, {1000, 1000, 1}, {1000, 900, 1}, {0, 900, 1}
                                              }));

    displayFile.adicionar(new Reta("faixa", 0, 950, 1000, 950));

    // SOL
    displayFile.adicionar(new Poligono("sol", {
                                                  {100, 200, 1}, {140, 220, 1}, {180, 200, 1}, {190, 160, 1},
                                                  {180, 120, 1}, {140, 100, 1}, {100, 120, 1}, {90, 160, 1}
                                              }));



    window.xmin = 0.0f;
    window.xmax = 100.0f;
    window.ymin = 100.0f;
    window.ymax = 0.0f;

    viewport.xmin = 0.0f;
    viewport.xmax = 1000.0f;
    viewport.ymin = 0.0f;
    viewport.ymax = 1000.0f;


    recalcularMatrizes();
}

void AreaDesenho::recalcularMatrizes() {
    /*
    viewport.xmax = width();
    viewport.ymax = height();
    */
    Matriz translacaoParaOrigem = Matriz::translacao(-window.xmin, -window.ymin);

    float window_width = window.xmax - window.xmin;
    float window_height = window.ymax - window.ymin;
    Matriz escalaParaNormalizado = Matriz::escala(2.0f / window_width, 2.0f / window_height);

    Matriz translacaoParaCentroNormalizado = Matriz::translacao(-1.0f, -1.0f);

    matrizSCN = translacaoParaCentroNormalizado * escalaParaNormalizado * translacaoParaOrigem;

    float viewport_width = viewport.xmax - viewport.xmin;
    float viewport_height = viewport.ymax - viewport.ymin;

    matrizViewport = Matriz(3, 3, 0.0f);
    matrizViewport[0][0] = viewport_width / 2.0f;
    matrizViewport[0][2] = viewport.xmin + viewport_width / 2.0f;

    matrizViewport[1][1] = -viewport_height / 2.0f;
    matrizViewport[1][2] = viewport.ymin + viewport_height / 2.0f;
    matrizViewport[2][2] = 1.0f;

    matrizTotal = matrizViewport * matrizSCN;
}

void AreaDesenho::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSet<QString> tiposVisiveis;

    if (checkPonto && checkPonto->isChecked())
        tiposVisiveis.insert("Ponto");

    if (checkReta && checkReta->isChecked())
        tiposVisiveis.insert("Reta");

    if (checkTriangulo && checkTriangulo->isChecked())
        tiposVisiveis.insert("Poligono");

    DisplayFile::No* atual = displayFile.inicio;

    while (atual) {
        const QString& tipo = atual->obj->tipo;

        if (tipo == "Objeto3D") {
            painter.setPen(QColor(255, 140, 0));
            painter.setBrush(Qt::NoBrush);
            atual->obj->desenhar(painter, matrizTotal, window);

        } else if (tiposVisiveis.contains(tipo)) {
            if (tipo == "Ponto")      painter.setPen(Qt::blue);
            else if (tipo == "Reta")  painter.setPen(Qt::black);
            else if (tipo == "Poligono") painter.setPen(Qt::green);

            atual->obj->desenhar(painter, matrizTotal, window);
        }

        atual = atual->proximo;
    }

    // Moldura vermelha da viewport
    QPen moldura(Qt::red);
    moldura.setWidth(2);
    painter.setPen(moldura);
    painter.drawRect(viewport.xmin, viewport.ymin,
                     viewport.xmax - viewport.xmin,
                     viewport.ymax - viewport.ymin);
}


DisplayFile* AreaDesenho::getDisplayFile() {
    return &displayFile;
}



