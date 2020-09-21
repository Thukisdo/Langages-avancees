#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

int main()
{
    int a = 0, b = 5;
    std::cout << "Avant échange : " << a << " " << b << std::endl;
    swap(a, b);
    std::cout << "Aprés échange : " << a << " " << b << std::endl;
    return 0;
}