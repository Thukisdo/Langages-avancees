#include <iostream>


class Point {
    private :
    int x, y;

    public :
    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {};
    Point(const Point& copy) : x(copy.x), y(copy.y) {};

    ~Point() {
        std::cout << "appel au destructeur\n";
    }

    const void afficher() {
        std::cout << "x : " << x << " y : " << y << std::endl;
    };
    
    const Point& operator=(const Point& p) {
        x = p.x; 
        y = p.y; 
        return *this;
    };

    int getx() const {return x;};
    int gety() const {return y;};
};


int main()
{
    Point a, b(4, 5), c(8, 9);
    a.afficher();
    b.afficher();
    c.afficher();
    c = b;
    c.afficher();
    return 0;
}