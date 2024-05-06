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

#else
// Code for linux
#include <stdio.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>

int _kbhit();
char getch();

#define CLEAN_SCREEN system("clear")
#define CHECK_KEY _kbhit()
#define PAUSE system("read -rsp $'\nPress any key to continue...\n' -n 1")
#define GET_KEY getch()

#endif

#endif