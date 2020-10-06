#pragma once
#include <iostream>
#include <memory>

class CList {
protected:
    struct elem {
        elem(int value = 0);
        std::shared_ptr<elem> next;
        int value;
    };

    std::shared_ptr<elem> begin;
    std::shared_ptr<elem> end;

    elem& getElem(int index) const;
    virtual elem& push(int value) = 0;
    virtual void pop() = 0;
    void clear();

public:
    CList();
    CList(CList const& val);

    CList& operator=(CList const& val);
    CList& operator=(CList&& val);


    /** En regle géneral, je prefere utiliser des méthode pop() push() peek() plutot que l'opérateur << ou >>
     * 
     */


    /**
     * @brief insert a value inside the list
     * 
     * @param list 
     * @param val 
     * @return CList& 
     */
    friend CList& operator<<(CList& list, int const val);

    /**
     * @brief extract a value from the list
     * 
     * @param list 
     * @param val 
     * @return CList& 
     */
    friend CList& operator>>(CList& list, int& val);


    /**
     * @brief Output the full stack to ostream
     * 
     * @param os 
     * @param val 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, CList const& val);

    /**
     * @brief Acess a given value from the list
     * 
     * @param index 
     * @return int 
     */
    int front() const;

    bool isEmpty() {return begin == nullptr;};
};