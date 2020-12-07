#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

int main()
{
	std::string line;
	std::set<char> answers_part1, aux1, aux2, intersect;
	int sum_part1 = 0, sum_part2 = 0;
	bool first = 1;

	while (std::getline(std::cin, line))
	{
		if (!line.empty())
		{
			for (int i = 0; i < line.size(); i++)
			{
				answers_part1.insert(line[i]);
				if (first) aux1.insert(line[i]);
			}
			if (!first)
			{
				for (int i = 0; i < line.size(); i++)
				{
					aux2.insert(line[i]);
				}

				set_intersection(aux1.begin(), aux1.end(), aux2.begin(), aux2.end(), std::inserter(intersect, intersect.begin()));

				aux1 = intersect;
				intersect.clear();
				aux2.clear();
			}
			first = 0;
		}
		else
		{
			sum_part1 += answers_part1.size();
			answers_part1.clear();
			sum_part2 += aux1.size(); 
			aux1.clear();
			aux2.clear();
			intersect.clear();
			first = 1;
		}
	}

	sum_part1 += answers_part1.size();
	answers_part1.clear();
    sum_part2 += aux1.size();
	aux1.clear();
	aux2.clear();
	intersect.clear();
	first = 1;

	std::cout << "Part 1 Answer: " << sum_part1 << std::endl;
	std::cout << "Part 2 Answer: " << sum_part2 << std::endl;

	return 0;
}
