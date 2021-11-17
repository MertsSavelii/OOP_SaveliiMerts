#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include <iostream>
#include "tree_elem.h"
#include "octagon.h"

class TBinaryTree {
 public:
 TBinaryTree();
 
 void Push(const Octagon& octagon);

 const Octagon& GetItemNotLess(double area);

 size_t Count(const Octagon& octagon);

 void Pop(const Octagon& octagon);

 bool Empty();

 friend std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree);

 void Clear();

 virtual ~TBinaryTree();
 private:
 TreeElem* t_root;
};

#endif