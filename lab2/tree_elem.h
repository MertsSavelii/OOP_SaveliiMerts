#ifndef TREEELEM_H
#define TREEELEM_H


#include <iostream>
#include "octagon.h"

class TreeElem{
    public:
    TreeElem();
    TreeElem(Octagon octagon);
    void TreeElemDel(TreeElem *elem);
    virtual ~TreeElem();
    Octagon octi;
    int count_fig;
    TreeElem * t_left;
    TreeElem * t_right;
};

#endif