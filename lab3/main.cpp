#include <iostream>
#include "tbinarytree.h"
#include "octagon.h"

int main()
{
    Octagon octi[8];
    for (int i = 0; i < 8; i++)
    {
        std::cin>>octi[i];
    }
    SPTR(Octagon) a(new Octagon(octi[0]));
    SPTR(Octagon) b(new Octagon(octi[1]));
    SPTR(Octagon) c(new Octagon(octi[2]));
    SPTR(Octagon) d(new Octagon(octi[3]));
    SPTR(Octagon) e(new Octagon(octi[4]));
    SPTR(Octagon) f(new Octagon(octi[5]));
    SPTR(Octagon) g(new Octagon(octi[6]));
    SPTR(Octagon) h(new Octagon(octi[7]));

    TBinaryTree tree;
    tree.Push(a);
    tree.Push(b);
    tree.Push(c);
    tree.Push(d);
    tree.Push(e);
    tree.Push(f);
    tree.Push(g);
    tree.Push(h);
    
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