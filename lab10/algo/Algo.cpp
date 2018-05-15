//
// Created by obajzuza on 15.05.18.
//

#include "Algo.h"

bool algo::Contains(const std::vector<int> &v, int element) {
    auto i = std::find(v.begin(), v.end(), element);
    if (i != v.end())
        return true;
    else
        return false;
}

void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    std::copy_n(v.begin(), n_elements, std::back_inserter(*out));
}

int algo::Sum(const std::vector<int> &v) {
    int result;
    std::for_each(v.begin(), v.end(), [&result](int i){result += i;});
    return result;
}

std::map<std::string, int> algo::DivisableBy(const std::map<std::string, int> &m, int divisor) {
    
}


bool algo::ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
    auto i = v.find(key);
    return (i != v.end());

}

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    return std::set<std::string>();
}

std::vector<int> algo::Values(const std::map<std::string, int> &m) {
    return std::vector<int>();
}



void algo::SortInPlace(std::vector<int> *v) {

}

std::vector<int> algo::Sort(const std::vector<int> &v) {
    return std::vector<int>();
}

void algo::SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

}

void algo::SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

}

void algo::SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    return std::vector<std::string>();
}

std::string algo::Join(const std::string &joiner, const std::vector<double> &v) {
    return std::__cxx11::string();
}

int algo::Product(const std::vector<int> &v) {
    return 0;
}

bool algo::ContainsValue(const std::map<std::string, int> &v, int value) {
    return false;
}

std::vector<std::string> algo::RemoveDuplicates(const std::vector<std::string> &v) {
    return std::vector<std::string>();
}

void algo::RemoveDuplicatesInPlace(std::vector<std::string> *v) {

}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {

}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    return std::vector<int>();
}

int algo::HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
    return 0;
}





