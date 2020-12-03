#include <iostream>
#include <string>
#include <tuple>

std::tuple<int, int> tree_counting(std::string line, int size, int pos, int trees, int d)
{
    if (pos <= size)
    {
        if (line[pos - 1] == '#') trees++;
        pos = pos + d;
    }

    else if (pos > size)
    {
        pos = pos - size;
        if (line[pos - 1] == '#') trees++;
        pos = pos + d;
    }

    return std::make_tuple(pos, trees);
}

int main()
{
    std::string line;
    int size;
    int a = 2, b = 4, c = 6, d = 8, e = 2;
    int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
    bool row = 0;


    std::getline(std::cin, line);

    size = line.size();

    while (std::getline(std::cin, line))
    {
        //Part 1
        std::tie(b, t2) = tree_counting(line, size, b, t2, 3);

        //Part 2
        std::tie(a, t1) = tree_counting(line, size, a, t1, 1);
        std::tie(c, t3) = tree_counting(line, size, c, t3, 5);
        std::tie(d, t4) = tree_counting(line, size, d, t4, 7);
        if (row == 1) std::tie(e, t5) = tree_counting(line, size, e, t5, 1);
        
        if (row == 0) row = 1;
        else if (row == 1) row = 0;
    }

    std::cout << "Part 1 answer: " << t2 << std::endl;
    std::cout << "Part 2 answer: " << t1 << " x " << t2 << " x " << t3 << " x " << t4 << " x " << t5 << " = " << t1*t2*t3*t4*t5 << std::endl;

    return 0;
}
