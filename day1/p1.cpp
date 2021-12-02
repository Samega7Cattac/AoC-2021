#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::fstream input("input.txt", std::ios::in);
    int deep = 0;
    int deep_ant = 0;
    int counter = 0;
    input >> deep;
    deep_ant = deep;
    while(input >> deep)
    {
        if (deep > deep_ant)
        {
            ++counter;
        }
        deep_ant = deep;
    }
    std::cout << counter << std::endl;
    return 0;
}
