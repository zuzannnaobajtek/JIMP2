//
// Created by obajzuza on 27.03.18.
//

#ifndef JIMP_EXERCISES_RODZICDZIECKO_H
#define JIMP_EXERCISES_RODZICDZIECKO_H

#include <string>

using std::string;

class Dziecko {
private:
    string imie;
    string nazwisko;
    int wiek;
    string szkola;

    friend class Rodzic;
};


class Rodzic {
    private:
        string imie;
        string nazwisko;
        int wiek;
        Dziecko dziecko;

    public:
        void przepiszDoInnejSzkoly(string nazwa);
};



#endif //JIMP_EXERCISES_RODZICDZIECKO_H
