#include "CString.hpp"

#include <iostream>
#include <memory>

int CString::nbr_chaines = 0;

// Fonctions privé pour reallouer le tableau interne
void CString::resize(size_t new_size)
{
    if (new_size < m_allocated_size)
        throw std::invalid_argument("Tried to expand by reducing CString size");
    if (new_size == 0)
        return;
    if (new_size == m_allocated_size)
        return;
    auto tmp = std::make_unique<char[]>(new_size);
    if (m_len > 0)
        strcpy(tmp.get(), m_c_str.get());
    m_allocated_size = new_size;
    m_c_str = std::move(tmp);
}

// Fonction pour réduire la taille du tableau
void CString::shrink(size_t new_size)
{
    if (new_size > m_allocated_size)
        throw std::invalid_argument("Tried to shrink by increasing Cstring size");
    if (new_size == m_allocated_size)
        return;
    auto tmp = std::make_unique<char[]>(new_size);
    strncpy(tmp.get(), m_c_str.get(), m_len);
    m_allocated_size = new_size;
    m_c_str = std::move(tmp);
}

int CString::getNbrString()
{
    return nbr_chaines;
}

CString::CString() : m_len(0), m_allocated_size(0)
{
    nbr_chaines++;
}

CString::CString(const char *s) : m_len(0), m_allocated_size(0)
{
    if (s == nullptr)
        throw std::invalid_argument("Tried to create CString from null pointer");
    int length = strlen(s);
    resize(length + 1);
    strcpy(m_c_str.get(), s);
    m_len = length;
    nbr_chaines++;
}

CString::CString(char k) : m_len(0), m_allocated_size(0)
{
    resize(2);
    m_c_str[0] = k;
    m_c_str[1] = '\0';
    m_len = 1;
    nbr_chaines++;
}

// On appel l'assignation de copie
CString::CString(CString const &str) : m_len(0), m_allocated_size(0)
{
    *this = str;
    nbr_chaines++;
}

// On appel l'assignation de mouvement
CString::CString(CString &&str) : m_len(0), m_allocated_size(0)
{
    *this = std::move(str);
}

CString::~CString()
{
    nbr_chaines--;
}

void CString::shrinkToFit()
{
    if (m_len == 0)
        return;
    shrink(m_len + 1);
}

void CString::resize()
{
    if (m_allocated_size == 0)
        m_allocated_size = 10;
    resize(m_allocated_size * 2);
}

// Copy assignement
CString &CString::operator=(const CString &s)
{
    if (s.m_len == 0)
        return *this;
    int length = s.m_len;
    if (m_allocated_size < length + 1)
        resize(length + 1);
    strcpy(m_c_str.get(), s);
    int tmp = m_len;
    m_len = length;
    if (m_len * 2 < m_allocated_size)
        shrinkToFit();
    return *this;
}
// Move assignement
CString &CString::operator=(CString &&s)
{
    if (s.m_c_str == nullptr)
        return *this;
    m_len = s.m_len;
    m_allocated_size = s.m_allocated_size;
    m_c_str = std::move(s.m_c_str);
    s.m_len = 0;
    s.m_allocated_size = 0;
    return *this;
}

CString CString::operator+(char const &c) const
{
    CString res;
    res.resize(m_len + 2);
    res = *this;
    return (res += c);
}

CString CString::operator+(char const *str) const
{
    if (str == nullptr)
        throw std::invalid_argument("Tried to add from null pointer");
    CString res;
    int length = strlen(str);
    res.resize(m_len + length + 1);
    res = *this;
    return (res += str);
}

CString CString::operator+(CString const &str) const
{
    return *this + str;
}

CString &CString::operator+=(const char &c)
{
    if (m_allocated_size < m_len + 2)
        resize();
    m_c_str[m_len++] = c;
    m_c_str[m_len] = '\0';
    return *this;
}

CString &CString::operator+=(const char *str)
{
    if (str == nullptr)
        throw std::invalid_argument("Tried to expand from a nullptr");
    size_t taille = strlen(str);
    if (m_allocated_size < m_len + taille + 1)
        resize(std::max(m_allocated_size, taille) * 2);
    memcpy(&m_c_str[m_len], str, taille);
    m_len += taille;
    m_c_str[m_len + 1] = '\0';
    return *this;
}

CString &CString::operator+=(CString const &str)
{
    return *this += str;
}

CString CString::substring(size_t begin, size_t end)
{
    if (begin >= end | end > m_len | begin > m_len)
        throw std::invalid_argument("Invalid range");
    CString res;
    res.resize(end - begin + 1);
    strncpy(res, &m_c_str[begin], end - begin);
    res.m_len = end - begin;
    return res;
}

CString& CString::clear()
{
    m_c_str = nullptr;
    m_len = 0;
    m_allocated_size = 0;
    return *this;
}

char &CString::operator[](int index)
{
    if (index > m_len)
        throw std::invalid_argument("Index is out of bound");
    return m_c_str[index];
}

std::ostream &operator<<(std::ostream &stream, const CString &s)
{
    for (int i = 0; i < s.m_len; i++)
        stream << s[i];
    return stream;
}

std::istream &operator>>(std::istream &stream, CString &s)
{
    char tmp;
    stream >> tmp;
    while (tmp != '\0' && tmp != '\n') {
        s += tmp;
        stream >> tmp;
    }
    return stream;
}

bool CString::operator==(const CString &s) const
{
    if (m_len != s.m_len)
        return false;
    for (int i = 0; i < std::min(m_len, s.m_len); i++)
    {
        if ((m_c_str[i] != s[i]))
            return false;
    }
    return true;
}

bool CString::operator>=(const CString& s) const
{
    for (int i = 0; i < std::min(m_len, s.m_len); i++)
    {
        if ((m_c_str[i] != s[i]))
            return m_c_str[i] > s[i];
    }
    return (m_len == s.m_len) ? true : false;
}

bool CString::operator>(const CString& s) const
{
    for (int i = 0; i < std::min(m_len, s.m_len); i++)
    {
        if ((m_c_str[i] != s[i]))
            return m_c_str[i] > s[i];
    }
    return false;
}
bool CString::operator<=(const CString &s) const
{
    return !(*this > s);
}
bool CString::operator<(const CString &s) const
{
    return (*this >= s);
}

CString::operator char *() const
{
    return m_c_str.get();
}

const char *CString::getCstr() const
{
    return m_c_str.get();
}
