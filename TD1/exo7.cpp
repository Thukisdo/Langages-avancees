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

class Definition {
    private :
    CString clef, def;

    public:
    Definition(CString&& nclef, CString&& ndef) : clef(nclef), def(ndef) {};
    const CString& getClef() {return clef;};
    const CString& getDef() {return def;};
};

int main()
{
    Definition homer( "Homer", "Buveur de biere") ;
    std::cout << "la definition du mot " << homer.getClef() << " est "<<
    homer.getDef() << std::endl ; 
} 