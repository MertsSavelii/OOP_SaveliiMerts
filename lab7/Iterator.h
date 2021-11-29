#ifndef ITERATOR_H
#define ITERATOR_H

#include "tbinarytree.h"
#include <iostream>
#include <memory>

template <class Elem, class Poligon>
class Iterator
{
    public:
        Iterator(std::shared_ptr<Elem> n)
        {
            curr = n;
            root = curr;
            prev = nullptr;
        }
        Iterator& operator=(const Iterator& curr_)
        {
            curr = curr_.curr;
            root = curr_.root;
            prev = curr_.prev;
            return *this;
        }
        bool operator==(const Iterator& curr_)
        {
            return curr == curr_.curr;
        }
        bool operator!=(const Iterator& curr_)
        {
            return !(curr == curr_.curr);
        }
        Poligon operator*(){
            return curr->get_poligon();
        }
        Iterator& operator++ ()
        {
            curr = root;
            while (curr->get_left() && curr->get_right() && curr->get_left() != prev && curr->get_right() != prev)
            {
                if (curr->get_left() && curr->get_left() != prev) curr = curr->get_left();
                if (curr->get_right() && curr->get_right() != prev) curr = curr->get_right();
            }
            prev = curr;
        
            return *this;
        }
        Iterator& operator++ (int)
        {
            Iterator tmp(*curr);
            ++(*this);
            return curr;
        }
    
        std::shared_ptr<Elem> root;//то что выше курр
        std::shared_ptr<Elem> curr;
        std::shared_ptr<Elem> prev;//то что курр уже выдал
};
#endif