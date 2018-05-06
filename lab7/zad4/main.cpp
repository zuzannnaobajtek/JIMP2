//
// Created by obajzuza on 17.04.18.
//

#include "Zad4.h"

int main(){
    LiczbaRzeczywista a(12);
    LiczbaZespolona b(23,5);

    a.powitaj();         //Czesc!
    a.wypisz();          //12
    (a+a).wypisz();      //24

    b.powitaj();         //Czesc!
    b.wypisz();          //23 + 5I

    (b+b).wypisz();      //Co się wypisze?
}