#pragma once

#include <array>
#include <string>

enum class Difficulty {
    EASY,
    NORMAL,
    HARD
};

struct DifficultyInfo {
    Difficulty value;
    std::string displayName;
    int minWordLength;
    int maxWordLength;
    int maxLives;

    bool isWordSuitable(size_t letterLength) const {
        return letterLength >= static_cast<size_t>(minWordLength) &&
               letterLength <= static_cast<size_t>(maxWordLength);
    }
};

inline const std::array<DifficultyInfo, 3> &allDifficulties() {
    static const std::array<DifficultyInfo, 3> values{{
        {Difficulty::EASY, "Легко", 3, 5, 6},
        {Difficulty::NORMAL, "Нормально", 6, 8, 6},
        {Difficulty::HARD, "Сложно", 9, 15, 6},
    }};
    return values;
}

inline const DifficultyInfo &getDifficultyInfo(Difficulty d) {
    for (const auto &info : allDifficulties()) {
        if (info.value == d) return info;
    }
    return allDifficulties()[0];
}

