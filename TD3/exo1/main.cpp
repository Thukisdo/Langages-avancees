#include "PointColor.hpp"
#include "Point.hpp"
#include <iostream>


int main()
{
    PointColor a(0,0,255,0,55);
    PointColor b = a;
    b.m_x += 50;

    std::cout << "x : " << b.m_x << " y : " << b.m_y << std::endl;
    std::cout << "R : " << b.m_R << " G : " << b.m_G << " B : " << b.m_B << std::endl;
    return 1;
}