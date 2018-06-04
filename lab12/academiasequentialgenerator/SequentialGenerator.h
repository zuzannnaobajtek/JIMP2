//
// Created by zuza on 04.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H


template <typename T, typename P>
class SequentialIdGenerator {
public:
    SequentialIdGenerator () { id = P(); }
    SequentialIdGenerator(P p) {id = p; }
    T NextValue() {
        T obj(id);
        ++id;
        return obj;
    }

private:
    P id;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
