//1712822 - Nguyen Khanh Toan - 17CNTN
//windowFunction.h
#ifndef  WINDOW_FUNCTION_H
#define WINDOW_FUNCTION_H

#include<Windows.h>
#include<windows.h>
#include <thread> 
#include<time.h>
#include<conio.h>
#include <stdio.h>
#include <ctype.h>

extern void TextColor(int x);
extern void GotoXY(int x, int y);
extern void FixConsoleWindow();
extern void resizeConsole(int width, int height);
extern void Nocursortype();
#endif // ! WINDOW_FUNCTION_H
