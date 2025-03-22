#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <cstdint>
#include <iostream>

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS
#else
    #define PLATFORM_UNIX
#endif

enum class Keys : uint16_t {
    ENTER = 13,
    ESC = 27,
#ifdef PLATFORM_WINDOWS
    UP = 72,
    LEFT = 75,
    RIGHT = 77,
    DOWN = 80
#else
    UP = 65,
    LEFT = 68,
    RIGHT = 67,
    DOWN = 66
#endif
};

enum class Direction : uint8_t {
    UP = 1,
    DOWN,
    RIGHT,
    LEFT
};

#endif  // _KEYBOARD_H_
