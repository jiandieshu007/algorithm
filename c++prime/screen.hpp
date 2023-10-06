
#ifndef _SCREEN_H_
#define _SCREEN_H_

#include<iostream>

class Screen{
public:
    Screen() = default;
    Screen(const int &h, const int &w) : height(h), width(w), contents(h * w, ' ') { }
    Screen(const int &h, const int &w, const char &c) : height(h), width(w), contents(h * w, c){}

private:
    int cursor;
    int width, height;
    std::string contents;
};

#endif