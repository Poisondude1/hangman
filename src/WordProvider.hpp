#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <random>

#include "Category.hpp"
#include "Difficulty.hpp"

class WordProvider {
public:
    WordProvider() {
        words_[Category::SPORT] = {
            "бег", "бокс", "йога", "дзюдо", "регби", "гольф", "теннис",
            "хоккей", "футбол", "плавание", "волейбол", "биатлон",
            "гимнастика", "баскетбол", "велоспорт"
        };
        words_[Category::FOOD] = {
            "суп", "хлеб", "сыр", "плов", "борщ", "пицца", "салат",
            "омлет", "котлета", "пельмени", "шашлык", "мороженое",
            "спагетти", "виноград", "бутерброд"
        };
        words_[Category::ANIMALS] = {
            "кот", "еж", "лев", "волк", "лиса", "тигр", "слон",
            "жираф", "зебра", "медведь", "черепаха", "обезьяна",
            "крокодил", "носорог", "бегемот"
        };
        words_[Category::COUNTRIES] = {
            "чад", "куба", "перу", "индия", "китай", "япония",
            "канада", "мексика", "германия", "австралия",
            "аргентина", "великобритания", "швейцария", "бразилия",
            "португалия"
        };
        words_[Category::PROFESSIONS] = {
            "врач", "повар", "актер", "пилот", "юрист", "физик",
            "механик", "учитель", "инженер", "художник", "программист",
            "архитектор", "музыкант", "журналист", "переводчик"
        };
        words_[Category::TECHNOLOGY] = {
            "сеть", "робот", "экран", "принтер", "процессор",
            "компьютер", "интернет", "смартфон", "браузер", "сервер",
            "алгоритм", "клавиатура", "программирование", "видеокарта",
            "микросхема"
        };
        words_[Category::NATURE] = {
            "лес", "река", "гора", "поле", "озеро", "закат",
            "вулкан", "пустыня", "водопад", "радуга", "ледник",
            "океан", "долина", "растение", "экосистема"
        };
    }

    std::string getRandomWord(Category category, Difficulty difficulty) {
        const auto &info = getDifficultyInfo(difficulty);
        const auto &all = words_.at(category);

        std::vector<std::string> suitable;
        for (const auto &w : all) {
            if (info.isWordSuitable(utf8::letterCount(w))) {
                suitable.push_back(w);
            }
        }

        const std::vector<std::string> &pool = suitable.empty() ? all : suitable;
        if (pool.empty()) {
            throw std::runtime_error("Нет слов для выбранной категории");
        }

        std::uniform_int_distribution<size_t> dist(0, pool.size() - 1);
        return pool[dist(rng_)];
    }

private:
    std::unordered_map<Category, std::vector<std::string>> words_;
    std::mt19937 rng_{std::random_device{}()};
};