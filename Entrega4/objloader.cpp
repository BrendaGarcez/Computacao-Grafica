#include "objloader.h"
#include "libs/tiny_obj_loader.h"
#include <QDebug>
#include <set>

Objeto3D* ObjLoader::carregar(const QString& caminhoArquivo, const QString& nomeObjeto) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    bool ret = tinyobj::LoadObj(
        &attrib, &shapes, &materials, &warn, &err,
        caminhoArquivo.toStdString().c_str()
        );

    if (!warn.empty()) qDebug() << "[ObjLoader] Aviso:" << QString::fromStdString(warn);
    if (!err.empty()) qDebug() << "[ObjLoader] Erro:" << QString::fromStdString(err);
    if (!ret) {
        qDebug() << "[ObjLoader] Falha ao carregar:" << caminhoArquivo;
        return nullptr;
    }

    auto* objeto = new Objeto3D(nomeObjeto);

    // Carrega os vértices
    for (size_t i = 0; i < attrib.vertices.size(); i += 3) {
        float x = attrib.vertices[i];
        float y = attrib.vertices[i + 1];
        float z = attrib.vertices[i + 2];
        objeto->adicionarVertice(x, y, z);
    }

    std::set<std::pair<int, int>> arestasUnicas;

    for (const auto& shape : shapes) {
        size_t index_offset = 0;
        for (size_t f = 0; f < shape.mesh.num_face_vertices.size(); f++) {
            int fv = shape.mesh.num_face_vertices[f];
            std::vector<int> indices;

            for (int v = 0; v < fv; v++) {
                int vertex_index = shape.mesh.indices[index_offset + v].vertex_index;
                indices.push_back(vertex_index);
            }

            for (size_t i = 0; i < indices.size(); ++i) {
                int from = indices[i];
                int to = indices[(i + 1) % indices.size()];
                auto parOrdenado = std::minmax(from, to);
                if (arestasUnicas.insert(parOrdenado).second) {
                    objeto->adicionarAresta(from, to);
                }
            }

            objeto->adicionarFace(indices);
            index_offset += fv;
        }
    }

    return objeto;
}
