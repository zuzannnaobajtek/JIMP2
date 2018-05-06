//
// Created by zuza on 26.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "SimpleJson.h"

using ::std::vector;
using ::std::map;
using ::std::cout;
using ::std::endl;
using ::std::string;
using ::nets::JsonValue;
using ::std::literals::operator""

namespace nets {
    class JsonValue {
        map<string, JsonValue> mapJson;
        optional<double> doubleJson;
        optional<int> intJson;
        optional<string> stringJson;
        optional<bool> boolJson;
        optonal<vector<JsonValue>> vectorJson;

        JsonValue (map<string, JsonValue> val);
        JsonValue (double val);
        JsonValue (int val);
        JsonValue (string val);
        JsonValue (bool val);
        JsonValue (vector<JsonValue> val);
        ~JsonValue();

        ValueByName(const string &name);
        string ToString();
    };

}


#endif //JIMP_EXERCISES_SIMPLEJSON_H
