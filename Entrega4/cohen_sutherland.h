#ifndef COHEN_SUTHERLAND_H
#define COHEN_SUTHERLAND_H

#include "coordenadas.h"

enum RegionCode {
    INSIDE = 0, // 0000
    LEFT   = 1, // 0001
    RIGHT  = 2, // 0010
    BOTTOM = 4, // 0100
    TOP    = 8  // 1000
};

int calcularCodigo(float x, float y, const Window& w);

bool cohenSutherlandClip(float& x1, float& y1, float& x2, float& y2, const Window& w);

#endif
