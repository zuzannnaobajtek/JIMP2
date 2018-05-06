//
// Created by Zuzanna Obajtek on 2018-03-12.
//

#include "Polybius.h"

string PolybiusCrypt(string message) {
    char a[5][5] = {{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    char c;
    string crypted;
    for (int i = 0; i < message.length(); i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k <= 5; k++) {
               if (message[i] == a[j][k]) {
                   c = j + 1;
                   crypted = crypted + c;
                   c = k + 1;
                   crypted = crypted + c;
                   crypted = crypted + " ";
               }
            } }
    }
    return crypted;
}

string PolybiusDecrypt(string crypted) {
    char a[5][5] = {{'a','b','c','d','e'},{'f','g','h','i','k'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};
    char first, second;
    int firstInt, secondInt;
    string message;
    for (int i = 0; i < crypted.length()-1; i++) {
        if (crypted[i] != ' ') {
            first = crypted[i];
            firstInt = first - '0';
            second = crypted[i + 1];
            secondInt = second - '0';
            message = message+ a[firstInt-1][secondInt-1];
            i++;
        }
    }
    return message;

}