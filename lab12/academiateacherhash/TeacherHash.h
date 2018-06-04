//
// Created by zuza on 04.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

namespace academia {
    class TeacherId {
    public:
        explicit TeacherId(int id);
        int Id() const;
        bool operator !=(const TeacherId &teacher) const;
        bool operator ==(const TeacherId &teacher) const;
        operator int () const;

    private:
        int id_;
    };

    class Teacher {
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &departement);

        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;

        bool operator !=(const Teacher &teacher) const;
        bool operator ==(const Teacher &teacher) const;

    private:
        TeacherId id_;
        std::string name_;
        std::string departement_;
    };

    class TeacherHash {
    public:
        int operator ()(const Teacher &teacher) const;
    };
}

#endif //JIMP_EXERCISES_TEACHERHASH_H
