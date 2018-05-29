//
// Created by obajzuza on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <cstdio>
#include <memory>

namespace tree {
    template <typename T>
    class Tree {
    public:
        Tree(const T &t) {
            left = nullptr;
            right = nullptr;
            value = t;
            depth = 1;
        }

        void Insert(const T &t) {
                if (t < value ) {
                    if (left)
                        left->Insert(t);
                    else {
                        left = std::make_unique<Tree<T>>(t);
                        depth++;
                    }
                }
                else{
                    if (right)
                        right->Insert(t);
                    else {
                        right = std::make_unique<Tree<T>>(t);
                        depth++;
                    }
                }
        }

        bool Find(const T &t) {
            if (t == value)
                return true;
            else {
                if (t < value && left != nullptr)
                    left->Find(t);
                if (!(t < value) && right != nullptr)
                    right->Find(t);
            }
            return false;
        }

        T Value () {
            return value;
        }

        size_t Depth() {
            return depth;
        }

        size_t Size() {
            size_t s = 1;
            if (left != nullptr) {
                s += left->Size();
            }
            if (right != nullptr) {
                s += right->Size();
            }
            if (left == nullptr && right == nullptr)
                return 1;
            return s;
        }

    protected:
        T value;
        size_t depth;
        std::unique_ptr<Tree> left;
        std::unique_ptr<Tree> right;
    };
}


#endif //JIMP_EXERCISES_TREE_H
