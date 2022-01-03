#ifndef TLINKEDLIST_ITEM_H
#define TLINKEDLIST_ITEM_H

#include <iostream>
#include <memory>

template <class T>
class TLinkedListItem
{
public:
    TLinkedListItem(const std::shared_ptr<T> item);
    TLinkedListItem(const TLinkedListItem<T> &other);

    std::shared_ptr<TLinkedListItem<T>> GetPrev() const;
    std::shared_ptr<TLinkedListItem<T>> GetNext() const;
    std::shared_ptr<T> GetObject() const;

    void SetPrev(std::shared_ptr<TLinkedListItem<T>> to_set);
    void SetNext(std::shared_ptr<TLinkedListItem<T>> to_set);

    bool operator==(const TLinkedListItem<T> &other) const;
    bool operator!=(const TLinkedListItem<T> &other) const;

    template <class A>
    friend std::ostream& operator<<(std::ostream &os, const TLinkedListItem<A> &i);

    ~TLinkedListItem();

private:
    std::shared_ptr<T> item;
    std::shared_ptr<TLinkedListItem<T>> prev;
    std::shared_ptr<TLinkedListItem<T>> next;
};

#endif // TLINKEDLIST_ITEM_H

template <class T>
TLinkedListItem<T>::TLinkedListItem(const std::shared_ptr<T> item) :
    item(item), prev(nullptr), next(nullptr) {}

template <class T>
TLinkedListItem<T>::TLinkedListItem(const TLinkedListItem<T> &o) :
    item(o.item), prev(o.prev), next(o.next) {}

template <class T>
std::shared_ptr<TLinkedListItem<T>> TLinkedListItem<T>::GetPrev() const
{
    return prev;
}

template <class T>
std::shared_ptr<TLinkedListItem<T>> TLinkedListItem<T>::GetNext() const
{
    return next;
}

template <class T>
std::shared_ptr<T> TLinkedListItem<T>::GetObject() const
{
    return item;
}

template <class T>
void TLinkedListItem<T>::SetPrev(std::shared_ptr<TLinkedListItem<T>> to_set)
{
    prev = to_set;
}

template <class T>
void TLinkedListItem<T>::SetNext(std::shared_ptr<TLinkedListItem<T>> to_set)
{
    next = to_set;
}

template <class T>
bool TLinkedListItem<T>::operator==(const TLinkedListItem<T> &o) const
{
    return ((item == o.item) && (prev == o.prev) && (next == o.next));
}

template <class T>
bool TLinkedListItem<T>::operator!=(const TLinkedListItem<T> &o) const
{
    return ((item != o.item) || (prev != o.prev) || (next != o.next));
}

template <class T>
std::ostream &operator<<(std::ostream &os, const TLinkedListItem<T> &i)
{
    os << "Item: " << *i.item << std::endl;
    return os;
}

template <class T>
TLinkedListItem<T>::~TLinkedListItem() {}
