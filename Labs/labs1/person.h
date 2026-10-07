#pragma once
#include <string>

// Возрастная категория человека
enum PersonCategory { CHILD, TEEN, ADULT };

// Данные о человеке
struct Person {
    std::string firstname;
    std::string sirname;      // фамилия
    int birthyear;
    PersonCategory category;
};

// Определяет категорию по году рождения: до 12 - ребёнок, 13..18 - подросток, старше 18 - взрослый
PersonCategory getCategory(const Person& p, int currentYear);

// Дописывает данные о человеке в файл, соответствующий его категории
void writePerson(const Person& p);

// Очищает выходные файлы перед запуском
void clearOutputFiles();
