#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifdef _WIN32
    // Code for Windows (32-bit and 64-bit, this part is common)
	#include <windows.h>
	#include <conio.h>
    #define CLEARSCREEN system("cls")
    #define CHECKKEY _kbhit()
	#define PAUSE system("pause>null")

#elif __linux__
    // Code for linux
	#include <stdio.h>
    #include <termios.h>
    #include <unistd.h>
	#include <fcntl.h>

    int kbhit();

    #define CLEARSCREEN system("clear")
    #define CHECKKEY kbhit()
	#define PAUSE system("read -rsp $'\nPress any key to continue...\n' -n 1")

#endif

#endif