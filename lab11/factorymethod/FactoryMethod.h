//
// Created by obajzuza on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <vector>

namespace factoryMethod {

    template <typename T>
    T Create() {
        T i;
        return i;
    }

    template <typename T, typename P>
    auto Add(T a, P b) {
        return a+b;
    }

    template <typename T>
    auto Value(T p) {
        return *p;
    }

    template <typename T>
    double Mean(std::vector<T> v) {
        int a = 0;
        T sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            a++;
        }
        return sum/a;
    }

    class MyType {
    public:
        std::string SayHello();
    };
}


#endif //JIMP_EXERCISES_FACTORYMETHOD_H
