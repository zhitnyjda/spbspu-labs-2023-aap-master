#include "functionStrRead.h"
#include <iostream>
#include <cstring>

char* readDynamicString()
{
    size_t BUFFER_SIZE = 100;
    char* buffer = new char[BUFFER_SIZE];
    size_t capacity = BUFFER_SIZE;
    size_t size = 0;
    char ch;

    while (std::cin.get(ch))
    {
        if (ch == '\n' || ch == EOF)
        {
            break;
        }

        if (size == capacity - 1)
        {
            capacity *= 2;
            char* newBuffer = new char[capacity];
            std::memcpy(newBuffer, buffer, size);
            delete[] buffer;
            buffer = newBuffer;
        }

        buffer[size++] = ch;
    }

    if (size == capacity)
    {
        capacity += 1;
        char* newBuffer = new char[capacity];
        std::memcpy(newBuffer, buffer, size);
        delete[] buffer;
        buffer = newBuffer;
    }
    buffer[size] = '\0';

    return buffer;
}
