//
// Created by obajzuza on 10.04.18.
//

#ifndef JIMP_EXERCISES_ZAD1_H
#define JIMP_EXERCISES_ZAD1_H

#include <iostream>

class Point {
public:
    void SetX(double x);
    void SetY(double y);
    double GetX();
    double GetY();

private:
    double x_, y_;
};

std::istream& operator>>(std::istream &is, Point& point);
std::ostream& operator<<(std::ostream &is, Point& point);

#endif //JIMP_EXERCISES_ZAD1_H
