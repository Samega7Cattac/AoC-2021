#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int input = open("input.txt", O_RDONLY);
    size_t input_size = lseek(input, 0, SEEK_END);
    char *input_ptr = static_cast<char*>(mmap(nullptr, input_size, PROT_READ, MAP_SHARED, input, 0));
    unsigned int ptr_inc = 0;
    unsigned int x = 0;
    int aim = 0;
    unsigned int y = 0;
    char * cmd = nullptr;
    unsigned int value_int = 0;
    while(*(cmd = input_ptr + ptr_inc) != 0)
    {
        char * value = nullptr;
        switch (*cmd)
        {
            case 'f':
                value = cmd + 8;
                ptr_inc += 10;
                value_int = (unsigned int)(*value) - 48;
                x += value_int;
                y += aim * value_int;
                break;
            case 'u':
                value = cmd + 3;
                ptr_inc += 5;
                aim -= (int)(*value) - 48;
                break;
            case 'd':
                value = cmd + 5;
                ptr_inc += 7;
                aim += (int)(*value) - 48;
                break;
        }
    }
    std::cout << x * y << std::endl;
    return 0;
}
