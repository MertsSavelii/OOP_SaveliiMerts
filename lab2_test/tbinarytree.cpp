#include "tbinarytree.h"

TBinaryTree::TBinaryTree() {
    t_root = new TreeElem();
}

TBinaryTree::TBinaryTree(const TBinaryTree& other) {

}

void TBinaryTree::Push(int octagon) {
    TreeElem * curr = t_root;
    while (curr)
    {
        if (curr->area == octagon)
        {
            curr->count_fig++;
            return;
        }
        if (curr->area > octagon && curr->t_left == NULL)
        {
            curr->t_left = new TreeElem(octagon);
            return;
        }
        if (curr->area < octagon && curr->t_right == NULL)
        {
            curr->t_right = new TreeElem(octagon);
            return;
        }
        if (curr->area > octagon)
            curr = curr->t_left;
        else
            curr = curr->t_right;
    }
}

void Pop_List(TreeElem *curr);
void Pop_Part_of_Branch(TreeElem *curr, TreeElem *parent);
void Pop_Root_of_Subtree(TreeElem *curr);
void TBinaryTree::Pop(int octagon) {

    TreeElem *curr = t_root;
    TreeElem *parent = nullptr;

    while (curr && curr->area != octagon)
    {
        parent = curr;
        if (curr->area > octagon)
            curr = curr->t_left;
        else
            curr = curr->t_right;
    }

    if (!curr)
        return;

    curr->count_fig--;
    if(curr->count_fig <= 0)
    {
        if (curr->t_left == nullptr && curr->t_right == nullptr)
            Pop_List(curr);
        if (curr->t_left == nullptr || curr->t_right == nullptr)
            Pop_Part_of_Branch(curr, parent);
        if (curr->t_left && curr->t_right)
           Pop_Root_of_Subtree(curr);
    }
}

void Pop_List(TreeElem *curr) {
    delete curr;
}

void Pop_Part_of_Branch(TreeElem *curr, TreeElem *parent) {
    if (curr->t_right == NULL)
    {
        // Вместо curr подвешивается его левое поддерево
        if (parent && parent->t_left == curr)
            parent->t_left = curr->t_left;

        if (parent && parent->t_right == curr)
            parent->t_right = curr->t_left;

        delete curr;
        return;
    }

    if (curr->t_left == NULL)
    {
        // Вместо curr подвешивается его правое поддерево
        if (parent && parent->t_left == curr)
            parent->t_left = curr->t_right;

        if (parent && parent->t_right == curr)
            parent->t_right = curr->t_right;

        delete curr;
        return;
    }

}

void Pop_Root_of_Subtree(TreeElem *curr) {
    TreeElem *replace = curr->t_left;

    while (replace->t_right)
        replace = replace->t_right;

    curr->area = replace->area;
    curr->count_fig = replace->count_fig;

    delete replace;
    return;
}

void TBinaryTree::Clear() {
    Pop(t_root->t_left->area);
    Pop(t_root->t_right->area);
    Pop(t_root->area);
}

bool TBinaryTree::Empty() {
    if (t_root->area != -1)
        return true;
    else
        return false;
}


double recursive_counting(const double min_area, const double max_area, TreeElem *curr) ;
double TBinaryTree::Count(double min_area, double max_area) {
    int count = 0;
    TreeElem *curr = t_root;
    while (curr && (curr->area < min_area || curr->area > max_area))
    {
        if (curr && curr->area < min_area) 
            curr = curr->t_right;
        if (curr && curr->area > min_area)
            curr = curr->t_left;
    }

    if (curr)
        count = recursive_counting(min_area, max_area, curr);  
    
    return count;
}

double recursive_counting(const double min_area, const double max_area, TreeElem *curr) {
    int count = 0;

    if (curr && curr->area >= min_area && curr->area <= max_area)
    {
        count += curr->count_fig;
        if (curr->t_left && curr->t_left->area >= min_area) 
            count += recursive_counting(min_area, max_area, curr->t_left);

        if (curr->t_right && curr->t_right->area <= max_area) 
            count += recursive_counting(min_area, max_area, curr->t_right);
        
    }
    return count;
}

void Tree_out (std::ostream& os, TreeElem *curr);
std::ostream& operator<<(std::ostream& os, const TBinaryTree& tree) {
    TreeElem *curr = tree.t_root;
    Tree_out(os, curr);
}

void Tree_out (std::ostream& os, TreeElem *curr) {
    if (curr)
    {
        os << curr->count_fig << "*" << curr->area;
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

TBinaryTree::~TBinaryTree() {
    delete t_root;
    std::cout << "дерево удалено" << std::endl;
}
