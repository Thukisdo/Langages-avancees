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
    /**
     * @brief Expand the internal array to the given size
     * 
     * @param new_size size to expand to
     */
    void resize(size_t new_size);

    /**
     * @brief shrink the internal array to the given size
     * 
     * @param new_size size to shrink to
     */
    void shrink(size_t new_size);

    /**
     * @brief return the internal array
     * 
     * @return char * 
     */
    operator char *() const;

public:

    /**
     * @brief Get the Nbr of CString object
     * 
     * @return int 
     */
    static int getNbrString();

    /**
     * @brief Construct a new CString object
     * 
     */
    CString();

    /**
     * @brief Construct a new CString object from a char*
     * 
     * @param s 
     */
    CString(const char *s);

    /**
     * @brief Construct a new CString object from a char
     * 
     * @param k 
     */
    CString(char k);

    /**
     * @brief Copy constructor
     * 
     * @param s 
     */
    CString(CString const &s);

    /**
     * @brief Move constructor
     * 
     * @param s 
     */
    CString(CString &&s);

    /**
     * @brief Destroy the CString object and decrease string count
     * 
     */
    ~CString();


    /**
     * @brief Shrink the internal array to fit the string len
     * 
     */
    void shrinkToFit();
    /**
     * @brief Expand the internal array to 2 times it's size
     * 
     */
    void resize();

    /**
     * @brief copy assignement
     * 
     * @param str 
     * @return CString& 
     */
    CString &operator=(const CString &str);
    
    /**
     * @brief Move assignement
     * 
     * @param str 
     * @return CString& 
     */
    CString &operator=(CString &&str);

    /**
     * @brief add a char to this string and return the result
     * 
     * @param c 
     * @return CString 
     */
    CString operator+(char const &c) const;

    /**
     * @brief append a string to this CString and return the result
     * 
     * @param str 
     * @return CString 
     */
    CString operator+(char const *str) const;

    /**
     * @brief Append a CString to this Cstring and return the result
     * 
     * @param str 
     * @return CString 
     */
    CString operator+(CString const &str) const;

    /**
     * @brief Append a char, resizing the array if need be
     * 
     * @param c 
     * @return CString& 
     */
    CString &operator+=(const char &c);

    /**
     * @brief Append a string, resizing the array if need be
     * 
     * @param str 
     * @return CString& 
     */
    CString &operator+=(const char *str);

    /**
     * @brief Append a CString, resizing the array if need be
     * 
     * @param str 
     * @return CString& 
     */
    CString &operator+=(CString const &str);

    /**
     * @brief return a substring of this CString
     * 
     * @param begin first position of the substring
     * @param end end of the substring
     * @return CString 
     */
    CString substring(size_t begin, size_t end);

    /**
     * @brief Empty the string
     * 
     * @return CString& 
     */
    CString& clear();

    /**
     * @brief Insert this CString inside a stream
     * 
     * @param stream 
     * @param s 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &stream, const CString &s);

    /**
     * @brief Read a from a stream until a newline or EOF is found
     * 
     * @param stream 
     * @param s 
     * @return std::istream& 
     */
    friend std::istream &operator>>(std::istream &stream, CString &s);

    /**
     * @brief Compare two string
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool operator==(const CString &s) const;

    /**
     * @brief return true if this CString is greater or equal to s, using lexical order
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool operator>=(const CString &s) const;

    /**
     * @brief return true if this CString is greater than s, using lexical order
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool operator>(const CString &s) const;

    /**
     * @brief return true if this CString is lesser or equal to s, using lexical order
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool operator<=(const CString &s) const;

    /**
     * @brief return true if this CString is lesser to s, using lexical order
     * 
     * @param s 
     * @return true 
     * @return false 
     */
    bool operator<(const CString &s) const;

    /**
     * @brief Acess the internal array in a secured way
     * 
     * @param index 
     * @return char& 
     */
    char &operator[](int index);

    /**
     * @brief Get the internal array
     * 
     * @return const char* 
     */
    const char *getCstr() const;
};
