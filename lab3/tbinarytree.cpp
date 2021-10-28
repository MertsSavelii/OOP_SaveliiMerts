#include "tbinarytree.h"

TBinaryTree::TBinaryTree() {
    t_root = nullptr;
}

void recursive_copying(TBinaryTree *curr, const sptr(TreeElem)  o_curr);
TBinaryTree::TBinaryTree(const TBinaryTree& other) {
    recursive_copying(this, other.t_root);
}

void recursive_copying(TBinaryTree *curr, const sptr(TreeElem) o_curr) {
    if(o_curr)
        for (int i = 0; i < o_curr->get_count_fig(); i++)
            curr->Push(o_curr->get_octagon());
    if(o_curr->get_left())
        recursive_copying(curr, o_curr->get_left());
    if(o_curr->get_right())
        recursive_copying(curr, o_curr->get_right());
}


void TBinaryTree::Push(Octagon octagon) {
    sptr(TreeElem) curr = t_root;
    while (curr)
    {
        if (curr->get_octagon().Area() == octagon.Area())
        {
            curr->set_count_fig(curr->get_count_fig() + 1);
            return;
        }
        if (curr->get_octagon().Area() > octagon.Area() && curr->get_left() == nullptr)
        {
            sptr(TreeElem) ptr1(new TreeElem(octagon));
            curr->set_left(ptr1);
            return;
        }
        if (curr->get_octagon().Area() < octagon.Area() && curr->get_right() == nullptr)
        {
            sptr(TreeElem) ptr1(new TreeElem(octagon));
            curr->set_right(ptr1);
            return;
        }
        if (curr->get_octagon().Area() > octagon.Area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }
    if (curr == nullptr)
    {
        sptr(TreeElem) ptr1(new TreeElem(octagon));
        t_root = ptr1;
        return;
    }
}


void Pop_List(sptr(TreeElem) curr, sptr(TreeElem) parent);
void Pop_Part_of_Branch(sptr(TreeElem) curr, sptr(TreeElem) parent);
void Pop_Root_of_Subtree(sptr(TreeElem) curr, sptr(TreeElem) parent);
void TBinaryTree::Pop(Octagon octagon) {

    sptr(TreeElem) curr = t_root;
    sptr(TreeElem) parent = nullptr;

    while (curr && curr->get_octagon().Area() != octagon.Area())
    {
        parent = curr;
        if (curr->get_octagon().Area() > octagon.Area())
            curr = curr->get_left();
        else
            curr = curr->get_right();
    }

    if (curr == nullptr)
        return;

    curr->set_count_fig(curr->get_count_fig() + 1);

    if(curr->get_count_fig() <= 0)
    {
        if (curr->get_left() == nullptr && curr->get_right() == nullptr)
        {
            Pop_List(curr, parent);
            return;
        }
        if (curr->get_left() == nullptr || curr->get_right() == nullptr)
        {
            Pop_Part_of_Branch(curr, parent);
            return;
        }
        if (curr->get_left() != nullptr && curr->get_right() != nullptr)
        {
           Pop_Root_of_Subtree(curr, parent);
           return;
        }
    }
}

void Pop_List(sptr(TreeElem) curr, sptr(TreeElem) parent) {
    if (parent->get_left() == curr)
                parent->set_left(nullptr);
            else
                parent->set_right(nullptr);
}

void Pop_Part_of_Branch(sptr(TreeElem) curr, sptr(TreeElem) parent) {
    if (curr->get_right() == nullptr)
    {
        if(parent)
        {
            if (parent && parent->get_left() == curr)
                parent->set_left(curr->get_left());

            if (parent && parent->get_right() == curr)
                parent->set_right(curr->get_left());
        
            curr->set_right(nullptr);
            curr->set_left(nullptr);
            return;
        }
    }

    if (curr->get_left() == nullptr)
    {
        if(parent)
        {
            if (parent && parent->get_left() == curr)
                parent->set_left(curr->get_right());

            if (parent && parent->get_right() == curr)
                parent->set_right(curr->get_right());

            curr->set_right(nullptr);
            curr->set_left(nullptr);
            return;
        }
    }

}

void Pop_Root_of_Subtree(sptr(TreeElem) curr, sptr(TreeElem) parent) {
    sptr(TreeElem) replace = curr->get_left();
    sptr(TreeElem) rep_par = curr;
    while (replace->get_right())
    {
        rep_par = replace;
        replace = replace->get_right();
    }

    curr->set_octagon(replace->get_octagon());
    curr->set_count_fig(replace->get_count_fig());
    
    if (rep_par->get_left() == replace)
        rep_par->set_left(nullptr);
    else
        rep_par->set_right(nullptr);
    return;
}


void recursive_clear(sptr(TreeElem) curr);
void TBinaryTree::Clear() {
    if (t_root->get_left())
        recursive_clear(t_root->get_left());
    t_root->set_left(nullptr);
    if (t_root->get_right())
        recursive_clear(t_root->get_right());
    t_root->set_right(nullptr);
    t_root = nullptr;
}

void recursive_clear(sptr(TreeElem) curr)
{
    if(curr)
    {
        if (curr->get_left())
            recursive_clear(curr->get_left());
        curr->set_left(nullptr);
        if (curr->get_right())
            recursive_clear(curr->get_right());
        curr->set_right(nullptr);
    }
}


bool TBinaryTree::Empty() {
    if (t_root == nullptr)
        return true;
    else
        return false;
}


double recursive_counting(const double min_area, const double max_area, sptr(TreeElem) curr) ;
double TBinaryTree::Count(double min_area, double max_area) {
    int count = 0;
    sptr(TreeElem) curr = t_root;
    while (curr && (curr->get_octagon().Area() < min_area || curr->get_octagon().Area() > max_area))
    {
        if (curr && curr->get_octagon().Area() < min_area) 
            curr = curr->get_right();
        if (curr && curr->get_octagon().Area() > min_area)
            curr = curr->get_left();
    }

    if (curr)
        count = recursive_counting(min_area, max_area, curr);  
    
    return count;
}

double recursive_counting(const double min_area, const double max_area, sptr(TreeElem) curr) {
    int count = 0;

    if (curr && curr->get_octagon().Area() >= min_area && curr->get_octagon().Area() <= max_area)
    {
        count += curr->get_count_fig();
        if (curr->get_left() && curr->get_left()->get_octagon().Area() >= min_area) 
            count += recursive_counting(min_area, max_area, curr->get_left());

        if (curr->get_right() && curr->get_right()->get_octagon().Area() <= max_area) 
            count += recursive_counting(min_area, max_area, curr->get_right());
    }
    return count;
}


void Tree_out (std::ostream& os, sptr(TreeElem) curr);
std::ostream& operator<<(std::ostream& os, const sptr(TBinaryTree) tree) {
    sptr(TreeElem) curr = tree->t_root;
    Tree_out(os, curr);
    return os;
}

void Tree_out (std::ostream& os, sptr(TreeElem) curr) {
    if (curr)
    {
        if(curr->get_octagon().Area() >= 0) 
            os << curr->get_count_fig() << "*" << curr->get_octagon().Area();
        if(curr->get_left() || curr->get_right()) 
        {
            os << ": [";
            if (curr->get_left())
                Tree_out(os, curr->get_left());
            if(curr->get_left() && curr->get_right())
                os << ", ";
            if (curr->get_right())
                Tree_out(os, curr->get_right());
            os << "]";
        }
    }
}


TBinaryTree::~TBinaryTree() {
}
