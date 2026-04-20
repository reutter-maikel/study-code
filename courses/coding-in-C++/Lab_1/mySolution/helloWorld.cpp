#include <iostream>
#include "cppheader.hpp"

void printFromHeader()
{
    std::cout<<"Hello from .hpp"<<std::endl;
}

int main()
{
    std::cout << "Hello World!" << std::endl;
    printFromHeader();
}