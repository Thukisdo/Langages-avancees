#include "Forme.hpp"




Forme::Forme(Point position) : m_position(position)
{

}


void Forme::move(Point delta)
{
    m_position += delta;
}


void Forme::move(int const x, int const y)
{
    m_position += Point(x, y);
}


void Forme::setPosition(Point newPos)
{
    m_position = newPos;
}


void Forme::setPosition(int const x, int const y)
{
    m_position = Point(x, y);
}

