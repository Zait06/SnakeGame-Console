#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#ifdef _WIN32
// Code for Windows (32-bit and 64-bit, this part is common)
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#define CLEAN_SCREEN system("cls")
#define CHECK_KEY _kbhit()
#define PAUSE system("pause>null")
#define GET_KEY getch()
#pragma comment(lib, "winmm.lib")

#elif __linux__
// Code for linux
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int kbhit();

#define CLEAN_SCREEN system("clear")
#define CHECK_KEY kbhit()
#define PAUSE system("read -rsp $'\nPress any key to continue...\n' -n 1")

#endif

#endif