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
        if (curr->area == -1)
        {
            curr->area = octagon;
            curr->count_fig = 1;
            return;
        }
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



void Pop_List(TreeElem *curr, TreeElem *parent);
void Pop_Part_of_Branch(TreeElem *curr, TreeElem *parent);
void Pop_Root_of_Subtree(TreeElem *curr, TreeElem *parent);
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
        //надо сделать удаление корня
    curr->count_fig--;
    if (!parent && curr->count_fig <= 0)
    {
        if (curr->t_left == nullptr && curr->t_right == nullptr)
        {
            t_root->area = -1;
            return;
        }
        if (curr->t_left == nullptr || curr->t_right == nullptr)
        {
            if(curr->t_left == nullptr)
                t_root = t_root->t_right;
            else
                t_root = t_root->t_left;
            return;
        }
        if (curr->t_left != nullptr && curr->t_right != nullptr)
        {
           curr = t_root->t_left;
           while (curr->t_right)
           {
               parent = curr;
               curr = curr->t_right;
           }
            t_root->area = curr->area;
            t_root->count_fig = curr->count_fig;
            parent->t_right = curr->t_left;
            curr->t_left = nullptr;
            delete curr;
           
           return;
        }
    }
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

    while (replace->t_right)
        replace = replace->t_right;

    curr->area = replace->area;
    curr->count_fig = replace->count_fig;

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
    t_root->area = -1;
    t_root->count_fig = 0;
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
    if (t_root->area == -1)
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
    return os;
}

void Tree_out (std::ostream& os, TreeElem *curr) {
    if (curr)
    {
        if(curr->area >= 0) 
            std::cout << curr->count_fig << "*" << curr->area;
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
