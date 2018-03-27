//
// Created by obajzuza on 27.03.18.
//

#ifndef JIMP_EXERCISES_MARSJANIE_H
#define JIMP_EXERCISES_MARSJANIE_H


class Marsjanin {
public:
    static int liczbaMarsjan;
    Marsjanin() {liczbaMarsjan++;}
    ~Marsjanin() {liczbaMarsjan--;}
    void atakuj();
};


#endif //JIMP_EXERCISES_MARSJANIE_H
