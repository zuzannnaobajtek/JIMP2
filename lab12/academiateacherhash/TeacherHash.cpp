//
// Created by zuza on 04.06.18.
//

#include "TeacherHash.h"

using namespace academia;

TeacherId::TeacherId(int id) {
    id_ = id;
}

int TeacherId::Id() const {
    return id_;
}

TeacherId::operator int() const {
    return Id();
}

bool TeacherId::operator!=(const TeacherId &teacher) const {
    return (Id()!=teacher.Id());
}

bool TeacherId::operator==(const TeacherId &teacher) const {
    return (Id()!=teacher.Id());
}




TeacherId Teacher::Id() const {
    return id_;
}

std::string Teacher::Name() const {
    return name_;
}

std::string Teacher::Department() const {
    return departement_;
}

bool Teacher::operator==(const Teacher &teacher) const {
    return (Id()==teacher.Id() && Name() == teacher.Name() && Department() == teacher.Department());
}

bool Teacher::operator!=(const Teacher &teacher) const {
    return (Id()!=teacher.Id() || Name() != teacher.Name() || Department() != teacher.Department());
}

Teacher::Teacher(const TeacherId &id, const std::string &name, const std::string &departement) : id_{id}, name_{name},departement_{departement}{}


int TeacherHash::operator()(const Teacher &teacher) const {
    int out = std::hash<int>()((int)teacher.Id());
    out += std::hash<std::string>()(teacher.Name());
    out += std::hash<std::string>()(teacher.Department());

    return out;
}
