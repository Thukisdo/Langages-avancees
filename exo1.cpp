#include <iostream>

int main()
{
    int tabl[10] = {0};
    int* p = tabl;
    for (int i = 0; i < 10; i++)
        std::cout << *p << std::endl;
    std::string* array = new std::string[3]();
    array[0] = "truc";
    array[1] = "machin";
    array[2] = "chose";
    delete[] array;
    return 0;
}