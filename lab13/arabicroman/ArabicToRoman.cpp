//
// Created by obajzuza on 05.06.18.
//

#include "ArabicToRoman.h"

std::string ArabicToRoman(int n) {
    std::string out = "";
    while (n > 0) {
        if (n < 10) {
            if (n < 5) {
                if (n == 4)
                    out += "IV";
                else {
                    n--;
                    out += "I";
                }
            }
            else {
                out += "V";
                n -= 5;
            }
        }
        else {
            if (n < 50) {
                out += "X";
                n -= 10;
            }
            else {
                if (n < 100) {
                    out += "L";
                    n -= 50;
                }
                else {
                    if (n < 500) {
                        out += "C";
                        n -= 100;
                    }
                    else {
                        if (n < 1000) {
                            out += "D";
                            n -= 500;
                        }
                        else {
                            out += "M";
                            n -= 1000;
                        }
                    }
                }
            }
        }
    }

    std::string str = std::to_string(n);
    while (str.length() > 0) {
        if (str.length() == 4) {
            for (int i = 0; i < int(str[0]); i++)
                out += "M";
            str.erase(0);
        }
        if (str.length() == 3) {

        }
    }
    return out;
}
