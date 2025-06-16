#include "cohen_sutherland.h"

int calcularCodigo(float x, float y, const Window& w) {
    int code = INSIDE;

    if (x < w.xmin) code |= LEFT;
    else if (x > w.xmax) code |= RIGHT;

    if (y < w.ymax) code |= BOTTOM;
    else if (y > w.ymin) code |= TOP;

    return code;
}

bool cohenSutherlandClip(float& x1, float& y1, float& x2, float& y2, const Window& w) {
    int code1 = calcularCodigo(x1, y1, w);
    int code2 = calcularCodigo(x2, y2, w);

    bool aceito = false;

    while (true) {
        if ((code1 | code2) == 0) {
            aceito = true;
            break;
        } else if ((code1 & code2) != 0) {
            break;
        } else {
            float x, y;
            int fora = code1 ? code1 : code2;

            if (fora & TOP) {
                x = x1 + (x2 - x1) * (w.ymin - y1) / (y2 - y1);
                y = w.ymin;
            } else if (fora & BOTTOM) {
                x = x1 + (x2 - x1) * (w.ymax - y1) / (y2 - y1);
                y = w.ymax;
            } else if (fora & RIGHT) {
                y = y1 + (y2 - y1) * (w.xmax - x1) / (x2 - x1);
                x = w.xmax;
            } else if (fora & LEFT) {
                y = y1 + (y2 - y1) * (w.xmin - x1) / (x2 - x1);
                x = w.xmin;
            }

            if (fora == code1) {
                x1 = x;
                y1 = y;
                code1 = calcularCodigo(x1, y1, w);
            } else {
                x2 = x;
                y2 = y;
                code2 = calcularCodigo(x2, y2, w);
            }
        }
    }

    return aceito;
}
