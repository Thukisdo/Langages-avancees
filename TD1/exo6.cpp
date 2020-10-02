/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 */


#include <iostream>
#include <memory>
#include <string.h>
#include "CString.hpp"

int main()
{
    CString s1( "toto" ),
    s2( 'q' ),
    s3 ;

    // On utilise une fct static en faisant nomClasse::nomFonction()
    std::cout << "nbrChaines : " << CString::getNbrString() << std::endl ;
    //On utilise l'opérateur + que l'on a définis
    s3 = s1 + 'w';
    std::cout << "s3=" << s3 << std::endl ;

    // On utilise les opérateurs de comparaisons que l'on a définis
    if( s1 > s2 ) // si s1 > s2 au sens alphabétique
        std::cout << "plus grand" << std::endl ;
    if( s1 <= s2) // si s1 <= s2 au sens alphabétique
        std::cout << "plus petit" << std::endl ;
    s3 = std::max(s1, s2) ;// retourner s1 si s1>s2, s2 sinon
    // on pourrait le remplacer par
    // s3 = std::max(s1, s2);
} 