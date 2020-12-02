#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string number;
    std::vector<int> input;
    
    while (std::getline(std::cin, number))
    {
        input.push_back(stoi(number));
    }
   
    //Part 1
    std::cout << std::endl << "Part 1 answer: ";
    
    for (auto i = input.begin(); i < input.end()-1; ++i)
        for (auto y = i + 1; y < input.end(); ++y)
            if (*i + *y == 2020)
            {
                std::cout << *i << " x " << *y << " = " << (*i) * (*y) << std::endl;
                goto part2;
            }
    //Part 2
    part2:
    std::cout << std::endl << "Part 2 answer: ";
    
    for (auto i = input.begin(); i < input.end() - 2; ++i)
        for (auto y = i + 1; y < input.end() - 1; ++y)
        {
            if (*i + *y < 2020) for (auto z = y + 1; z < input.end(); ++z)
                if (*i + *y + *z == 2020)
                {
                    std::cout << *i << " x " << *y << " x " << *z << " = " << (*i) * (*y) * (*z) << std::endl;
                    goto end;
                }
        }

    end:
    return 0;
}
