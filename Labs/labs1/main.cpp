#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "person.h"

int main() {
    std::ifstream in("people.txt");
    if (!in.is_open()) {
        std::cout << "Не удалось открыть people.txt\n";
        return 1;
    }

    // текущий год
    std::time_t t = std::time(nullptr);
    int currentYear = std::localtime(&t)->tm_year + 1900;

    clearOutputFiles();

    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back(); // файлы из Windows
        if (line.empty()) continue;

        // формат строки: Фамилия Имя Год
        std::istringstream ss(line);
        Person p;
        if (!(ss >> p.sirname >> p.firstname >> p.birthyear)) continue;

        p.category = getCategory(p, currentYear);
        writePerson(p);
    }
    std::cout << "Готово: children.txt, teens.txt, adults.txt\n";
    return 0;
}
