#ifndef TBINARYTREE_H
#define TBINARYTREE_H

#include <iostream>
#include "tree_elem.h"
#include "octagon.h"

class TBinaryTree {
 public:
 TBinaryTree();
 
 void Push(const SPTR(Octagon) octagon);

 const SPTR(Octagon) GetItemNotLess(double area);

 size_t Count(const SPTR(Octagon) octagon);

 void Pop(const SPTR(Octagon) octagon);

 bool Empty();

 friend std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree);

 void Clear();

 virtual ~TBinaryTree();
 private:
 SPTR(TreeElem) t_root;
};

#endif