#pragma once

#include <array>
#include <string>

namespace StagesOfHangman {

    inline const std::array<std::string, 7> &stages() {
        static const std::array<std::string, 7> values{{
            R"(   ________
   |      |
   |
   |
   |
   |
___|___
)",
            R"(   ________
   |      |
   |      O
   |
   |
   |
___|___
)",
            R"(   ________
   |      |
   |      O
   |      |
   |      |
   |
___|___
)",
            R"(   ________
   |      |
   |      O
   |     /|
   |      |
   |
___|___
)",
            R"(   ________
   |      |
   |      O
   |     /|\
   |      |
   |
___|___
)",
            R"(   ________
   |      |
   |      O
   |     /|\
   |      |
   |     /
___|___
)",
            R"(   ________
   |      |
   |      O
   |     /|\
   |      |
   |     / \
___|___
)",
        }};
        return values;
    }

    inline const std::string &getStage(int num) {
        if (num < 0) num = 0;
        if (num > 6) num = 6;
        return stages()[static_cast<size_t>(num)];
    }
}