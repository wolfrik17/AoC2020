#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string number;
    std::vector<int> input;
    bool found;
    
    while (std::getline(std::cin, number))
    {
        input.push_back(stoi(number));
    }
   
    //Part 1
    found = 0;
    std::cout << std::endl << "Part 1 answer: ";
    
    for (auto i = input.begin(); i < input.end()-1 && found == 0; ++i)
        for (auto y = i + 1; y < input.end() && found == 0; ++y)
            if (*i + *y == 2020)
            {
                std::cout << *i << " x " << *y << " = " << (*i) * (*y) << std::endl;
                found = 1;
            }
    
    //Part 2
    found = 0;
    std::cout << std::endl << "Part 2 answer: ";
    
    for (auto i = input.begin(); i < input.end()-2 && found == 0; ++i)
        for (auto y = i + 1; y < input.end()-1 && found == 0; ++y)
            for (auto z = y + 1; z < input.end() && found == 0; ++z)
                if (*i + *y + *z == 2020) 
                { 
                    std::cout << *i << " x " << *y << " x " << *z << " = " << (*i) * (*y) * (*z) << std::endl;
                    found = 1;
                }
    return 0;
}
