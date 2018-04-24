//
// Created by obajzuza on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <stdexcept>

namespace academia {
    class Pesel {
    private:
        char ** pesel;

    public:
        Pesel(const char* pesel);
        void validatePESEL(const char* pesel);
    };

    class AcademiaDataValidationError : public std::invalid_argument {
    public:
        AcademiaDataValidationError(const std::string &pesel);
    };

    class InvalidPeselLength : public academia::AcademiaDataValidationError {

    };

    class InvalidPeselCharacter : public academia::AcademiaDataValidationError {

    };

    class InvalidPeselChecksum : public academia::AcademiaDataValidationError {

    };


}

#endif //JIMP_EXERCISES_PESEL_H
