//
// Created by obajzuza on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>

namespace academia {
    class Serializer;

    class Serializable {
         virtual std::string Serialize(Serializer *)=0;
    };

    class Serializer {
        virtual void IntegerField(const std::string &field_name, int value);
        virtual void DoubleField(const std::string &field_name, double value) ;
        virtual void StringField(const std::string &field_name, const std::string &value) ;
        virtual void BooleanField(const std::string &field_name, bool value);
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value);
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value);
        virtual void Header(const std::string &object_name);
        virtual void Footer(const std::string &object_name);
    };


    class Room : public Serializable {
    public:
        std::string Serialize(Serializer *) override ;

    private:
    int no;
    std::string name;
    enum Type {
        COMPUTER_LAB
    };
    };

}


#endif //JIMP_EXERCISES_SERIALIZATION_H
