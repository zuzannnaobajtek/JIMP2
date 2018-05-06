//
// Created by zuza on 23.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <vector>
#include <string>

namespace utility {

    class IterableIterator {
    public:
        std::vector<int>::const_iterator lefty;
        std::vector<std::string>::const_iterator righty;

        std::pair<int, std::string> Dereference() const;
        IterableIterator &Next();
        bool NotEquals(const std::unique_ptr<IterableIterator> &other);
        ~IterableIterator() = default;
    };

    class Zipper : public Iterable {
    public:
        Zipper(std::vector<int> vec_i, std::vector<std::string> vec_s);
        std::unique_ptr<IterableIterator> ConstBegin()const override;
        std::unique_ptr<IterableIterator> ConstEnd()const override;
    };

    class ZipperIterator : public IterableIterator {
    public:
        std::pair<int, std::string> Dereference()const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) override;

        ZipperIterator(std::vector<int>::const_iterator left,
                       std::vector<std::string>::const_iterator right,
                       std::vector<int>::const_iterator left_end,
                       std::vector<std::string>::const_iterator right_end);

        ZipperIterator(std::vector<int>::const_iterator left,
                       std::vector<std::string>::const_iterator right);

        ~ZipperIterator() override = default;
    };

    class Product : public Iterable {
    public:
        Product(std::vector<int> vec_i, std::vector<std::string> vec_s);
        std::unique_ptr<IterableIterator> ConstBegin() const override ;
        std::unique_ptr<IterableIterator> ConstEnd() const override ;
    };

    class IterableIteratorWrapper {
    private:
        std::unique_ptr<IterableIterator> it;
    public:
        IterableIteratorWrapper (std::unique_ptr<IterableIterator> itr);
        bool operator !=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();
    };

    class Iterable {
    public:
        std::pair <std::vector<int>, std::vector<std::string>> pair;

        std::unique_ptr<IterableIterator> ConstBegin() const;
        std::unique_ptr<IterableIterator> ConstEnd() const;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper end() const;

        ~Iterable() = default;

    };

    class Enumerate : public Iterable {
    public:
        std::unique_ptr<IterableIterator> ConstBegin()const override ;
        std::unique_ptr<IterableIterator> ConstEnd()const override ;

        Enumerate(std::vector<std::string> vec_s);
    };
}

#endif //JIMP_EXERCISES_ITERABLE_H
