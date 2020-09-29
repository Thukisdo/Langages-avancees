/** Auteur : Mathys JAM TD1A
 * Je vous recommande d'essayer par vous meme avant de lire les corrections
 * Cette correction n'est qu'a titre indicatif, et a ete ecrite par un eleve
 * 
 * J'uttilise certaines notions avancés qui ne seront peut etre pas vu en cours
 * Cependant, elles correspondent a une utilisation correcte du c++
 * 
 * 
 * 
 * N'hesitez pas a me contactez
 * Discord : Thukisdo#8050
 */

#include <iostream>
#include <memory>
#include <string.h>

// On utilise pas
// using namespace std;
// parcequ'on est pas des enculé

// de maniere optimale, on créerait un template Vecteur
// et on ferait de l'héritage
// Cependant on va garder sa simple

class VecteurTableau
{
private:
    // on sépare la taille réele de la taille allouer
    unsigned int m_size_alloc;
    unsigned int m_size;
    std::unique_ptr<int[]> m_array;

    // on agrandi le tableau
    void resize(unsigned int newSize)
    {
        std::unique_ptr<int[]> tmp = std::make_unique<int[]>(newSize);
        memcpy(tmp.get(), m_array.get(), m_size * sizeof(int));
        m_array = std::move(tmp);
        m_size_alloc = newSize;
    }

    void resize()
    {
        if (m_size_alloc == 0)
            m_size_alloc = 1;
        resize(m_size_alloc * 2);
    }

public:
    VecteurTableau() : m_size_alloc(0), m_size(0)
    {
    }

    // on réutilise directement les operator=
    VecteurTableau(VecteurTableau const &val) : m_size_alloc(0), m_size(0)
    {
        *this = val;
    }

    VecteurTableau(VecteurTableau &&val)
    {
        *this = val;
    }

    VecteurTableau &operator=(VecteurTableau const &val)
    {
        if (m_size_alloc < val.m_size)
            resize(val.m_size);
        m_size = val.m_size;
        for (int i = 0; i < val.m_size; i++)
            m_array[i] = val[i];
        return *this;
    }

    // assignation par mouvement
    VecteurTableau &operator=(VecteurTableau &&val)
    {
        m_size = val.m_size;
        m_size_alloc = val.m_size_alloc;
        m_array = std::move(val.m_array);
        val.m_size = 0;
        val.m_size_alloc = 0;
        return *this;
    }

    int operator[](unsigned int index) const
    {
        if (index >= m_size)
            throw new std::overflow_error("Index is ouf of bound");
        return m_array[index];
    }

    int &operator[](unsigned int index)
    {
        if (index >= m_size)
            throw new std::overflow_error("Index is ouf of bound");
        return m_array[index];
    }

    VecteurTableau &operator+=(int const &n)
    {
        if (m_size + 1 >= m_size_alloc)
            resize();
        m_array[m_size++] = n;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, VecteurTableau const &val)
    {
        for (int i = 0; i < val.m_size; i++)
            os << val[i] << " ";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, VecteurTableau &val)
    {
        int tmp;
        is >> tmp;
        val += tmp;
        return is;
    }
};

class VecteurListe
{
private:
    struct elem
    {
        int value;
        std::shared_ptr<struct elem> next;
    };

    std::shared_ptr<elem> begin;
    std::shared_ptr<elem> end;
    unsigned int m_size;

    void insert(int val)
    {
        if (begin == nullptr)
        {
            begin = std::make_shared<elem>();
            begin->value = val;
            end = begin;
            return;
        }
        end->next = std::make_shared<elem>();
        end = end->next;
        end->value = val;
    }

    int &get(unsigned int val) const
    {
        if (val > m_size)
            throw new std::out_of_range("Index is out of bound");
        std::shared_ptr<elem> current = begin;
        for (int i = 0; i < val; i++)
            current = current->next;
        return current->value;
    }

    void copy(std::shared_ptr<elem> ptr)
    {
        if (ptr == nullptr)
            return;

        std::shared_ptr<elem> current = begin;
        while (ptr != nullptr)
        {
            if (current == nullptr)
                insert(ptr->value);
            else
            {
                current->value = ptr->value;
                current = current->next;
            }
            ptr = ptr->next;
        }
        end->next == nullptr;
    }

public:
    VecteurListe() : begin(nullptr), end(nullptr)
    {
    }

    // on réutilise directement les operator=
    VecteurListe(VecteurListe const &val)
    {
        *this = val;
    }

    VecteurListe(VecteurListe &&val)
    {
        *this = val;
    }

    VecteurListe &operator=(VecteurListe const &val)
    {
        m_size = val.m_size;
        copy(val.begin);
        return *this;
    }

    // assignation par mouvement
    VecteurListe &operator=(VecteurListe &&val)
    {
        begin = val.begin;
        end = val.end;
        val.begin = nullptr;
        val.end = nullptr;
        m_size = val.m_size;
        return *this;
    }

    int operator[](unsigned int index) const
    {
        return get(index);
    }

    int &operator[](unsigned int index)
    {
        return get(index);
    }

    VecteurListe &operator+=(int const &n)
    {
        insert(n);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, VecteurListe const &val)
    {
        for (std::shared_ptr<elem> current = val.begin; current != nullptr; current = current->next)
            os << current->value << " ";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, VecteurListe &val)
    {
        int tmp;
        is >> tmp;
        val.insert(tmp);
        return is;
    }
};

int main()
{
    VecteurTableau a;
    for (int i = 0; i < 5; i++)
        a += i;

    std::cout << "a : " << a << std::endl
              << std::endl;

    VecteurTableau b;

    std::cout << "b : " << b << std::endl
              << std::endl;

    b = std::move(a);
    std::cout << "b : " << b << std::endl
              << std::endl;

    VecteurTableau c(b);
    std::cout << "c : " << c << std::endl;

    std::cout << std::endl
              << " ============================ En utilisant des listes \n\n";

    VecteurListe x;
    for (int i = 0; i < 5; i++)
        x += i;
    std::cout << "x : " << x << std::endl
              << std::endl;

    VecteurListe y;
    std::cout << "y : " << y << std::endl
              << std::endl;
    y = std::move(x);
    std::cout << "y : " << y << std::endl
              << std::endl;
    VecteurListe z(y);
    std::cout << "z : " << z << std::endl;
}