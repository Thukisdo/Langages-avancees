/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 */


#include <iostream>

// Normalement, on devrait créer un Point.hpp et un Point.cpp
// Je mettrais tout dans le meme fichier pour simplifier
class Point {
    private :
    int x, y;

    public :
    // Ici, nx et ny sont des parametres optionnels
    Point(int nx = 0, int ny = 0) : x(nx), y(ny) {};

    // Constructeur de copie
    Point(const Point& copy) : x(copy.x), y(copy.y) {};

    // Destructeur
    ~Point() {
        std::cout << "appel au destructeur\n";
    }

    // le const aprés le nom de fonction indique que la fct ne modifie pas la classe
    void afficher() const {
        std::cout << "x : " << x << " y : " << y << std::endl;
    };
    
    // Surchage d'opérateur '='
    const Point& operator=(const Point& p) {
        x = p.x; 
        y = p.y; 
        return *this;
    };

    /** équivalent a la fonction au dessus
     * 
    void cloner(const Point& p) {
        x = p.x;
        y = p.y;
    } 
    */

    int getx() const {return x;};
    int gety() const {return y;};
};


int main()
{
    Point a, b(4, 5), c(8, 9); // Ici, a = a(0,0);
    a.afficher();
    b.afficher();
    c.afficher();
    c = b; // on pourrait écrire c.cloner(b)
    c.afficher();
    return 0;
}