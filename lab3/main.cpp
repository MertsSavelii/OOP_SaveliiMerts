#include <iostream>
#include "tbinarytree.h"
#include "octagon.h"

int main()
{
    Octagon octi[8];
    TBinaryTree tree;
    for (int i = 0; i < 8; i++)
    {
        std::cin>>octi[i];
        tree.Push(octi[i]);
    }
    
    std::cout << tree << std::endl;
    //a = tree.GetItemNotLess(b->Area());
    //std::cout << *a << std::endl;
    //std::cout << tree.Count(a) << std::endl;
    //tree.Pop(a);
    //tree.Pop(a);
    //std::cout << tree << std::endl;
    //tree.Clear();
    //std::cout << tree << std::endl;
    //if (tree.Empty())
        //std::cout << "дерево пустое" << std::endl;
    return 0;
}