#include <iostream>
#include "./day_one.h"
#include "./day_two.h"

int main() {
    std::cout << "Day One:" << std::endl;
    std::cout << "  Part One: " << std::to_string(day_one::PartOne()) << std::endl;
    std::cout << "  Part Two: " << std::to_string(day_one::PartTwo()) << std::endl;

    std::cout << "Day Two:" << std::endl;
    std::cout << "  Part One: " << std::to_string(day_two::PartOne()) << std::endl;

    return 0;
}
