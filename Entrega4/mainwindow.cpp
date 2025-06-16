#include "objeto3d.h"
#include "matriz3d.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areadesenho.h"
#include "matriz.h"
#include <QMessageBox>
#include <QFileDialog>
#include "objloader.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    areaDesenho = findChild<AreaDesenho*>("areaDesenho");

    connect(ui->botaoCarregarOBJ, &QPushButton::clicked, this, &MainWindow::carregarObjeto3D);

    ui->comboEixoRotacao->clear();
    ui->comboEixoRotacao->addItems({"X", "Y", "Z"});
    ui->comboEixoRotacao->setCurrentText("Z");

    connect(ui->comboEixoRotacao, &QComboBox::currentTextChanged, this, [=](const QString&) {
        ui->sliderRotacao->setValue(0);
        aplicarTransformacoes();
    });

    connect(ui->spinWindowXmin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->window.xmin = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinWindowXmax, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->window.xmax = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinWindowYmin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->window.ymin = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinWindowYmax, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->window.ymax = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinViewportXmin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->viewport.xmin = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinViewportXmax, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->viewport.xmax = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinViewportYmin, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->viewport.ymin = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    connect(ui->spinViewportYmax, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value){
        areaDesenho->viewport.ymax = value;
        areaDesenho->recalcularMatrizes();
        areaDesenho->update();
    });

    ui->spinWindowXmin->setValue(areaDesenho->window.xmin);
    ui->spinWindowXmax->setValue(areaDesenho->window.xmax);
    ui->spinWindowYmin->setValue(areaDesenho->window.ymin);
    ui->spinWindowYmax->setValue(areaDesenho->window.ymax);

    ui->spinViewportXmin->setValue(areaDesenho->viewport.xmin);
    ui->spinViewportXmax->setValue(areaDesenho->viewport.xmax);
    ui->spinViewportYmin->setValue(areaDesenho->viewport.ymin);
    ui->spinViewportYmax->setValue(areaDesenho->viewport.ymax);

    connect(ui->actionAbrir, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Abrir", "Funcionalidade ainda não implementada.");
    });

    connect(ui->actionSalvar, &QAction::triggered, this, []() {
        QMessageBox::information(nullptr, "Salvar e Sair", "Ainda não implementado.");
    });

    connect(ui->actionSobre, &QAction::triggered, this, &MainWindow::mostrarSobre);

    areaDesenho->configurarCheckboxes(ui->checkPonto, ui->checkReta, ui->checkTriangulo);

    connect(ui->checkPonto, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkReta, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));
    connect(ui->checkTriangulo, &QCheckBox::checkStateChanged, areaDesenho, QOverload<>::of(&QWidget::update));

    connect(ui->sliderTransX, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderTransY, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderEscalaX, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderEscalaY, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderRotacao, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);
    connect(ui->sliderEscalaProporcional, &QSlider::valueChanged, this, &MainWindow::aplicarTransformacoes);

    connect(ui->comboObjetos, &QComboBox::currentTextChanged, this, [=]() {
        resetarSliders();
        aplicarTransformacoes();
    });

    atualizarComboObjetos();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::mostrarSobre() {
    QMessageBox::about(this, "Sobre", "teste");
}

void MainWindow::atualizarComboObjetos() {
    ui->comboObjetos->clear();
    DisplayFile::No* atual = areaDesenho->getDisplayFile()->inicio;

    while (atual) {
        ui->comboObjetos->addItem(atual->obj->nome);
        atual = atual->proximo;
    }
}

void MainWindow::resetarSliders() {
    ui->sliderTransX->setValue(0);
    ui->sliderTransY->setValue(0);
    ui->sliderEscalaX->setValue(10);
    ui->sliderEscalaY->setValue(10);
    ui->sliderRotacao->setValue(0);
    ui->sliderEscalaProporcional->setValue(10);
}

