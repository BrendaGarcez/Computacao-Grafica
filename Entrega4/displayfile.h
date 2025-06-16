#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <QPainter>
#include <QSet>
#include "matriz.h"
#include "coordenadas.h"

class Objeto;
class DisplayFile {
public:
    struct No {
        Objeto* obj;
        No* proximo;
    };

    No* inicio;

    DisplayFile();
    ~DisplayFile();
    void adicionar(Objeto* obj);
    void limpar();
    void desenharTodos(QPainter &painter, const QSet<QString> &tiposVisiveis, const Matriz &transformacao, const Window &window);
    Objeto* buscarPorNome(const QString& nome);
};

#endif


