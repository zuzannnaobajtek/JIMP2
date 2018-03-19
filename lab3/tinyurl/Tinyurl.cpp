//
// Created by obajzuza on 19.03.18.
//

#include "Tinyurl.h"


void NextHash(std::array<char, 6> *state) {
    int changeIndex = 5, value;
    bool change = true;
    while (change) {
        value = (int)(*state)[changeIndex];
        switch (value) {
            case 57:
                (*state)[changeIndex] = 'a';
                change = false;
                break;
            case 90:
                (*state)[changeIndex] = 'A';
                change = false;
                break;
            case 122:
                (*state)[changeIndex] = '0';
                changeIndex--;
                break;
            default:
                value++;
                (*state)[changeIndex] = (char)value;
                change = false;
        }
    }
}

std::unique_ptr<TinyUrlCodec> Init() {
    return std::unique_ptr <TinyUrlCodec> ();
}

std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {

    NextHash(&(codec->get()->array));
    std::string tinyUrl = "";

    int i = 0;
    do {
        tinyUrl += codec->get()->array[i];
        i++;
    }while (i < 6);

    codec->get()->shortFullUrl[0] = tinyUrl;
    codec->get()->shortFullUrl[1] = url;

    return tinyUrl;
}

std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
    if(hash == codec->shortFullUrl[0])
        return codec->shortFullUrl[1];
    else return "Cannot decode";
}



