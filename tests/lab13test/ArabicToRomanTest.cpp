//
// Created by mwypych on 01.06.17.
//

#include <utility>
#include <ArabicToRoman.h>
#include <gtest/gtest.h>

TEST (arabic_to_roman, convertion_of_4_returns_string_IV) {
    EXPECT_EQ("IV", ArabicToRoman(4));
}

TEST (arabic_to_roman, convertion_of_6_returns_string_VI) {
    EXPECT_EQ("VI", ArabicToRoman(6));
}

TEST (arabic_to_roman, convertion_of_12_returns_string_XII) {
    EXPECT_EQ("XII", ArabicToRoman(12));
}

TEST (arabic_to_roman, convertion_of_55_returns_string_LV) {
    EXPECT_EQ("LV", ArabicToRoman(55));
}