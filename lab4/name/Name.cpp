//
// Created by obajzuza on 20.03.18.
//

#include "Name.h"

Name::Name(string firstName, ) {

}

string Name::FirstName() {
    return this->firstName;
}

string Name::Surname() {
    return this->surname;
}

string Name::SecondName() {
    if (this->secondName != ''s)
        return this->SecondName();
    else
        return ''s;
}

string Name::ThirdName(){
    if (this->thirdName != ''s)
        return this->ThirdName();
    else
        return ''s;
}

string Name::ToFullInitials() {
    string initials = ''s;
    initials += Name::FirstName()[0] + '. ';
    initials += Name::SecondName()[0] + '. ';
    initials += Name::ThirdName()[0] + '. ';
    initials += Name::Surname()[0] + '. ';

    return initials;
}


string Name::ToFirstNamesInitials(){
    string initials = ''s;
    initials += Name::FirstName()[0] + '. ';
    initials += Name::SecondName()[0] + '. ';
    initials += Name::ThirdName()[0] + '. ';
    initials += Name::Surname();

    return initials;
}

string Name::ToSurnameNames() {
    string surnameNames = ''s;
    surnameNames += Name::Surname();
    surnameNames += Name::FirstName();
    surnameNames += Name::SecondName();
    surnameNames += Name::ThirdName();

    return surnameNames;
}

string Name::ToNamesSurname() {
    string namesSurname = ''s;
    namesSurname += Name::Surname();
    namesSurname += Name::FirstName();
    namesSurname += Name::SecondName();
    namesSurname += Name::ThirdName();

    return namesSurname;
}

bool Name::IsBeforeBySurname(string compare) {
    for (int i = 0; i < this->surname.length() && i < compare.length(); i++) {
        if (this->surname[i] > compare[i])
            return false;
    }
    return true;
}

bool Name::IsBeforeByFirstName(string compare) {
    for (int i = 0; i < this->firstName.length() && i < compare.length(); i++) {
        if (this->firstName[i] > compare[i])
            return false;
    }
    return true;
}