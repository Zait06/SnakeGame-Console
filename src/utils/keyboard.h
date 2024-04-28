#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <cstdint>
#include <iostream>

enum class Keys : uint16_t {
    ENTER = 13,
    ESC = 27,
    UP = 72,
    LEFT = 75,
    RIGTH = 77,
    DOWN = 80
};

enum class Direction : uint8_t {
    UP = 1,
    DOWN,
    RIGTH,
    LEFT
};

#endif  // _KEYBOARD_H_