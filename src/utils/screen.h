#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>

struct CoordStr { 
	int x, y;
	bool operator==(const CoordStr &coordA) {
		return coordA.x == x && coordA.y == y;
	}
};
 
// Cursor position in coords
void gotoxy(CoordStr coord);

#endif // _SCREEN_H_