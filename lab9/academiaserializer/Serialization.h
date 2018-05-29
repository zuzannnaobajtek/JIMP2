//
// Created by obajzuza on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

using std::string;

namespace academia {
    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *) const = 0;
    };

    class Serializer {
    public:
        explicit Serializer(std::ostream* out);
        virtual ~Serializer() = default;
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0 ;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;
    };


    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        void Serialize(Serializer *s) const override ;
        Room(int n, string nam, Type typ);
        string TypeToString(Type typ) const;


    private:
        int no;
        std::string name;
        Type type;
    };

    class XmlSerializer : public Serializer {
    public:
        explicit XmlSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override ;
        void StringField(const std::string &field_name, const std::string &value) override ;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name) override ;
        void Footer(const std::string &object_name) override ;
    };

    class JsonSerializer : public Serializer {
    public:
        explicit JsonSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override ;
        void DoubleField(const std::string &field_name, double value) override ;
        void StringField(const std::string &field_name, const std::string &value) override ;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override ;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override ;
        void Header(const std::string &object_name) override ;
        void Footer(const std::string &object_name) override ;
        void IfFirst();

    private:
        bool first = true;
    };

    class Building : public Serializable {
    public:
        Building(int no, string name, const std::vector<std::reference_wrapper<const academia::Serializable>> &rooms);
        void Serialize(Serializer *) const override ;
    private:
        int no_;
        string name_;
        std::vector<std::reference_wrapper<const academia::Serializable>> rooms_;
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H