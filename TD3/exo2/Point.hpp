#pragma once

class Point {
public:
    int m_x, m_y; // il est assez peut utilise de mettre les coord en private ici

    /**
     * @brief Construct a new Point object
     * 
     * @param x 
     * @param y 
     */
    Point(int x = 0, int y = 0);

    /**
     * @brief Copy constructor
     * 
     * @param val 
     */
    Point(Point const& val);


    /**
     * @brief copy assignement
     * 
     * @param val 
     * @return Point& 
     */
    Point& operator=(Point const& val);


    /**
     * @brief Add each coordinate 
     * 
     * @param val 
     * @return Point 
     */
    Point operator+(Point const& val);

    /**
     * @brief Substract each coordinate
     * 
     * @param val 
     * @return Point 
     */
    Point operator-(Point const& val);

    /**
     * @brief Add the coordinates of val to this point
     * 
     * @param val 
     * @return Point& 
     */
    Point& operator+=(Point const& val);

    /**
     * @brief Substract the coordinates of val from this point
     * 
     * @param val 
     * @return Point& 
     */
    Point& operator-=(Point const& val);
};


