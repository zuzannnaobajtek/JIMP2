//
// Created by zuza on 23.04.18.
//

#include "Iterable.h"

using std::vector;
using std::string;
using std::unique_ptr;
using namespace utility;


std::pair<int, std::string> ZipperIterator::Dereference() const{

    }

IterableIterator &ZipperIterator::Next() {
    righty++, lefty++;
    return *this;

    }

bool NotEquals(const unique_ptr<IterableIterator> &other) {
    return (righty != other->righty || lefty != other->lefty);
    }

Zipper::Zipper(vector<int> vec_i, vector<string> vec_s) {
    if(vec_s.size() < vec_i.size())
        for (auto a=vec_s.size(); a<vec_i.size(); ++a)
            vec_s.emplace_back(vec_s.back());
    else
        for (auto a=vec_i=size(); a<vec_s.size(); ++a)
            vec_i.emplace_back(vec_i.back());
    pair = std::make_pair(vec_i, vec_s);
}

unique_ptr<IterableIterator> Zipper::ConstBegin() const {
    auto zippy = ZipperIterator(pair.first.begin(), pair.second.begin());
    return std::make_unique<ZipperIterator>(zippy);
}

unique_ptr<IterableIterator> Zipper::ConstEnd() const {
    auto zippy = ZipperIterator(pair.first.end(), pair.second.begin());
    return std::make_unique<ZipperIterator>(zippy);
}

IterableIteratorWrapper Iterable::cbegin() const {
    return IterableIteratorWrapper{ConstBegin()};
}

IterableIteratorWrapper Iterable::cend() const {
    return IterableIteratorWrapper{ConstEnd()};
}

IterableIteratorWrapper Iterable::begin() const {
    return IterableIteratorWrapper{ConstBegin()};
}

IterableIteratorWrapper Iterable::end() const {
    return IterableIteratorWrapper{ConstEnd()};
}

IterableIteratorWrapper (unique_ptr<IterableIterator> itr) {
    it = move(itr);
}

std::pair<int, string> IterableIteratorWrapper::operator*() {
    return it->Dereference();
}

IterableIteratorWrapper &IterableIteratorWrapper::operator++() {
    it->Next();
    return *this;
}

ZipperIterator(std::vector<int>::const_iterator left,
std::vector<std::string>::const_iterator right,
        std::vector<int>::const_iterator left_end,
std::vector<std::string>::const_iterator right_end) {

    lefty = left;
    righty = right;

}

ZipperIterator::ZipperIterator(vector<int>::const_iterator left,
                               vector<string>::const_iterator right) {

    lefty = left;
    righty = right;

}

Enumerate::Enumerate(vector<string> vec_s) {
    auto vec_i = vector<int>();
    for (int i = 1; i < vec_s.size()+1; i++)
        vec_i.push_back(i);

    pair = std::make_pair(vec_i, vec_s);
}

bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
    return it->NotEquals(other.it);
}

unique_ptr<IterableIterator> Enumerate::ConstBegin() const {
    auto zippy = ZipperIterator(pair_.first.begin(),pair.second.begin());
    return std::make_unique<ZipperIterator>(zippy);
}

unique_ptr<IterableIterator> Enumerate::ConstEnd() const {
    auto zippy = ZipperIterator(pair_.first.end(),pair.second.end());
    return std::make_unique<ZipperIterator>(zippy);
}

Product::Product(vector<int> vec_i, vector<string> vec_s) {
    auto vec_i = vector<int>();
    auto vec_s = vector<string>();

    for (auto vec : vec_i) {
        for (auto vec_ : vec_s) {
            vec_i.emplace_back(vec_i);
            vec_s.emplace_back(vec_s);
        }
    }
    pair = std::make_pair(vec_i, vec_s);
}

unique_ptr<IterableIterator> Product::ConstBegin() const {
    auto zippy = ZipperIterator(pair.first.begin(),pair.second.begin());
    return std::make_unique<ZipperIterator>(zippy);
}

unique_ptr<IterableIterator> Product::ConstEnd() const {
    auto zippy = ZipperIterator(pair_.first.end(),pair.second.end());
    return std::make_unique<ZipperIterator>(zippy);
}