#include <iostream>

void tableauEcriture(int* tabl, int size)
{
    for (int i = 0; i < size; i++)
        tabl[i] = i;
}

void tableauLecture(const int* tabl, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << tabl[i] << std::endl;
}

int main()
{
    int tabl[100] = {0};
    tableauEcriture(tabl, 100);
    tableauLecture(tabl, 100);
    return 0;
}