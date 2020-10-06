#include "Point.hpp"



    /**
     * @brief Construct a new Point object
     * 
     * @param x 
     * @param y 
     */
    Point::Point(int x, int y) : m_x(x), m_y(y)
    {

    }

    /**
     * @brief Copy constructor
     * 
     * @param val 
     */
    Point::Point(Point const& val) : m_x(val.m_x), m_y(val.m_y)
    {

    }


    /**
     * @brief copy assignement
     * 
     * @param val 
     * @return Point& 
     */
    Point& Point::operator=(Point const& val)
    {
        m_x = val.m_x;
        m_y = val.m_y;
        return *this;
    }


    /**
     * @brief Add each coordinate 
     * 
     * @param val 
     * @return Point 
     */
    Point Point::operator+(Point const& val)
    {
        Point res = *this;
        res += val;
        return res;
    }

    /**
     * @brief Substract each coordinate
     * 
     * @param val 
     * @return Point 
     */
    Point Point::operator-(Point const& val)
    {
        Point res = *this;
        res -= val;
        return res;
    }

    /**
     * @brief Add the coordinates of val to this point
     * 
     * @param val 
     * @return Point& 
     */
    Point& Point::operator+=(Point const& val)
    {
        m_x += val.m_x;
        m_y += val.m_y;
        return *this;
    }

    /**
     * @brief Substract the coordinates of val from this point
     * 
     * @param val 
     * @return Point& 
     */
    Point& Point::operator-=(Point const& val)
    {
        m_x -= val.m_x;
        m_y -= val.m_y;
        return *this;
    }