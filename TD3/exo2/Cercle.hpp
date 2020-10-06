#pragma once

#include "Forme.hpp"
#include <iostream>

class Cercle : public Forme {
private:
    int m_rayon;

public:

    using Forme::Forme;
    Cercle(Point position = Point(), int const rayon = 0);
    virtual void afficher();
};