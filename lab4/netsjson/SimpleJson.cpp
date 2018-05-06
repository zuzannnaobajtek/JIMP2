//
// Created by zuza on 26.03.18.
//

#include "SimpleJson.h"

using nets::JsonValue;
using std::to_string;

JsonValue::JsonValue(int val){
    mapJson = val;
}

JsonValue::JsonValue (double val) {
    doubleJson = val;
}

JsonValue::JsonValue (int val) {
    intJson = val;
}

JsonValue::JsonValue (string val) {
    stringJson = val;
}

JsonValue::JsonValue (bool val) {
    boolJson = val;
}

JsonValue::JsonValue (vector<JsonValue> val) {
    vectorJson = val;
}

JsonValue::~JsonValue() {
    mapJson.clear();
}

JsonValue::JsonValue JsonValue::ValueByName(const string &name) {
    return (this->mapJson.find(&name))->second;
}

string JsonValue::ToString() {
    if (doubleJson) {
        return std::to_string(*doubleJson);
    } else if (intJson){
        return  std::to_string(*intJson);
    } else if (stringJson) {
        return stringJson;
    } else if (boolJson) {
        if (boolJson == true)
            return "true";
        else
            return "false";
    } else if (vectorJson) {
        string outputString = "[";
        for (auto &n : *vectorJson) {
            outputString = outputString+", "+n.ToString();
        }
        outputString += "]";
        return outputString;
    } else if (&mapJson != nullptr) {
        string outputString = "{";
        for (auto &n : this->mapJson) {
            outputString = outputString+n.second.ToString()+", ";
        }
        outputString[outputString.size()-2] = '}';
        return outputString;
    }

}