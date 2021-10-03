#include "tree_elem.h"

TreeElem::TreeElem(Octagon val) {
    t_left = nullptr;
    t_right = nullptr;
    figure = val;
    count_fig = 1;
}

TreeElem::~TreeElem() {
    
}