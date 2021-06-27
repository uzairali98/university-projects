#ifndef CURSOR_H
#define CURSOR_H
#include<iostream>
#include<windows.h>
using namespace std;
class cursor
{
private:
    int x;int y;
public:
    void gotoxy(int x, int y)
{
    this->x=x;this->y=y;
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

}
 void gotoxy(int x, int y,string c)
{
    this->x=x;this->y=y;
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      cout<<c;
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
cursor()
{
    x=0;y=0;

}

};
#endif // CURSOR_H
