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


    void resize(size_t new_size)
    {
        auto tmp = std::make_unique<char[]>(new_size);
        if (len > 0)
            strcpy(tmp.get(), c_str.get());
        size = new_size;
        c_str = std::move(tmp);
    }

    public:

    CString() : len(0) {nbr_chaines++;};
    CString(const char* s) 
    {
        len = strlen(s);
        size = len + 1;
        c_str = std::make_unique<char[]>(size);
        strcpy(c_str.get(), s);
        nbr_chaines++;
    };

    CString(char k)
    {
        len = 1;
        size = len + 1;
        c_str = std::make_unique<char[]>(size);
        c_str[0] = k;
        c_str[1] = '\0';
        nbr_chaines++;
    }

    CString(const CString& s) : CString(s.c_str.get()) {}

    CString(CString&& s)
    {
        len = s.len;
        size = s.size;
        c_str = std::move(s.c_str);
        s.len = 0;
        s.size = 0;
    }

    static int nbrChaines();

    const CString& operator+(const char& c)
    {
        if (len + 1 == size)
            resize(size * 2);
        c_str[len] = c;
        len++;
        c_str[len] = '\0';
        return *this;
    }

    const CString& operator=(const CString& s)
    {
        resize(s.size);
        len = s.len;
        strcpy(c_str.get(), s.c_str.get());
        return *this;
    }

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
        return std::max(*this, s);
    }

    const char* getString() const
    {
        return c_str.get();
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
    std::cout << "s3=" << s3 << std::endl ;
    if( s1 > s2 ) // si s1 > s2 au sens alphabétique
        std::cout << "plus grand" << std::endl ;
    if( s1 <= s2) // si s1 <= s2 au sens alphabétique
        std::cout << "plus petit" << std::endl ;
    s3 = s1.plusGrand( s2 ) ;// retourner s1 si s1>s2, s2 sinon
} 