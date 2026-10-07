#include "person.h"
#include <fstream>

static const char* CHILD_FILE = "children.txt";
static const char* TEEN_FILE  = "teens.txt";
static const char* ADULT_FILE = "adults.txt";

PersonCategory getCategory(const Person& p, int currentYear) {
    int age = currentYear - p.birthyear;
    if (age <= 12) return CHILD;
    if (age <= 18) return TEEN;
    return ADULT;
}

void writePerson(const Person& p) {
    const char* fileName = ADULT_FILE;
    switch (p.category) {
        case CHILD: fileName = CHILD_FILE; break;
        case TEEN:  fileName = TEEN_FILE;  break;
        case ADULT: fileName = ADULT_FILE; break;
    }
    std::ofstream out(fileName, std::ios::app); // дописываем в конец
    if (out.is_open())
        out << p.sirname << " " << p.firstname << " " << p.birthyear << "\n";
}

void clearOutputFiles() {
    std::ofstream(CHILD_FILE, std::ios::trunc);
    std::ofstream(TEEN_FILE,  std::ios::trunc);
    std::ofstream(ADULT_FILE, std::ios::trunc);
}
