//
// Created by obajzuza on 17.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <math.h>

double Kolo::pole() {
    return M_PI * r * r;
}

double Kula::pole() {
    return M_PI * 4 * r * r * r;
}