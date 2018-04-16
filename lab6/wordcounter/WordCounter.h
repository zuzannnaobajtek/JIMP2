//
// Created by zuza on 16.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

using ::std::string;
using ::std::vector;
using ::std::pair;

namespace datastructures {
    class Counts {
    private:
        int number;

    public:
        Counts(int number);
        Counts();
        int GetCounts();
        void SetCounts(int number);
        Counts*operator++(int);

        bool operator<(Counts c);
        bool operator==(Counts c);
        bool operator==(int r) const ;
        bool operator>(Counts c);
    };

    class Word {
    private:
        string word;

    public:
        Word(string word);
        Word();
        string GetWord() const;

        bool operator<(const Word &w) const;
        bool operator<=(const Word &w) const;
        bool operator>(const Word &w) const;
        bool operator>=(const Word &w) const;
        bool operator==(const Word &w) const;

    };

    class WordCounter {
    private:
        vector<pair<datastructures::Word, datastructures::Counts>> data;

    public:
        WordCounter();
        WordCounter(std::initializer_list<datastructures::Word> i_list);
        std::set<datastructures::Word> Words();
        int DistinctWords();
        int TotalWords();
        void FromInputStream(std::ifstream &is);
        int operator[](string name);
        std::vector<std::pair<datastructures::Word, datastructures::Counts>> Get() const;
        ~WordCounter();

    };

    std::ostream &operator<<(std::ostream &os, WordCounter &counter);
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
