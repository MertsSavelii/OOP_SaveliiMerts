#include "tbinarytree.h"

TBinaryTree::TBinaryTree() {
    t_root = nullptr;
}

void recursive_copying(TBinaryTree *curr, const TreeElem  *o_curr);
TBinaryTree::TBinaryTree(const TBinaryTree& other) {
    recursive_copying(this, other.t_root);
}

void recursive_copying(TBinaryTree *curr, const TreeElem  *o_curr) {
    if(o_curr)
        for (int i = 0; i < o_curr->count_fig; i++)
            curr->Push(o_curr->octi);
    if(o_curr->t_left)
        recursive_copying(curr, o_curr->t_left);
    if(o_curr->t_right)
        recursive_copying(curr, o_curr->t_right);
}



void TBinaryTree::Push(Octagon octagon) {
    TreeElem * curr = t_root;
    while (curr)
    {
        if (curr->octi.Area() == octagon.Area())
        {
            curr->count_fig++;
            return;
        }
        if (curr->octi.Area() > octagon.Area() && curr->t_left == NULL)
        {
            curr->t_left = new TreeElem(octagon);
            return;
        }
        if (curr->octi.Area() < octagon.Area() && curr->t_right == NULL)
        {
            curr->t_right = new TreeElem(octagon);
            return;
        }
        if (curr->octi.Area() > octagon.Area())
            curr = curr->t_left;
        else
            curr = curr->t_right;
    }
    if (curr == nullptr)
    {
        t_root = new TreeElem(octagon);
        return;
    }
}



void Pop_List(TreeElem *curr, TreeElem *parent);
void Pop_Part_of_Branch(TreeElem *curr, TreeElem *parent);
void Pop_Root_of_Subtree(TreeElem *curr, TreeElem *parent);
void TBinaryTree::Pop(Octagon octagon) {

    TreeElem *curr = t_root;
    TreeElem *parent = nullptr;

    while (curr && curr->octi.Area() != octagon.Area())
    {
        parent = curr;
        if (curr->octi.Area() > octagon.Area())
            curr = curr->t_left;
        else
            curr = curr->t_right;
    }

    if (curr == nullptr)
        return;

    curr->count_fig--;

    if(curr->count_fig <= 0)
    {
        if (curr->t_left == nullptr && curr->t_right == nullptr)
        {
            Pop_List(curr, parent);
            return;
        }
        if (curr->t_left == nullptr || curr->t_right == nullptr)
        {
            Pop_Part_of_Branch(curr, parent);
            return;
        }
        if (curr->t_left != nullptr && curr->t_right != nullptr)
        {
           Pop_Root_of_Subtree(curr, parent);
           return;
        }
    }
}

void Pop_List(TreeElem *curr, TreeElem *parent) {
    if (parent->t_left == curr)
                parent->t_left = nullptr;
            else
                parent->t_right = nullptr;
    delete curr;
}

void Pop_Part_of_Branch(TreeElem *curr, TreeElem *parent) {
    if (curr->t_right == nullptr)
    {
        // Вместо curr подвешивается его левое поддерево
        if(parent)
        {
            if (parent && parent->t_left == curr)
                parent->t_left = curr->t_left;

            if (parent && parent->t_right == curr)
                parent->t_right = curr->t_left;
        
            curr->t_right = nullptr;
            curr->t_left = nullptr;
            delete curr;
            return;
        }
    }

    if (curr->t_left == nullptr)
    {
        // Вместо curr подвешивается его правое поддерево
        if(parent)
        {
            if (parent && parent->t_left == curr)
                parent->t_left = curr->t_right;

            if (parent && parent->t_right == curr)
                parent->t_right = curr->t_right;

            curr->t_right = nullptr;
            curr->t_left = nullptr;
            delete curr;
            return;
        }
    }

}

void Pop_Root_of_Subtree(TreeElem *curr, TreeElem *parent) {
    TreeElem *replace = curr->t_left;
    TreeElem *rep_par = curr;
    while (replace->t_right)
    {
        rep_par = replace;
        replace = replace->t_right;
    }

    curr->octi = replace->octi;
    curr->count_fig = replace->count_fig;
    
    if (rep_par->t_left == replace)
        rep_par->t_left = nullptr;
    else
        rep_par->t_right = nullptr;

    delete replace;
    return;
}



void recursive_clear(TreeElem *curr);
void TBinaryTree::Clear() {
    if (t_root->t_left)
        recursive_clear(t_root->t_left);
    t_root->t_left = nullptr;
    if (t_root->t_right)
        recursive_clear(t_root->t_right);
    t_root->t_right = nullptr;
    //t_root->area = -1;
    //t_root->count_fig = 0;
    t_root = nullptr;
}

void recursive_clear(TreeElem *curr)
{
    if(curr)
    {
        if (curr->t_left)
            recursive_clear(curr->t_left);
        curr->t_left = nullptr;
        if (curr->t_right)
            recursive_clear(curr->t_right);
        curr->t_right = nullptr;
        delete curr;
    }
}

bool TBinaryTree::Empty() {
    if (t_root == nullptr)
        return true;
    else
        return false;
}



double recursive_counting(const double min_area, const double max_area, TreeElem *curr) ;
double TBinaryTree::Count(double min_area, double max_area) {
    int count = 0;
    TreeElem *curr = t_root;
    while (curr && (curr->octi.Area() < min_area || curr->octi.Area() > max_area))
    {
        if (curr && curr->octi.Area() < min_area) 
            curr = curr->t_right;
        if (curr && curr->octi.Area() > min_area)
            curr = curr->t_left;
    }

    if (curr)
        count = recursive_counting(min_area, max_area, curr);  
    
    return count;
}

double recursive_counting(const double min_area, const double max_area, TreeElem *curr) {
    int count = 0;

    if (curr && curr->octi.Area() >= min_area && curr->octi.Area() <= max_area)
    {
        count += curr->count_fig;
        if (curr->t_left && curr->t_left->octi.Area() >= min_area) 
            count += recursive_counting(min_area, max_area, curr->t_left);

        if (curr->t_right && curr->t_right->octi.Area() <= max_area) 
            count += recursive_counting(min_area, max_area, curr->t_right);
        
    }
    return count;
}



void Tree_out (std::ostream& os, TreeElem *curr);
std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree) {
    TreeElem *curr = tree.t_root;
    Tree_out(os, curr);
    return os;
}

void Tree_out (std::ostream& os, TreeElem *curr) {
    if (curr)
    {
        if(curr->octi.Area() >= 0) 
            std::cout << curr->count_fig << "*" << curr->octi.Area();
        if(curr->t_left || curr->t_right) 
        {
            os << ": [";
            if (curr->t_left)
                Tree_out(os, curr->t_left);
            if(curr->t_left && curr->t_right)
                os << ", ";
            if (curr->t_right)
                Tree_out(os, curr->t_right);
            os << "]";
        }
    }
}



TBinaryTree::~TBinaryTree() {
    delete t_root;
    std::cout << "дерево удалено" << std::endl;
}
