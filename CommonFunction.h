#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<time.h>
#include<string>
#include<Windows.h>
#include<conio.h>

using namespace std;

#define BOX_WIDTH 100
#define BOX_HEIGHT 25


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//print a text
void showText(string file_name)
{
    ifstream file;
    file.open(file_name);
    string line;
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

//create game frames
void draw_box(int x, int y)
{
    gotoxy(0, 0);
    for (int i = 0; i < x; i++)
    {
        cout << "=";
    }
    gotoxy(0, y);
    {
        for (int i = 0; i < x; i++)
        {
            cout << "=";
        }
    }
    for (int i = 0; i <= y; i++)
    {
        gotoxy(0, i);
        cout << "[]";
        gotoxy(x, i);
        cout << "[]";
    }
}

void randomAdd(int& add, int& random_range)
{
    add = rand() % random_range - random_range / 2;
    while (add == 0)
    {
        add = rand() % random_range - random_range / 2;
    }
}

#endif
