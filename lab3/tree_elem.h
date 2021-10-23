#ifndef TREEELEM_H
#define TREEELEM_H

#include <memory>
#include "octagon.h"

#define sptr(T) std::shared_ptr<T>

class TreeElem{
public:
    TreeElem();
    TreeElem(const Octagon octagon);

    Octagon get_octagon();
    int get_count_fig();
    sptr(TreeElem) get_left();
    sptr(TreeElem) get_right();
    
    void set_octagon(Octagon octi);
    void set_count_fig(const int count);
    void set_left(sptr(TreeElem) to_left);
    void set_right(sptr(TreeElem) to_right);

    virtual ~TreeElem();
private:
    sptr(Octagon) octi;
    int count_fig;
    sptr(TreeElem) t_left;
    sptr(TreeElem) t_right;
};

#endif