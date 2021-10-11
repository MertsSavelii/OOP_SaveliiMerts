#ifndef TREEELEM_H
#define TREEELEM_H


#include <iostream>
#include "octagon.h"

class TreeElem{
    public:
    TreeElem(Octagon val);
    virtual ~TreeElem();
    Octagon figure;
    int count_fig;
    TreeElem * t_left;
    TreeElem * t_right;
};

#endif