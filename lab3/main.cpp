#include <iostream>
#include "tbinarytree.h"
#include "octagon.h"

int main()
{
    Octagon a[8];
    sptr(TBinaryTree) tree;
    for (int i = 0; i < 8; i++)
    {
        std::cin>>a[i];
        tree->Push(a[i]);
    }
    
    std::cout << tree;
    //tree->Count(20, 50);
    /*std::cout << tree << " - кол фигур в диапазоне 20-50" << std::endl;
    tree->Pop(a[2]);
    std::cout << tree << endl;
    TBinaryTree biba(tree);
    tree.Clear();
    std::cout << biba << endl << tree << endl;*/
    return 0;
}