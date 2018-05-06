//
// Created by obajzuza on 20.03.18.
//

#ifndef JIMP_LAB_NAME_H
#define JIMP_LAB_NAME_H

#include <string>

using ::std::string;

class Name {
public:
    Name();
    string FirstName();
    string SecondName();
    string ThirdName();
    string Surname();
    string ToFullInitials();
    string ToFirstNamesInitials();
    string ToSurnameNames();
    string ToNamesSurname;
    bool IsBeforeBySurname(string compare);
    bool IsBeforeByFirstName(string compare);

    string firstName;
    string secondName;
    string thirdName;
    string surname;
};



#endif //JIMP_LAB_NAME_H
