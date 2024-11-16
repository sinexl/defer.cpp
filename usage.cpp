#include "defer.hpp"
#include <iostream>

const size_t SIZE = 10;

int main(void)
{
    int* example = new int[SIZE];
    // This will be executed automatically on exit out
    // of this function
    defer(delete[] example);

    // we can read/write into memory that we declared to be deallocated later
    for (size_t i = 0; i < SIZE; i++) {
        if (i == SIZE / 2)
        {
            return 0;
        }
        example[i] = i;
        std::cout << example[i] << std::endl;
    }
}
