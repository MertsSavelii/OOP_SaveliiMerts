#include <iostream>
#include "tbinarytree.h"
#include "octagon.h"

using namespace std;
int main()
{
    Octagon a[8];
    TBinaryTree tree;
    for (int i = 0; i < 8; i++)
    {
        cin>>a[i];
        tree.Push(a[i]);
    }
    
    cout << tree << endl;
    cout << tree.Count(20, 50) << " - кол фигур в диапазоне 20-50" << endl;
    tree.Pop(a[2]);
    cout << tree << endl;
    TBinaryTree biba(tree);
    tree.Clear();
    cout << biba << endl << tree << endl;
    return 0;
}