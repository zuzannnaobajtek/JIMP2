//
// Created by obajzuza on 13.03.18.
//

#include "MinimalTimeDifference.h"


unsigned int minimaltimedifference::ToMinutes(std::string time_HH_MM) {
    std::string hours = time_HH_MM[0] + time_HH_MM[1];
    std::string mins = time_HH_MM[4] + time_HH_MM[5];
    unsigned int minutes = 0;
    minutes += hours-'0';
    minutes *= 60;
    minutes += mins-'0';
    return minutes;
}

unsigned int minimaltimedifference::MinimalTimeDifference(std::vector<std::string> times) {
    unsigned int first = minimaltimedifference::ToMinutes(times[0]);
    unsigned int second = minimaltimedifference::ToMinutes(times[1]);
    if (first >= second)
        return first-second;
    else
        return second-first;
}
