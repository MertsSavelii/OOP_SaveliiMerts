#include <iostream>
#include "tbinarytree.h"
#include "octagon.h"

int main()
{
    Octagon a[8];
    TBinaryTree tree;
    for (int i = 0; i < 8; i++)
    {
        std::cin>>a[i];
        tree.Push(a[i]);
    }
    
    std::cout << tree << std::endl;
    std::cout << tree.Count(20, 50) << " - кол фигур в диапазоне 20-50" << std::endl;
    tree.Pop(a[2]);
    std::cout << tree << std::endl;
    tree.Clear();
    std::cout << tree << std::endl;
    
    /*TBinaryTree biba(tree);
    tree.Clear();
    std::cout << std::make_shared<TBinaryTree> (biba); 
    std::cout << std::endl << std::make_shared<TBinaryTree> (tree);
    std::cout << std::endl;*/
    return 0;
}