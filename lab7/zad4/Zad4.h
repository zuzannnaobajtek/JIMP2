//
// Created by obajzuza on 17.04.18.
//

#ifndef JIMP_EXERCISES_ZAD4_H
#define JIMP_EXERCISES_ZAD4_H


#include <iostream>
using namespace std;

class LiczbaRzeczywista{
protected:
    double re;
public:
    LiczbaRzeczywista(double r){re=r;}
    void wypisz(){
        cout << re << endl;
    }
    void powitaj(){
        cout << "Czesc!" << endl;
    }

    LiczbaRzeczywista operator+(const LiczbaRzeczywista& r){
        LiczbaRzeczywista rr(re+r.re);
        return rr;
    }

};

class LiczbaZespolona : public LiczbaRzeczywista{
protected:
    double im;
public:
    LiczbaZespolona(double re, double i):LiczbaRzeczywista(re){im=i;}
    void wypisz(){
        cout << re << " + " << im << "i" << endl;
    }
};

#endif //JIMP_EXERCISES_ZAD4_H
