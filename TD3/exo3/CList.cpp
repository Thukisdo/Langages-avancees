#include "CList.hpp"

CList::elem::elem(int value) : value(value)
{

}

CList::elem& CList::getElem(int index) const
{
    auto current = begin;
    if (current == nullptr)
        throw std::invalid_argument("List is empty");
    for (int i = 0; i < index; current = current->next, i++)
    {
        if (current == nullptr)
            throw std::overflow_error("Index is out of range");
    }
    return *current;
}

void CList::clear()
{
    begin = nullptr;
    end = nullptr; // Vu qu'on utilise des shared_ptr, les dealloc se fait tout seul
}


CList::CList() : begin(nullptr), end(nullptr)
{

}

CList::CList(CList const& val)
{
    *this = val;
}

CList& CList::operator=(CList const& val)
{
    auto ptr = val.begin;
    if (ptr == nullptr) 
            return begin = nullptr, *this;

    auto current = begin;
    while (ptr != nullptr)
    {
        if (current == nullptr)
            push(ptr->value);
        else
        {
            current->value = ptr->value;
            current = current->next;
        }
        ptr = ptr->next;
    }
    end->next == nullptr;
    return *this;
}

CList& CList::operator=(CList&& val)
{
    begin = val.begin;
    end = val.end;
    val.end = nullptr;
    val.begin = nullptr;
    return *this;
}


CList& operator<<(CList& list, int val)
{
    list.push(val);
    return list;
}


CList& operator>>(CList& list, int& val)
{
    val = list.front();
    list.pop();
    return list;
}

std::ostream& operator<<(std::ostream& os, CList const& val)
{
    for (auto current = val.begin; current != nullptr; current = current->next)
        os << current->value << " ";
    return os;
}


int CList::front() const
{
    return getElem(0).value;
}
