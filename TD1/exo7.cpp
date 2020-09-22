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

class CString
{
    private:
    std::unique_ptr<char[]> c_str;
    size_t len;
    int size;
    static int nbr_chaines;

    // Fonctions privé pour reallouer le tableau interne
    void resize(size_t new_size)
    {
        // auto Permet de déduire automatiquement le type de la variable
        // A utiliser uniquement lorsque c'est évident
        auto tmp = std::make_unique<char[]>(new_size);
        if (len > 0)
            strcpy(tmp.get(), c_str.get());
        size = new_size;

        // On remplace le tableau par le tableau agrandi
        c_str = std::move(tmp);
    }

    public:

    CString() : len(0) {nbr_chaines++;};
    CString(const char* s) 
    {
        len = strlen(s);
        size = len + 1; // on laisse de la place pour '\0'
        c_str = std::make_unique<char[]>(size);
        strcpy(c_str.get(), s);
        nbr_chaines++;
    };

    CString(char k)
    {
        len = 1;
        size = len + 1; // on laisse de la place pour '\0'
        c_str = std::make_unique<char[]>(size);
        c_str[0] = k;
        c_str[1] = '\0';
        nbr_chaines++;
    }

    // On appel le constructeur char*
    CString(const CString& s) : CString(s.c_str.get()) {}

    // Les fonctions static doivent étre implémenter hors de la classe
    static int nbrChaines();

    CString operator+(const char& c)
    {
        CString res = *this;
        if (res.len + 1 == res.size)
            res.resize(res.size * 2);
        res.c_str[res.len] = c;
        res.len++;
        res.c_str[res.len] = '\0';
        return res;
    }

    // Operateur d'assignation
    const CString& operator=(const CString& s)
    {
        resize(s.size);
        len = s.len;
        strcpy(c_str.get(), s.c_str.get());
        return *this;
    }

    // Operateur de deplacement, notions avancées de gestion de mémoire
    const CString& operator=(CString&& s) 
    {
        size = s.size;
        len = s.len;
        c_str = std::move(s.c_str);
        return *this;
    }


    // Operateur de comparaisons
    bool operator>=(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str[i] != s.c_str[i]))
                return c_str[i] > s.c_str[i];
        }
        return true;
    }

    bool operator>(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str[i] != s.c_str[i]))
                return c_str[i] > s.c_str[i];
        }
        return false;
    }

    bool operator<=(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str[i] != s.c_str[i]))
                return c_str[i] < s.c_str[i];
        }
        return true;
    }

    bool operator<(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str[i] != s.c_str[i]))
                return c_str[i] < s.c_str[i];
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& stream, const CString& s)
    {
        for (int i = 0; i < s.len; i++)
            stream << s.c_str[i];
        return stream;
    }

    const CString& plusGrand(const CString& s) const
    {
        // Vu que l'on a implémenter les opérateurs >, <, >=, <=, on peut utiliser std::max
        return std::max(*this, s);
    }

    const char* getString() const
    {
        return c_str.get();
    }   
};

// on implémente les variable/fct static
// Il faudrait faire pareille si on découpait nos classe en .cpp et .hpp

int CString::nbr_chaines = 0;

int CString::nbrChaines()
{
    return nbr_chaines;
}

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
    Definition homer( std::move("Homer"), std::move("Buveur de biere")) ;
    std::cout << "la definition du mot " << homer.getClef() << " est "<<
    homer.getDef() << std::endl ; 
} 