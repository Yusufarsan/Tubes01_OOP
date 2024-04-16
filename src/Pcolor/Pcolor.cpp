/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#include "Pcolor.hpp"

void print_red(string s) {
    cout << RED << s << NORMAL;
}

void print_green(string s) {
    cout << GREEN << s << NORMAL;
}

void print_blue(string s) {
    cout << BLUE << s << NORMAL;
}
