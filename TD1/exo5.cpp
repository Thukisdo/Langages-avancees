#include <iostream>
#include <math.h>


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

class Segment {
    private :
    Point a, b;

    public :
    Segment(int x1, int y1, int x2, int y2) : a(x1, y1), b(x2, y2) {};
    Segment(const Point& na, const Point& nb) : a(na), b(nb) {};
    Segment(const Segment& s) : a(s.a), b(s.b) {};

    const Point& setA(const Point& na) {return a = na;};
    const Point& setB(const Point& nb) {return b = nb;};

    double longueur() const
    {
        return sqrt(pow(b.getx() - a.getx(), 2) + pow(b.gety() - a.gety(), 2));
    }

    bool estVertical() const {
        return a.getx() == b.getx();
    }

    bool estHorizontal() const {
        return a.gety() == b.gety();
    }

    bool estDiagonale() const {
        return abs((b.gety() - a.gety())) == abs((b.getx() - a.getx()));
    }
};


int main()
{
    Segment test(0, 0, 0, -5) ;
    std::cout << test.longueur() << std::endl;
    std::cout << test.estDiagonale() << std::endl;
    std::cout << test.estHorizontal() << std::endl;
    std::cout << test.estVertical() << std::endl;
    return 0;
}