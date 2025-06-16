#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "objeto3d.h"
#include <QString>

class ObjLoader {
public:
    static Objeto3D* carregar(const QString& caminhoArquivo, const QString& nomeObjeto);
};

#endif
