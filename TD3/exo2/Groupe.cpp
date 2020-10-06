#include "Groupe.hpp"


Groupe::Groupe()
{

}

void Groupe::remove(int index)
{
    m_array.erase(m_array.begin() + index);
}

void Groupe::moveAll(int const x, int const y)
{
    for (size_t i = 0; i < m_array.size(); i++)
        m_array[i]->move(x, y);
}
void Groupe::moveAll(Point const& delta)
{
    for (size_t i = 0; i < m_array.size(); i++)
        m_array[i]->move(delta);
}

void Groupe::setPositionAll(int const x, int const y)
{
    for (size_t i = 0; i < m_array.size(); i++)
        m_array[i]->setPosition(x, y);
}
void Groupe::setPositionAll(Point const& newPos)
{
    for (size_t i = 0; i < m_array.size(); i++)
        m_array[i]->setPosition(newPos);
}

Forme& Groupe::operator[](unsigned int index)
{
    if( index >= m_array.size())
        throw std::overflow_error("Index is out of bound");
    return *m_array[index];
}

void Groupe::AfficheAll()
{
    for (size_t i = 0; i < m_array.size(); i++)
        m_array[i]->afficher();
}

void Groupe::clear()
{
    m_array.clear();
}
