//
// Created by obajzuza on 17.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kolo k1(2,3,4);
    cout << k1.pole() << endl;
    Kula k2(2,3,5,4);
    cout << k2.pole() << endl;
    return 0;
}