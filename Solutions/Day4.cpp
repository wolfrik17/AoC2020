#include <iostream>
#include <sstream>
#include <string>
#include <algorithm> 
#include <vector>

int main()
{
    int valid1 = 0, valid2 = 0;
    std::string input, line;
    std::string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
    std::string byr_v, iyr_v, eyr_v, hgt_v, hcl_v, ecl_v, pid_v, cid_v;
    std::string unit, value;
    std::vector<std::string> colors = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

    while (std::getline(std::cin, line))
    {
        if (!line.empty())
        {
            std::istringstream is{ line };
            while (!is.eof())
            {
                std::getline(is, input, ':');
                if (input.compare("byr") == 0)
                {
                    std::getline(is, input, ' ');
                    byr = input;
                    if (byr.size() == 4 && stoi(byr) >= 1920 && stoi(byr) <= 2002) byr_v = "valid";
                }
                if (input.compare("iyr") == 0)
                {
                    std::getline(is, input, ' ');
                    iyr = input;
                    if (iyr.size() == 4 && stoi(iyr) >= 2010 && stoi(iyr) <= 2020) iyr_v = "valid";
                }
                if (input.compare("eyr") == 0)
                {
                    std::getline(is, input, ' ');
                    eyr = input;
                    if (eyr.size() == 4 && stoi(eyr) >= 2020 && stoi(eyr) <= 2030) eyr_v = "valid";
                }
                if (input.compare("hgt") == 0)
                {
                    std::getline(is, input, ' ');
                    hgt = input;
                    unit = hgt.substr(hgt.length() - 2);
                    value = hgt.substr(0, hgt.length() - 2);
                    if (unit == "cm" && stoi(value) >= 150 && stoi(value) <= 193) hgt_v = "valid";
                    if (unit == "in" && stoi(value) >= 59 && stoi(value) <= 76) hgt_v = "valid";
                }
                if (input.compare("hcl") == 0)
                {
                    std::getline(is, input, ' ');
                    hcl = input;
                    if (hcl[0] = "#" && hcl.length() == 7) if (std::all_of(hcl.begin() + 1, hcl.end(), ::isxdigit)) hcl_v = "valid";
                }
                if (input.compare("ecl") == 0)
                {
                    std::getline(is, input, ' ');
                    ecl = input;
                    if (std::find(colors.begin(), colors.end(), ecl) != colors.end()) ecl_v = "valid";
                }
                if (input.compare("pid") == 0)
                {
                    std::getline(is, input, ' ');
                    pid = input;
                    if (pid.size() == 9 && std::all_of(pid.begin(), pid.end(), ::isdigit)) pid_v = "valid";
                }
                if (input.compare("cid") == 0)
                {
                    std::getline(is, input, ' ');
                    cid = input;
                }
            }

            if (!byr.empty() && !iyr.empty() && !eyr.empty() && !hgt.empty() && !hcl.empty() && !ecl.empty() && !pid.empty())
            {
                valid1++;
                byr.clear(), iyr.clear(), eyr.clear(), hgt.clear(), hcl.clear(), ecl.clear(), pid.clear(), cid.clear();
            }

            if (byr_v == "valid" && iyr_v == "valid" && eyr_v == "valid" && hgt_v == "valid" && hcl_v == "valid" && ecl_v == "valid" && pid_v == "valid")
            {
                valid2++;
                byr_v.clear(), iyr_v.clear(), eyr_v.clear(), hgt_v.clear(), hcl_v.clear(), ecl_v.clear(), pid_v.clear(), cid_v.clear();
            }
        }
        else byr_v.clear(), iyr_v.clear(), eyr_v.clear(), hgt_v.clear(), hcl_v.clear(), ecl_v.clear(), pid_v.clear(), cid_v.clear(), byr.clear(), iyr.clear(), eyr.clear(), hgt.clear(), hcl.clear(), ecl.clear(), pid.clear(), cid.clear();
    }

    std::cout << "Part 1 Answer: " << valid1 << std::endl;
    std::cout << "Part 2 Answer: " << valid2 << std::endl;

    return 0;
}
