#include "Rectangle.hpp"


Rectangle::Rectangle(Point position, int const longueur, int const hauteur) : Forme(position), m_longueur(longueur), m_hauteur(hauteur)
{

}

void Rectangle::afficher()
{
    std::cout << "Rectangle [" << m_position.m_x << "," << m_position.m_y << "] : longueur (" << m_longueur << ") hauteur (" << m_hauteur << ")\n";
}