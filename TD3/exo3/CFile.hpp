#pragma once


#include "CList.hpp"

class CFile : public CList {
protected:
    /**
     * @brief Insert an element at the end of the queue
     * 
     * @param value 
     * @return elem& 
     */
    virtual elem& push(int value);

    /**
     * @brief pop the first element of the queue
     * 
     */
    virtual void pop();

public:

using CList::CList;
using CList::operator=;

};