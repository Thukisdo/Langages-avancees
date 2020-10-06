#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Cercle.hpp"
#include "Groupe.hpp"

int main()
{
    Groupe monGroupe;

    monGroupe.addForme(Rectangle(Point(0 , 0), 50, 50));
    monGroupe.addForme(Rectangle(Point(2 , 2), 50, 50));
    monGroupe.addForme(Rectangle(Point(5 , 5), 50, 50));
    monGroupe.addForme(Rectangle(Point(10 , 10), 50, 50));

    monGroupe.addForme(Cercle(Point(10 , 10), 5));
    monGroupe.addForme(Cercle(Point(20 , 20), 50));
    monGroupe.addForme(Cercle(Point(100 , 100), 500));

    monGroupe.AfficheAll();
    std::cout << std::endl << std::endl << "Moving forme !!!!!!!!!!" << std::endl << std::endl;
    monGroupe.moveAll(5000, 5000);

    monGroupe.AfficheAll();

    return -1;
}