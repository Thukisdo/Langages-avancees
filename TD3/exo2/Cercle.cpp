#include "Cercle.hpp"

Cercle::Cercle(Point position, int const rayon) : Forme(position), m_rayon(rayon)
{


}

void Cercle::afficher()
{
    std::cout << "Cercle [" << m_position.m_x << "," << m_position.m_y << "] : rayon (" << m_rayon << ")\n";
}