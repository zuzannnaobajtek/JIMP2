//
// Created by obajzuza on 10.04.18.
//

#include "Zad1.h"
#include <iomanip>
#include <iostream>
#include <string>

using ::std::istream;
using ::std::ws;

void CheckNextChar(char c, istream* is) {
    int next_char = is->peek();
    if (next_char != c) {
        throw std::runtime_error("invalid character");
    }
    is->ignore();
}

void IgnoreWhitespace(istream* is) {
    (*is) >> ws;
}

double ReadNumber(istream* is) {
    double d;
    (*is) >> d;
    return d;
}

istream& operator>>(istream & input, Point& p){
    CheckNextChar('(', &input);
    p.SetX(ReadNumber(&input));
    CheckNextChar(',', &input);
    IgnoreWhitespace(&input);
    p.SetY(ReadNumber(&input));
    CheckNextChar(')', &input);
    return input;
}

std::ostream &operator<<(std::ostream &is, Point &point) {
    is << "(" << std::to_string(point.GetX()) << ", " << std::to_string(point.GetY()) << ')';
    return is;
}


void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}

double Point::GetX() {
    return x_;
}

double Point::GetY() {
    return y_;
}
