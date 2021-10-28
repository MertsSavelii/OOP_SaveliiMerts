#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include <iostream>
#include "tree_elem.h"
#include "octagon.h"

class TBinaryTree {
public:
    TBinaryTree();

    TBinaryTree(const TBinaryTree& other);

    void Push(Octagon octagon);
    void Pop(Octagon octagon);
    void Clear();
    bool Empty();
    double Count(double min_area, double max_area);

    friend std::ostream& operator<<(std::ostream& os, const TBinaryTree tree);

    virtual ~TBinaryTree();
private:
    sptr(TreeElem) t_root;
};
#endif