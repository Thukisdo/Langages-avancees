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
        strcpy(c_str.get(), tmp.get());
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
        CString(s.c_str.get());
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