//
// Created by zuza on 16.04.18.
//

#include "WordCounter.h"
#include <algorithm>
using  ::datastructures::Counts;
using  ::datastructures::Word;
using  ::datastructures::WordCounter;


datastructures::Counts::Counts(int number) {
    this->number = number;
}

datastructures::Counts::Counts() {
    this->number = 0;
}

int datastructures::Counts::GetCounts() {
    return this->number;
}

void datastructures::Counts::SetCounts(int number) {
    this->number = number;
}

Counts *datastructures::Counts::operator++(int) {
    this->number=this->number + 1;
    return  this;
}

bool datastructures::Counts::operator<(Counts c) {
    if (this->GetCounts() < c.GetCounts()) return true;
    else return false;
}

bool datastructures::Counts::operator==(Counts c) {
    if (this->GetCounts() == c.GetCounts()) return true;
    else return false;
}

bool datastructures::Counts::operator==(int n) const {
    if (number == n) return true;
    else return false;
}

bool datastructures::Counts::operator>(Counts c) {
    if (this->GetCounts() > c.GetCounts()) return true;
    else return false;
}

datastructures::Word::Word(string word) {
    this->word = word;
}

datastructures::Word::Word() {
    this->word = "";
}

string datastructures::Word::GetWord() const {
    return this->word;
}

bool datastructures::Word::operator<(const Word &w) const {
    return word < w.word;
}

bool datastructures::Word::operator<=(const Word &w) const {
    return word <= w.word;
}

bool datastructures::Word::operator>(const Word &w) const {
    return word > w.word;
}

bool datastructures::Word::operator>=(const Word &w) const {
    return word >= w.word;
}

bool datastructures::Word::operator==(const Word &w) const {
    return word == w.word;
}


datastructures::WordCounter::WordCounter() {

}

datastructures::WordCounter::WordCounter(std::initializer_list<datastructures::Word> i_list) {
    for(auto i = i_list.begin(); i!=i_list.end(); i++) {
        bool flag = true;
        for (auto &j: this->data) {
            if(i->GetWord()==j.first.GetWord()) {
                flag = false;
                ((&j)->second)++;
            }
        }
        if (flag)
            this->data.emplace_back(std::make_pair(Word(*i), Counts(1)));
    }
}

std::set<datastructures::Word> datastructures::WordCounter::Words() {
    std::set<Word> set;
    for(auto i: this->data)
        set.emplace(i.first);
    return set;
}

int datastructures::WordCounter::DistinctWords() {
    int number = 0;
    for (auto &i: this->data)
        number++;
    return number;
}

int datastructures::WordCounter::TotalWords() {
    int number = 0;
    for (auto &i: this->data)
        number+=i.second.GetCounts();
    return number;
}

void datastructures::WordCounter::FromInputStream(std::ifstream &is) {

}

int datastructures::WordCounter::operator[](string name) {
    return 0;
}

datastructures::WordCounter::~WordCounter() {
    data.empty();
}

std::vector<std::pair<datastructures::Word, datastructures::Counts>> datastructures::WordCounter::Get() const {
    return this->data;
}

bool compare(pair<Word, Counts> &l, pair<Word, Counts> &p) {
    if (l.second.GetCounts()>p.second.GetCounts()) return true;
    else return false;
}

std::ostream &datastructures::operator<<(std::ostream &os, WordCounter &counter) {
    vector<pair<Word, Counts>> temp = counter.Get();
    std::sort(temp.begin(), temp.end(), compare);
    for (auto &i: temp)
        os<<"("<<i.first.GetWord()<<" : "<<i.second.GetCounts()<<")";
    return os;
}

