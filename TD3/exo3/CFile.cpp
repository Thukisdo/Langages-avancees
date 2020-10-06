#include "CFile.hpp"


CList::elem& CFile::push(int value)
{
    auto tmp = std::make_shared<elem>(value);
    if (end == nullptr)
        begin = end = tmp;
    else {
        end->next = tmp;
        end = end->next;
    }
    return *tmp;
}

void CFile::pop()
{
    if (begin == nullptr)
        return;
    begin = begin->next;
    if (begin == nullptr)
        end = nullptr;
}

