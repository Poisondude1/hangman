#pragma once

#include <array>
#include <string>

enum class Category {
    SPORT,
    FOOD,
    ANIMALS,
    COUNTRIES,
    PROFESSIONS,
    TECHNOLOGY,
    NATURE
};

struct CategoryInfo {
    Category value;
    std::string displayName;
};

inline const std::array<CategoryInfo, 7> &allCategories() {
    static const std::array<CategoryInfo, 7> values{{
        {Category::SPORT, "Спорт"},
        {Category::FOOD, "Еда"},
        {Category::ANIMALS, "Животные"},
        {Category::COUNTRIES, "Страны"},
        {Category::PROFESSIONS, "Профессии"},
        {Category::TECHNOLOGY, "Технологии"},
        {Category::NATURE, "Природа"},
    }};
    return values;
}