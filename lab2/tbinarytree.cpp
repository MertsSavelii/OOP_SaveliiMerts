#include "tbinarytree.h"
#include <iomanip>
#include <iostream>


TBinaryTree::TBinaryTree() {
    Octagon octi;
    t_root = new TreeElem(octi);
}

TBinaryTree::TBinaryTree(const TBinaryTree& other) {

}

void TBinaryTree::Push(Octagon octagon) {
    TreeElem *curr = t_root;
    while (curr && curr->figure.Area() != octagon.Area())
    {
        if (curr->figure.Area() > octagon.Area() && curr->t_left == NULL)
        {
            curr->t_left = new TreeElem(octagon);
            return;
        }
        if (curr->figure.Area() < octagon.Area() && curr->t_right == NULL)
        {
            curr->t_right = new TreeElem(octagon);
            return;
        }
        if (curr->figure.Area() > octagon.Area())
            curr = curr->t_left;
        else
            curr = curr->t_right;
    }
    if (curr->figure.Area() == octagon.Area()){
        curr->count_fig++;
    }
    
}

void TBinaryTree::Pop(Octagon octagon) {
    TreeElem *curr = t_root;
    TreeElem *parent = nullptr;
    while (curr && curr->figure.Area() != octagon.Area())
    {
        parent = curr;
        if (curr->figure.Area() > octagon.Area())
            curr = curr->t_left;
        else 
            curr = curr->t_right;
    }

    if (!curr)
        return;
    if (curr && curr->count_fig > 1)
    {
        curr->count_fig --;
        return;
    }
    if (curr->t_left == nullptr)
    {
        if (parent && parent->t_left == curr)
            parent->t_left = curr->t_right;
        if (parent && parent->t_right == curr)
            parent->t_right = curr->t_right;
        delete curr;
        return;
    }
    if (curr->t_right == NULL)
    {
        if (parent && parent->t_left == curr)
            parent->t_left = curr->t_left;
        if (parent && parent->t_right == curr)
            parent->t_right = curr->t_left;
        delete curr;
        return;
    }

    TreeElem * replace = curr->t_left;
    while (replace->t_right)
        replace = replace->t_right;
    curr->figure = replace->figure;
    curr->count_fig = replace->count_fig;
    Pop((Octagon) replace->figure);

}

void TBinaryTree::Clear() {
    DeleteTree(t_root->t_left);
    DeleteTree(t_root->t_right);
    t_root->count_fig = 0;
    t_root->figure = Octagon();

}

double recursive_counting(const double min_area, const double max_area, TreeElem *curr) {
    if(curr && curr->figure.Area() >= min_area && curr->figure.Area() <= max_area)
    {
        int count = 0;
        if (curr && curr->t_left->figure.Area() >= min_area) 
            count += recursive_counting(min_area, max_area, curr->t_left);
        if (curr && curr->t_right->figure.Area() <= max_area) 
            count += recursive_counting(min_area, max_area, curr->t_right);
        count += curr->count_fig;
        return count;
    }
    return 0;
}

double TBinaryTree::Count(double min_area, double max_area) {
    int count = 0;
    TreeElem *curr = t_root;
    while (curr && curr->figure.Area() >= min_area && curr->figure.Area() <= max_area)
    {
        if (curr && curr->figure.Area() < min_area) 
        {
            curr = curr->t_right;
        }
        else if (curr && curr->figure.Area() > min_area)
        {
            curr = curr->t_left;
        }
    }
    count = recursive_counting(min_area, max_area, curr);  
    return count;
}

void Tree_out (std::ostream& os, TreeElem *curr) {
    if (curr)
    {
        os << curr->count_fig << "*" << curr->figure.Area();
        if(curr->t_left || curr->t_right) 
        {
            os << ": [";
            if (curr->t_left)
                Tree_out(os, curr->t_left);
            if(curr->t_left && curr->t_right)
                os << ", ";
            if (curr->t_right)
                Tree_out(os, curr->t_left);
            os << "]";
        }
        
    }
}

std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree) {
    TreeElem *curr = tree.t_root;
    Tree_out(os, curr);
}


TBinaryTree::~TBinaryTree() {
    DeleteTree(t_root);
    std::cout<< "Tree deleted" << std::endl;
}

void TBinaryTree::DeleteTree(TreeElem *curr) {
    if (curr) {
        DeleteTree(curr -> t_left);
        DeleteTree(curr -> t_right);
        delete curr;
    }
}
