#ifndef COORDENADAS_H
#define COORDENADAS_H

#include <QPointF>

struct Window {
    float xmin = 0.0f;
    float xmax = 500.0f;
    float ymin = 0.0f;
    float ymax = 500.0f;
};

struct Viewport {
    float xmin = 0.0f;
    float xmax = 500.0f;
    float ymin = 0.0f;
    float ymax = 500.0f;
};

#endif
