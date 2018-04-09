//
// Created by zuza on 07.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <complex>
#include <vector>

using std::string;

namespace algebra {
    class Matrix {
        std::complex<double> **mac;
        int n, m;

    public:
        Matrix(int n, int m); //parametrowy
        Matrix();             //bezparam
        Matrix(Matrix &matrix);
        Matrix(string matlab); //matlaba
        Matrix(std::initializer_list<std::vector<std::complex<double>>> lista);

        //ustawianie, pobieranie elementów
        std::pair<size_t, size_t>  Size();
        string Print();
        std::complex<double> ** macierz();
        int wysokosc();
        int szerokosc();


        //działania
        Matrix Add(Matrix macierz); //wymiary!
        Matrix Sub(Matrix macierz); //wymiary!
        Matrix Mul(Matrix macierz); //wymiary!
        Matrix Mul(std::complex<double> skalar);
        Matrix Pow(int potega);

        ~Matrix();
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
