//
// Created by obajzuza on 17.04.18.
//

#ifndef JIMP_EXERCISES_KOLO_H
#define JIMP_EXERCISES_KOLO_H

class Kolo {
protected:
    double x,y,r;
public:
    Kolo(double x_, double y_, double r_) {
        x = x_;
        y = y_;
        r = r_;
    }
    double pole();
    virtual double pole1();
};



#endif //JIMP_EXERCISES_KOLO_H
