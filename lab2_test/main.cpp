#include "tree_elem.h"
#include <iostream>
#include "tbinarytree.h"

int main()
{
    TBinaryTree tree;
    int a [10] = {50, 30, 60, 10, 40, 60, 55, 70, 45, 45};
    for (int i = 0; i < 10; i++)
    {
        tree.Push(a[i]);
    }
    
    std::cout<<tree<<std::endl;
    //std::cout<<tree.t_root->area<<std::endl;
    return 0;
}