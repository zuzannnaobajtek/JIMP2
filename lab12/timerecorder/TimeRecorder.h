//
// Created by zuza on 04.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <vector>

namespace profiling {
    template <typename T>
    auto TimeRecorder(T obj) {
        auto beginning = std::chrono::high_resolution_clock::now();
        auto out = obj();
        auto end = std::chrono::high_resolution_clock::now();

        auto duracy = std::chrono::duration<double, std::milli>(end-beginning).count();
        return std::make_pair(out, duracy);
    }
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
