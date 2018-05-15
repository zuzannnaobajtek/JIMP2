//
// Created by obajzuza on 08.05.18.
//

#include "Serialization.h"



string academia::Room::TypeToString(academia::Room::Type typ) const {
    switch (typ) {

        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
}

void academia::Room::Serialize(academia::Serializer *s) const {
    s->Header("room");
    s->IntegerField("id", no);
    s->StringField("name", name);
    s->StringField("type", TypeToString(type));
    s->Footer("room");
}

academia::Room::Room(int n, string nam, academia::Room::Type typ) {
    no = n;
    name = nam;
    type = typ;
}

academia::Serializer::Serializer(std::ostream *out) {
    out_ = out;
}

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    *(out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    *(out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    *(out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    *(out_) << "<" << field_name << ">" << value << "<\\" << field_name << ">";
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *(out_) << "<" << field_name << ">";
    for(auto a:value)
        SerializableField(field_name, a.get());
    *(out_) << "<\\" << field_name << ">";
}

void academia::XmlSerializer::Header(const std::string &object_name) {
    *(out_) << "<" << object_name << ">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    *(out_) << "<\\" << object_name << ">";
}

academia::XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {

}

academia::Building::Building(int no, string name, const std::vector<std::reference_wrapper<const academia::Serializable>> &rooms) {
    no_ = no;
    name_ = name;
    rooms_ = rooms;
}

void academia::Building::Serialize(academia::Serializer *s) const {
    s->Header("building");
    s->IntegerField("id", no_);
    s->StringField("name", name_);
    s->ArrayField("rooms", rooms_);
    s->Footer("building");
}

academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    (*out_) << "{";
}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    (*out_) << "}";
}

void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    IfFirst();
    (*out_) << "\"" << field_name << "\": " << value;

}

void academia::JsonSerializer::IfFirst() {
    if(first)
        first = false;
    else
        (*out_) << ", ";
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    IfFirst();
    (*out_) << "\"" << field_name << "\": \"" << value << "\"";
}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    IfFirst();
    (*out_) << "\"" << field_name << "\": " << value;
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    IfFirst();
    (*out_) << "\"" << field_name << "\": " << value;
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    IfFirst();
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    IfFirst();
    (*out_)<<"\""<<field_name<<"\": [";
    for(int i = 0; i<value.size();i++) {
        first = true;
        if(i==0) {
            value[0].get().Serialize(this); }
        else {
            *out_<<", ";
            value[i].get().Serialize(this);
        }
    }

    *(out_)<<"]";


}
