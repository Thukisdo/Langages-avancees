/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 */


#include <iostream>

void tableauEcriture(int* tabl, int size)
{
    for (int i = 0; i < size; i++)
        tabl[i] = i;
}

void tableauLecture(const int* tabl, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << tabl[i] << std::endl;
}

int main()
{
    int tabl[100] = {0};
    tableauEcriture(tabl, 100);
    tableauLecture(tabl, 100);
    return 0;
}