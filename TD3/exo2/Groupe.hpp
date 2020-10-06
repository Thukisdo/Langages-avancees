#pragma once

#include "Forme.hpp"
#include <iostream>
#include <memory>
#include <vector>


class Groupe {
private:
    std::vector<std::unique_ptr<Forme>> m_array;

public:
    Groupe();

    template<typename T>
    Forme& addForme(T&& toAdd)
    {
        m_array.push_back(std::make_unique<T>(toAdd));
        return *m_array.back();
    }
    
    void remove(int index);

    void moveAll(int const x, int const y);
    void moveAll(Point const& delta);

    void setPositionAll(int const x, int const y);
    void setPositionAll(Point const& newPos);

    void AfficheAll();

    Forme& operator[](unsigned int index);
    void clear();
};