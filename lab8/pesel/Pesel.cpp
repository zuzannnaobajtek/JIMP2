//
// Created by obajzuza on 24.04.18.
//

#include "Pesel.h"

academia::Pesel::Pesel(const char *pesel) {
    validatePESEL(pesel);
}

void academia::Pesel::validatePESEL(const char *pesel) {
    try {

    }
    catch (InvalidPeselLength) {

    }
    catch (InvalidPeselCharacter) {

    }
    catch (InvalidPeselChecksum) {

    }
}

academia::AcademiaDataValidationError::AcademiaDataValidationError(const std::string &pesel) : invalid_argument(pesel) {

}
