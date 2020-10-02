#include <iostream>
#include <memory>
#include <string.h>

class CString
{
private:
    std::unique_ptr<char[]> m_c_str;
    size_t m_len;
    size_t m_allocated_size;
    static int nbr_chaines;

    // Fonctions privé pour reallouer le tableau interne
    void resize(size_t new_size);
    void shrink(size_t new_size);

public:
    static int getNbrString();

    CString();
    CString(const char *s);
    CString(char k);

    // On appel le constructeur char*
    CString(CString const &s);
    CString(CString &&s);

    ~CString();

    void shrinkToFit();
    void resize();

    // Copy assignement
    CString &operator=(const CString &str);
    // Move assignement
    CString &operator=(CString &&str);

    CString operator+(char const &c) const;
    CString operator+(char const *str) const;
    CString operator+(CString const &str) const;

    CString &operator+=(const char &c);
    CString &operator+=(const char *str);
    CString &operator+=(CString const &str);

    CString substring(size_t begin, size_t end);
    CString replace(CString const &c, CString const &pattern);
    CString& clear();


    friend std::ostream &operator<<(std::ostream &stream, const CString &s);
    friend std::istream &operator>>(std::istream &stream, CString &s);

    // Operateur de comparaisons
    bool operator==(const CString &s) const;
    bool operator>=(const CString &s) const;
    bool operator>(const CString &s) const;
    bool operator<=(const CString &s) const;
    bool operator<(const CString &s) const;


    char &operator[](int index);
    operator char *() const;

    const char *getCstr() const;
};
