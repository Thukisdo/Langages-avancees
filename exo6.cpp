#include <iostream>
#include <memory>
#include <string.h>

class CString
{
    private:
    std::shared_ptr<char> c_str;
    size_t len;
    int size;
    static int nbr_chaines;


    void resize(size_t new_size)
    {
        auto tmp = std::make_shared<char>(new_size);
        strcpy(tmp.get(), c_str.get());
        size = new_size;
    }

    public:

    CString() : len(0) {nbr_chaines++;};
    CString(char* s) 
    {
        len = strlen(s);
        size = len + 1;
        c_str = std::make_shared<char>(size);
        strcpy(c_str.get(), s);
        nbr_chaines++;
    };

    CString(char k)
    {
        len = 1;
        size = len + 1;
        c_str = std::make_shared<char>(size);
        c_str.get()[0] = k;
        c_str.get()[1] = '\0';
        nbr_chaines++;
    }

    CString(const CString& s)
    {
        CString(s.c_str.get());
    }

    CString(CString&& s)
    {
        len = s.len;
        c_str = s.c_str;
        s.c_str = nullptr;
    }

    static int nbrChaines();

    const CString& operator+(const char& c)
    {
        if (len + 1 == size)
            resize(size * 2);
        c_str.get()[len] = c;
        len++;
        c_str.get()[len] = '\0';
        return *this;
    }

    const CString& operator=(const CString& s)
    {
        CString(s.c_str.get());
        return *this;
    }

    bool operator>=(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str.get()[i] != s.c_str.get()[i]))
                return c_str.get()[i] > s.c_str.get()[i];
        }
        return true;
    }

    bool operator>(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str.get()[i] != s.c_str.get()[i]))
                return c_str.get()[i] > s.c_str.get()[i];
        }
        return false;
    }

    bool operator<=(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str.get()[i] != s.c_str.get()[i]))
                return c_str.get()[i] < s.c_str.get()[i];
        }
        return true;
    }

    bool operator<(const CString& s) const
    {
        for (int i = 0; i < std::min(len, s.len); i++)
        {
            if ((c_str.get()[i] != s.c_str.get()[i]))
                return c_str.get()[i] < s.c_str.get()[i];
        }
        return false;
    }

    const CString& plusGrand(const CString& s) const
    {
        return std::max(*this, s);
    }

    std::shared_ptr<char> getString()
    {
        return c_str;
    }
};

int CString::nbr_chaines = 0;

int CString::nbrChaines()
{
    return nbr_chaines;
}

int main()
{
    CString s1( "toto" ),
    s2( 'q' ),
    s3 ;

    std::cout << "nbrChaines" << CString::nbrChaines() << std::endl ;
    //afficher le nombre de chaines créées
    s3 = s1 + 'w';
    std::cout << "s3=" << s3.getString().get() << std::endl ;
    if( s1 > s2 ) // si s1 > s2 au sens alphabétique
        std::cout << "plus grand" << std::endl ;
    if( s1 <= s2) // si s1 <= s2 au sens alphabétique
        std::cout << "plus petit" << std::endl ;
    s3 = s1.plusGrand( s2 ) ;// retourner s1 si s1>s2, s2 sinon
} 