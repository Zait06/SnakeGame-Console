#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "../src/Game.h"

using namespace std;

int main(){
    srand(time(NULL));
    Game g;
    g.run();
    system("pause>null");
    return 0;
}