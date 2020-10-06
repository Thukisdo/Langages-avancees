#include "CList.hpp"
#include "CPile.hpp"
#include "CFile.hpp"


int main()
{
    CPile pile;
    CFile file;

    CList* ptList = &file;
    * ptList << 0 << 1; //empiler deux valeurs dans la file
    std::cout << "La file contient : " << * ptList << std::endl;
    int i;
    * ptList >> i; //récupérer une valeur de la file dans i
    std::cout << "Aprés extraction la file contient : " << * ptList << " et i=" << i  << std::endl;

    ptList = &pile;
    * ptList << 0 << 1; //empiler deux valeurs dans la pile
    std::cout << "La pile contient : " << *ptList  << std::endl;
    * ptList >> i; //récupérer une valeur de la pile dans i
    std::cout << "Aprés extraction la pile contient : "  << * ptList << " et i=" << i  << std::endl; 
}