/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 */

#include <iostream>

int main()
{
    int tabl[10] = {0};
    int* p = tabl;
    for (int i = 0; i < 10; i++)
        std::cout << p[i] << std::endl;

    std::string* array = new std::string[3]; // On pourrait utiliser un char**
    array[0] = "truc";
    array[1] = "machin";
    array[2] = "chose";
    for (int i = 0; i < 3; i++)
        std::cout << array[i] << std::endl;
    delete[] array; // on doit utiliser delete[] pour les tableau
    return 0;
}