void MainWindow::aplicarTransformacoes() {
    QString nomeSelecionado = ui->comboObjetos->currentText();
    if (nomeSelecionado.isEmpty()) return;

    Objeto* obj = areaDesenho->getDisplayFile()->buscarPorNome(nomeSelecionado);
    if (!obj) return;

    Objeto3D* obj3d = dynamic_cast<Objeto3D*>(obj);
    bool eh3d = (obj3d != nullptr);

    float dx = ui->sliderTransX->value();
    float dy = ui->sliderTransY->value();
    float dz = 0.0f;

    float sx, sy, sz;
    if (ui->sliderEscalaProporcional->isVisible()) {
        sx = sy = sz = ui->sliderEscalaProporcional->value() / 10.0f;
    } else {
        sx = ui->sliderEscalaX->value() / 10.0f;
        sy = ui->sliderEscalaY->value() / 10.0f;
        sz = 1.0f;
    }

    float angulo = ui->sliderRotacao->value();

    QPointF centro = obj->centro();
    float px = centro.x();
    float py = centro.y();
    float pz = (eh3d ? obj->getCentroZ() : 0.0f);

    if (eh3d) {
        auto T = Matriz3D::translacao(dx, dy, dz);
        auto S = Matriz3D::escala(sx, sy, sz);

        QString eixo = ui->comboEixoRotacao->currentText();
        Matriz3D R;

        if (eixo == "X") {
            R = Matriz3D::rotacaoX(angulo, py, pz);
        } else if (eixo == "Y") {
            R = Matriz3D::rotacaoY(angulo, px, pz);
        } else {
            R = Matriz3D::rotacaoZ(angulo, px, py, pz);
        }

        auto composta = T * R * S;
        obj3d->aplicarTransformacao(composta);

    } else {
        float cx = centro.x();
        float cy = centro.y();

        auto Ts1 = Matriz::translacao(-cx, -cy);
        auto S   = Matriz::escala(sx, sy);
        auto Ts2 = Matriz::translacao(cx, cy);
        auto R   = Matriz::rotacao(angulo, px, py);
        auto T3  = Matriz::translacao(dx, dy);
        auto composta = T3 * R * Ts2 * S * Ts1;

        obj->aplicarTransformacao(composta);
    }

    areaDesenho->update();
}

void MainWindow::carregarObjeto3D() {
    QString arquivo = QFileDialog::getOpenFileName(
        this,
        "Abrir arquivo OBJ",
        QDir::homePath(),
        "OBJ Files (*.obj)"
        );

    if (arquivo.isEmpty()) {
        qDebug() << "Nenhum arquivo selecionado.";
        return;
    }

    if (!QFile::exists(arquivo)) {
        qDebug() << "Arquivo não existe:" << arquivo;
        return;
    }

    QString nome = QFileInfo(arquivo).baseName();
    Objeto3D* modelo = ObjLoader::carregar(arquivo, nome);
    if (!modelo) {
        qDebug() << "Falha ao carregar modelo OBJ.";
        return;
    }

    PontoHomogeneo centro = modelo->calcularCentro();
    //qDebug() << "[DEBUG] Centro do modelo:" << centro[0] << centro[1];

    modelo->transladar(-centro[0], -centro[1]);

    float tamanho = modelo->maiorDistanciaDoCentro();
    //qDebug() << "[DEBUG] Maior distância do centro:" << tamanho;

    if (tamanho > 300.0f) {
        float fator = 200.0f / tamanho;
        modelo->escalar(fator);
    }

    auto flipY = Matriz3D::escala(1.0f, -1.0f, 1.0f);
    modelo->aplicarTransformacao(flipY);
    modelo->setPontosOriginais(modelo->getPontos());

    areaDesenho->getDisplayFile()->adicionar(modelo);
    atualizarComboObjetos();
    areaDesenho->update();

    qDebug() << "objeto carregado:" << nome;
}




