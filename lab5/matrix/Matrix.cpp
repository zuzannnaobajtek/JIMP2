//
// Created by zuza on 07.04.18.
//

#include <complex>
#include "Matrix.h"

using algebra::Matrix;


algebra::Matrix::Matrix(int n, int m) {
    this->n = n;
    this->m = m;
    mac = new std::complex<double>*[n];
    for (int i = 0; i < n; i++)
        mac[i] = new std::complex<double>[m];
}

algebra::Matrix::Matrix() {

}

algebra::Matrix::Matrix(Matrix &ma) {
    this->n = ma.n;
    this->m = ma.m;
    mac  = new std::complex<double>*[n];
    for (int i = 0; i < n; i++) {
        mac[i] = new std::complex<double>[m];
        for (int j = 0; j < m; j++)
            mac[i][j] = ma.mac[i][j];
    }
}

algebra::Matrix::Matrix(string matlab) {

}

algebra::Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> lista) {
    int ilWierszy = int(lista.size());
    unsigned long ilKolumn = 0;

    for (auto row : lista) {
        ilKolumn = row.size();
    }

    n = int(ilKolumn);
    m = ilWierszy;

    std::complex<double> ** tab = new std::complex<double>*[m];
    for (int i = 0; i < m; i++) {
        tab[i] = new std::complex<double>[n];
    }

    mac = tab;
    //mac[0][0] = 1.0 + 1.0i;

    int i = 0, j = 0;

    for (std::vector<std::complex<double>> row : lista) {
        j = 0;
        for (std::complex<double> element : row) {
            mac[i][j] = element;
            j++;
        }
        i++;
    }

}

std::pair <size_t, size_t> algebra::Matrix::Size() {
    return std::pair<size_t, size_t> (n,m);
}

string algebra::Matrix::Print() {
    string wyjscie, pom;
    wyjscie += "[";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pom = std::to_string(mac[i][i].real());

            for (int k = 0; k < pom.length(); k++) {
                bool flaga = true;

                for (int l =  pom.length() - 1; l >= k; l--)
                    if(pom[l] != '0')
                        flaga = false;
                if (flaga) {
                    pom = pom.substr(0, k);
                    //break;
                }
            }

            if (pom[pom.length() - 1] == '.')
                pom = pom.substr(0, pom.length() -1);

            wyjscie += pom;

            if(mac[i][j].imag() != 0) {
                string pom2 = std::to_string(mac[i][j].imag());
                for (int o = 0; o < pom2.length(); o++) {
                    bool flaga = true;
                    for (int p = pom2.length() - 1; p >= o; p--) {
                        if (pom2[p] != '0') {
                            flaga = false;
                        }
                    }
                    if (flaga) {
                        pom2 = pom2.substr(0, o);
                        //break;
                    }
                }

                if (pom2[pom2.length() - 1] == '.')
                    pom2 = pom2.substr(0, pom2.length() - 1);

                wyjscie += "i" + pom2;
            } else
                wyjscie += "i0";
            wyjscie += ", ";
            }
        wyjscie = wyjscie.substr(0, wyjscie.length() - 2);
        wyjscie += "; ";
        }

    wyjscie = wyjscie.substr(0, wyjscie.length() - 2);
    wyjscie += "]";

    return wyjscie;
    }

std::complex<double> **algebra::Matrix::macierz() {
    return nullptr;
}

int algebra::Matrix::wysokosc() {
    return n;
}

int algebra::Matrix::szerokosc() {
    return m;
}

Matrix algebra::Matrix::Add(Matrix macierz) {
    if (m != macierz.szerokosc() || n != macierz.wysokosc())
        throw "Nie można dodać macierzy - różne wymiary";

    Matrix wyjscie(macierz.wysokosc(), macierz.szerokosc());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            wyjscie.macierz()[i][j]= mac[i][j] + macierz.macierz()[i][j];
        }
    }

    return wyjscie;
}

Matrix algebra::Matrix::Sub(Matrix macierz) {
    if (m != macierz.szerokosc() || n != macierz.wysokosc())
        throw "Nie można dodać macierzy - różne wymiary";

    Matrix wyjscie(macierz.wysokosc(), macierz.szerokosc());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            wyjscie.macierz()[i][j]= mac[i][j] - macierz.macierz()[i][j];
        }
    }
    return wyjscie;

}

Matrix algebra::Matrix::Mul(Matrix macierz) {
    if (m!= macierz.wysokosc())
        throw "Nie można pomnożyć macierzy - nieprawidłowe wymiary";

    Matrix wyjscie(n, macierz.szerokosc());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < macierz.szerokosc(); j++) {
            wyjscie.macierz()[i][j] = 0;
            for (int k = 0; k < macierz.wysokosc(); k++) {
                wyjscie.macierz()[i][j] += mac[i][k] * macierz.macierz()[k][j];
            }
        }
    }

    return wyjscie;
}

Matrix algebra::Matrix::Mul(std::complex<double> skalar) {
    Matrix wyjscie(n,m);

    for(int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            wyjscie.macierz()[i][j] = mac[i][j] * skalar;
        }
    }
    return  wyjscie;
}

Matrix algebra::Matrix::Pow(int potega) {
    Matrix wyjscie = *this;

    for (int i = 1; i < potega; i++)
        wyjscie = wyjscie.Mul(*this);

    return wyjscie;
}

algebra::Matrix::~Matrix() {
    for (int i = 0; i < n; i++)
        delete [] mac[i];
    delete [] mac;
}




