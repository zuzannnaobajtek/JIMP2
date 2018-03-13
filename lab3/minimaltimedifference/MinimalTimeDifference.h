//
// Created by obajzuza on 13.03.18.
//

#ifndef JIMP_LAB_MINIMALTIMEDIFFERENCE_H
#define JIMP_LAB_MINIMALTIMEDIFFERENCE_H

#include <vector>
#include <sstream>
#include <regex>
#include <cmath>

namespace  minimaltimedifference {
    unsigned int ToMinutes(std::string time_HH_MM);

    unsigned int MinimalTimeDifference(std::vector<std::string> times);
}

#endif //JIMP_LAB_MINIMALTIMEDIFFERENCE_H
