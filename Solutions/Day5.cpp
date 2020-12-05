#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    int max = 0, id = 0, row = 0, row_upper, row_lower, col = 0, col_upper, col_lower;
    std::string line;
    std::vector<int> id_list;

    while (std::getline(std::cin, line))
    {
        row_lower = 0;
        row_upper = 127;
        col_lower = 0;
        col_upper = 7;

        for (int i = 0; i < 7; i++)
        {
            if (line[i] == 'F')
            {
                row_upper = (row_lower + row_upper) / 2;
                if (i == 6) row = row_lower;
            }
            if (line[i] == 'B')
            {
                row_lower = ((row_lower + row_upper) / 2)+1;
                if (i == 6) row = row_upper;
            }
        }

        for (int i = 7; i < 10; i++)
        {
            if (line[i] == 'L')
            {
                col_upper = (col_lower + col_upper) / 2;
                if (i == 9) col = col_lower;
            }
            if (line[i] == 'R')
            {
                col_lower = ((col_lower + col_upper) / 2) + 1;
                if (i == 9) col = col_upper;
            }
        }
        id = (row * 8) + col;
        id_list.push_back(id);
        max = std::max(max, id);
    }

    sort(id_list.begin(), id_list.end());
    for (auto it = id_list.begin(); it < id_list.end() - 1; it++) if (*(it + 1) - *it == 2) id = *it + 1;


    std::cout << "Part 1 Answer: " << max << std::endl;
    std::cout << "Part 2 Answer: " << id << std::endl;

    return 0;
}
