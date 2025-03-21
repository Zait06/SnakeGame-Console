#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <sys/ioctl.h>


void disableEcho() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

char getch() {
    disableEcho();
    char buf = 0;
    struct termios old = {0}, newt = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcgetattr()");
    newt = old;
    newt.c_lflag &= ~(ICANON | ECHO); // disable canonical mode and echo so the pressed char isn't shown
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &newt) < 0)
        perror("tcsetattr()");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr()");
    return buf;
}

int _kbhit() {
    termios oldt, newt;
    int bytesWaiting;
    // Save current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    ioctl(STDIN_FILENO, FIONREAD, &bytesWaiting);
    
    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return bytesWaiting;
}


#endif
