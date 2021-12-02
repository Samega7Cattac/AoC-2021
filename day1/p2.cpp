#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char *argv[])
{
    int input = open("input.txt", O_RDONLY);
    size_t input_size = lseek(input, 0, SEEK_END);
    char *input_ptr = static_cast<char*>(mmap(nullptr, input_size, PROT_READ, MAP_SHARED, input, 0));
    unsigned int counter = 0;
    char * prox_value_ptr = input_ptr;
    while(true)
    {
        int value_ant = std::atoi(prox_value_ptr);
        int offset = 12;
        if (*(prox_value_ptr + 7) != '\n')
        {
            offset += 3;
        }
        int value = std::atoi(prox_value_ptr + offset);
        if (value == 0)
        {
            int tmp_value = std::atoi(prox_value_ptr + 5);
            if (tmp_value > value_ant)
            {
                ++counter;
            }
            if (std::atoi(prox_value_ptr + 10) > tmp_value)
            {
                ++counter;
            }
            break;
        }
        if (value_ant < 1000)
        {
            prox_value_ptr += 4;
        }
        else
        {
            prox_value_ptr += 5;
        }
        if (value > value_ant)
        {
            ++counter;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}