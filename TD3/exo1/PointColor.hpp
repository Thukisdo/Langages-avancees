#pragma once
#include "Point.hpp"

class PointColor : public Point {
public:
    unsigned short m_R, m_G, m_B;

    /**
     * @brief On peut utiliser le meme constructeur que la classe mère
     * 
     */
    using Point::Point;

    /**
     * @brief Construct a new Point Color object
     * 
     * @param x 
     * @param y 
     * @param R 
     * @param G 
     * @param B 
     */
    PointColor(int x = 0, int y = 0, short R = 0, short G = 0, short B = 0);
};