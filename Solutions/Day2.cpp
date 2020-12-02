#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

int main()
{
    int min_position1, max_position2, appearances, valid_part1 = 0, valid_part2 = 0;
    char letter;

    std::string input, line;
    std::string password;

    while (std::getline(std::cin, line))
    {
        std::istringstream is{ line };
        std::getline(is, input, '-');
        min_position1 = stoi(input);
        std::getline(is, input, ' ');
        max_position2 = stoi(input);
        std::getline(is, input, ':');
        letter = input[0];
        std::getline(is, input);

        //Part 1
        appearances = std::count(input.begin(), input.end(), letter);
        if (appearances >= min_position1 && appearances <= max_position2) valid_part1++;

        //Part 2
        if(input[min_position1] == letter != (max_position2 < input.length() && input[max_position2] == letter)) valid_part2++;
    }

    std::cout << "Part 1 answer: " << valid_part1 << std::endl;
    std::cout << "Part 2 answer: " << valid_part2 << std::endl;

    return 0;
}
