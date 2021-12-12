//
// Advent of Code Day Two
//   URL: https://adventofcode.com/2021/day/2
//

#include <fstream>
#include <sstream>
#include "day_two.h"
#include <limits>

namespace day_two {

    int PartOne() {
        // yolo, no error checking because we know what our input looks like.
        std::ifstream file;
        file.open("input.day2.txt");
        Dir curr_dir;
        int position = 0;
        int depth = 0;
        while(file) {
            auto chara = file.get();
            switch(chara) {
                // First character of a word. Check which direction it is, then seek
                // to the character after the next space. That should be a single digit
                // 1-9, followed by a newline.
                case Dir::Down:
                    curr_dir = Dir::Down;
                    file.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    break;
                case Dir::Up:
                    curr_dir = Dir::Up;
                    file.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    break;
                case Dir::Forward:
                    curr_dir = Dir::Forward;
                    file.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                    break;
                // Single int character. Update position by this number. Next character
                // should be a newline character; discard it. The character following this
                // is the first character of the new direction.
                case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    switch(curr_dir) {
                        case Dir::Forward:
                            position += chara - 48;
                            break;
                        case Dir::Down:
                            depth += chara - 48;
                            break;
                        case Dir::Up:
                            depth -= chara - 48;
                            break;
                    }
                    file.ignore(1, ';');
                    break;
                default:
                    break;
            }
        }
        return position * depth;
    }

}