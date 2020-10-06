#pragma once


#include "CList.hpp"

class CPile : public CList {
protected:
    /**
     * @brief insert an element on top of the stack
     * 
     * @param value 
     * @return elem& 
     */
    virtual elem& push(int value);

    /**
     * @brief pop the first element of the stack
     * 
     */
    virtual void pop();

public:

using CList::CList;
using CList::operator=;

};