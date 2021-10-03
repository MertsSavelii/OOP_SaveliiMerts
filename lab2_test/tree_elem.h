#ifndef TREEELEM_H
#define TREEELEM_H


#include <iostream>

class TreeElem{
    public:
    TreeElem();
    TreeElem(int octagon);
    void TreeElemDel(TreeElem *elem);
    virtual ~TreeElem();
    int area;
    int count_fig;
    TreeElem * t_left;
    TreeElem * t_right;
};

#endif