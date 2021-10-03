#include <iostream>
#include "tree_elem.h"

TreeElem::TreeElem() {
    area = -1;
    count_fig = 0;
    t_left = nullptr;
    t_right = nullptr;
}

TreeElem::TreeElem(int octagon) {
    area = octagon;
    count_fig = 1;
    t_left = nullptr;
    t_right = nullptr;
}

void TreeElemDel(TreeElem *elem) {
    delete elem->t_left;
    delete elem->t_right;
    delete elem;
}

TreeElem::~TreeElem() {
    delete t_left;
    delete t_right;
    std::cout << "элемент дерева удалён" << std::endl;
}