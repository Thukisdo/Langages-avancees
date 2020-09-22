/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 */


#include <iostream>

/** La fonction marche pour n'importe quel type
 * 
 */
template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

/** La fonction ne marche que pour le type int
 * 
 */
void swapInt(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
}


int main()
{
    int a = 0, b = 5;
    std::cout << "Avant échange A : " << a << " B : " << b << std::endl;
    swap(a, b);
    std::cout << "Aprés échange A : " << a << " B : " << b << std::endl;
    return 0;
}