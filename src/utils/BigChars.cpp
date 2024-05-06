#include "BigChars.h"

/**
 * hxw = 5x7
 * 185 ╣
 * 186 ║
 * 187 ╗
 * 188 ╝
 * 200 ╚
 * 201 ╔
 * 202 ╩
 * 203 ╦
 * 204 ╠
 * 205 ═
 * 206 ╬
 */

void char_a(CoordStr coord) {
    setOnXY(coord, (char)201);
    setOnXY({coord.x + 6, coord.y}, (char)187);

    setOnXY({coord.x, coord.y + 1}, (char)186);
    setOnXY({coord.x + 6, coord.y + 1}, (char)186);

    for (int idx = 1; idx < 6; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 2}, (char)205);
    }

    setOnXY({coord.x, coord.y + 2}, (char)204);
    setOnXY({coord.x + 6, coord.y + 2}, (char)185);

    for (int idx = 3; idx < 5; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        setOnXY({coord.x + 6, coord.y + idx}, (char)186);
    }
}

void char_e(CoordStr coord) {
    setOnXY(coord, (char)201);
    setOnXY({coord.x, coord.y + 1}, (char)186);
    setOnXY({coord.x, coord.y + 2}, (char)204);
    setOnXY({coord.x, coord.y + 3}, (char)186);
    setOnXY({coord.x, coord.y + 4}, (char)200);

    for (int idx = 1; idx < 6; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 2}, (char)205);
        setOnXY({coord.x + idx, coord.y + 4}, (char)205);
    }
}

void char_i(CoordStr coord) {
    for (int idx = 0; idx < 7; idx++) {
        setOnXY({coord.x + idx, coord.y}, idx == 3 ? (char)203 : (char)205);
        setOnXY({coord.x + idx, coord.y + 4}, idx == 3 ? (char)202 : (char)205);
    }

    for (int idx = 1; idx < 4; idx++) {
        setOnXY({coord.x + 3, coord.y + idx}, (char)186);
    }
}

void char_o(CoordStr coord) {
    setOnXY({coord.x, coord.y}, (char)201);
    setOnXY({coord.x, coord.y + 4}, (char)200);

    for (int idx = 1; idx < 7; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 4}, (char)205);
    }

    setOnXY({coord.x + 6, coord.y}, (char)187);
    setOnXY({coord.x + 6, coord.y + 4}, (char)188);

    for (int idx = 1; idx < 4; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        setOnXY({coord.x + 6, coord.y + idx}, (char)186);
    }
}

void char_u(CoordStr coord) {
    for (int idx = 0; idx < 4; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        setOnXY({coord.x + 6, coord.y + idx}, (char)186);
    }
    
    setOnXY({coord.x, coord.y + 4}, (char)200);
    
    for (int idx = 0; idx < 5; idx++)
        printf("%c", (char)205);

    printf("%c", (char)188);
}

void char_g(CoordStr coord) {
    for (int idx = 1; idx < 5; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 4}, (char)205);
    }
    
    setOnXY({coord.x + 5, coord.y}, (char)205);

    for (int idx = 1; idx < 4; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        if (idx  < 3) continue;
        setOnXY({coord.x + 5, coord.y + idx}, (char)186);
    }
    setOnXY(coord, (char)201);
    setOnXY({coord.x, coord.y + 4}, (char)200);
    setOnXY({coord.x + 5, coord.y + 4}, (char)188);
    setOnXY({coord.x + 5, coord.y + 2}, (char)187);
    setOnXY({coord.x + 4, coord.y + 2}, (char)205);
}

void char_m(CoordStr coord) {
    for (int idx = 0; idx < 7; idx++)
        setOnXY({coord.x + idx, coord.y}, (char)205);
    setOnXY({coord.x, coord.y}, (char)201);
    setOnXY({coord.x + 3, coord.y}, (char)203);
    setOnXY({coord.x + 6, coord.y}, (char)187);
    for (int idx = 1; idx < 5; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        setOnXY({coord.x + 3, coord.y + idx}, (char)186);
        setOnXY({coord.x + 6, coord.y + idx}, (char)186);
    }
}

void char_p(CoordStr coord) {
    setOnXY({coord.x, coord.y}, (char)201);
    setOnXY({coord.x, coord.y + 2}, (char)204);
    
    for (int idx = 1; idx < 6; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 2}, (char)205);
    }
    
    setOnXY({coord.x + 6, coord.y}, (char)187);
    setOnXY({coord.x + 6, coord.y + 2}, (char)188);


    setOnXY({coord.x, coord.y + 1}, (char)186);
    setOnXY({coord.x + 6, coord.y + 1}, (char)186);

    for (int idx = 3; idx < 5; idx++)
        setOnXY({coord.x, coord.y + idx}, (char)186);
}

void char_r(CoordStr coord) {
    char_p(coord);
    setOnXY({coord.x + 2, coord.y + 2}, (char)203);
    for (int idx = 0; idx < 2; idx++) {
        setOnXY({coord.x + 2 + (idx * 2), coord.y + 3 + idx}, (char)200);
        setOnXY({coord.x + 3 + (idx * 2), coord.y + 3 + idx}, (char)205);
        setOnXY({coord.x + 4 + (idx * 2), coord.y + 3 + idx}, (char)187);
    }
}

void char_s(CoordStr coord) {
    for (int idx = 0; idx < 6; idx++) {
        setOnXY({coord.x + idx, coord.y}, (char)205);
        setOnXY({coord.x + idx, coord.y + 2}, (char)205);
        setOnXY({coord.x + idx, coord.y + 4}, (char)205);
    }

    setOnXY({coord.x, coord.y + 1}, (char)186); 
    setOnXY({coord.x + 5, coord.y + 3}, (char)186);

    setOnXY(coord, (char)201);
    setOnXY({coord.x, coord.y + 2}, (char)200);
    setOnXY({coord.x + 5, coord.y + 2}, (char)187);
    setOnXY({coord.x + 5, coord.y + 4}, (char)188);
}

void char_v(CoordStr coord) {
    for (int idx = 0; idx < 2; idx++) {
        setOnXY({coord.x, coord.y + idx}, (char)186);
        setOnXY({coord.x + 6, coord.y + idx}, (char)186);
    }
    for (int idx = 0; idx < 2; idx++) {
        setOnXY({coord.x + idx, coord.y + 2 + idx}, (char)200);
        setOnXY({coord.x + idx + 1, coord.y + 2 + idx}, (char)187);

        setOnXY({coord.x - idx + 6, coord.y + 2 + idx}, (char)188);
        setOnXY({coord.x - idx - 1 + 6, coord.y + 2 + idx}, (char)201);
    }
    setOnXY({coord.x + 2, coord.y + 4}, (char)200);
    setOnXY({coord.x + 3, coord.y + 4}, (char)205);
    setOnXY({coord.x + 4, coord.y + 4}, (char)188);
}