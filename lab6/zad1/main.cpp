//
// Created by obajzuza on 10.04.18.
//

#include "Zad1.h"
#include <stdio.h>

int main () {

    Point Punkt;
    double x = 9.34;
    double y = 6.11;
    Punkt.SetX(x);
    Punkt.SetY(y);
    Point Punkt2;
    std::cin >> Punkt2;
    std::cout << Punkt2;
    return 0;
}