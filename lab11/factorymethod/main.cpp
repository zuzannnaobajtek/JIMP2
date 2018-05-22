//
// Created by obajzuza on 22.05.18.
//

#include <iostream>
#include <memory>
#include <complex>
#include "FactoryMethod.h"

int main() {
    int a = 3, b =4;
    int *p = &a;
    double c = 5.6, d=6.7;
    double *r = &c;
    std::complex<double> e = 6+6i, f = 6+7i;
    std::shared_ptr<double> q = std::make_shared<double>(c);
    std::unique_ptr<int> s = std::make_unique<int>(a);

    std::cout << factoryMethod::Add(a,b) << std::endl;
    std::cout << factoryMethod::Add(c,d) << std::endl;
    std::cout << factoryMethod::Add(a,c) << std::endl;

    std::vector<double> v;
    v.push_back(0.1);
    v.push_back(0.2);
    v.push_back(0.3);

    std::cout << factoryMethod::Mean(v) << std::endl;
    std::cout << factoryMethod::Mean(v) << std::endl;

    std::cout << factoryMethod::Value(p) << std::endl;
    std::cout << factoryMethod::Value(q) << std::endl;
    std::cout << factoryMethod::Value(s) << std::endl;

    return 0;
}