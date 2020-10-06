#pragma once

#include "Forme.hpp"
#include <iostream>

class Rectangle : public Forme {
private:
    int m_longueur;
    int m_hauteur;

public:

    using Forme::Forme;
    Rectangle(Point position = Point(), int const longueur = 0, int const hauteur = 0);
    virtual void afficher();
};