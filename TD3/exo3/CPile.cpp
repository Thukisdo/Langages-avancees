#include "CPile.hpp"


CList::elem& CPile::push(int value)
{
    auto current = begin;
    auto tmp = std::make_shared<elem>(value);

    tmp->next = current;
    begin = tmp;
    if (end == nullptr)
        end = begin;
    return *begin;
}

void CPile::pop()
{
    if (begin == nullptr)
        return;
    begin = begin->next;
    if (begin == nullptr)
        end = nullptr;
}