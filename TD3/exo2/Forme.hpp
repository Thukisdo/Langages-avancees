#pragma once
#include "Point.hpp"


class Forme {
protected:
    Point m_position;

public:

    /**
     * @brief Construct a new Forme object
     * 
     * @param position 
     */
    Forme(Point position = Point(0, 0));

    /**
     * @brief Move a Forme
     * 
     * @param delta 
     */
    void move(Point delta);

    /**
     * @brief Move a Forme
     * 
     * @param x 
     * @param y 
     */
    void move(int const x, int const y);

    /**
     * @brief Set the Forme's position
     * 
     * @param newPos 
     */
    void setPosition(Point newPos);

    /**
     * @brief Set the Forme's position
     * 
     * @param x 
     * @param y 
     */
    void setPosition(int const x, int const y);

    virtual void afficher() = 0;
};