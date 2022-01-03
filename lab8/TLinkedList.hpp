#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

#include "tlinkedlist_item.hpp"

template <class T>
class TLinkedList
{
public:
    TLinkedList() = default;
    TLinkedList(const TLinkedList<T> &other);

    T First() const;
    T Last() const;
    T GetItem(size_t position) const;

    void InsertFirst(const T item);
    void InsertLast(const T item);
    void Insert(const T item, size_t position);

    void RemoveFirst();
    void RemoveLast();
    void Remove(size_t position);

    bool Empty() const;
    size_t Length() const;

    TLinkedList<T>& operator=(const TLinkedList<T> &other);
    bool operator==(const TLinkedList<T> &other) const;
    bool operator!=(const TLinkedList<T> &other) const;
        
    // prints "S1 -> S2 -> ... -> Sn", S - area of square
    template <class A>
    friend std::ostream &operator<<(std::ostream &os, const TLinkedList<A> &l);

    void Clear();
    virtual ~TLinkedList();

private:
    std::shared_ptr<TLinkedListItem<T>> first = nullptr;
    std::shared_ptr<TLinkedListItem<T>> last = nullptr;
};

#endif // TLINKEDLIST_H

template <class T>
TLinkedList<T>::TLinkedList(const TLinkedList &o) : first(o.first), last(o.last) {}

template <class T>
T TLinkedList<T>::First() const
{
    if (first == nullptr) {
        std::cout << "List is empty" << std::endl;
        T out(new T);
        return out;
    }
    return first->GetObject();
}

template <class T>
T TLinkedList<T>::Last() const
{
    if (last == nullptr) {
        std::cout << "List is empty" << std::endl;
        T out(new T);
        return out;
    }
    return last->GetObject();
}

template <class T>
T TLinkedList<T>::GetItem(size_t pos) const
{
    --pos;
    size_t n = this->Length();
    if (first == nullptr) {
        std::cout << "Err: List is empty" << std::endl;
        return nullptr;
    }
    if (pos > n - 1) {
        if (n == 1) {
            std::cout << "Err: pos = " << pos + 1 << "\n";
            std::cout << "Hint: Available pos is 1" << std::endl;
            return nullptr;
        }
        std::cout << "Err: pos = " << pos + 1 << "\n";
        std::cout << "Hint: Available pos is between 1 and " << n << std::endl;
        return nullptr;
    }
    if (pos == 0) {
        return first->GetObject();
    }
    if (pos == n - 1) {
        return last->GetObject();
    }
    std::shared_ptr<TLinkedListItem<T>> to_return = first;
    for (size_t i = 0; i < pos; ++i) {
        to_return = to_return->GetNext();
    }
    return to_return->GetObject();
}

template <class T>
void TLinkedList<T>::InsertFirst(T item)
{
    std::shared_ptr<TLinkedListItem<T>> new_item(new TLinkedListItem<T>(item));
    if (first == nullptr) {
        first = (last = new_item);
        return;
    }
    new_item->SetPrev(nullptr);
    new_item->SetNext(first);
    first->SetPrev(new_item);
    first = new_item;
}

template <class T>
void TLinkedList<T>::InsertLast(T item)
{
    std::shared_ptr<TLinkedListItem<T>> new_item(new TLinkedListItem<T>(item));
    if (first == nullptr) {
        first = (last = new_item);
        return;
    }
    new_item->SetPrev(last);
    new_item->SetNext(nullptr);
    last->SetNext(new_item);
    last = new_item;
}

template <class T>
void TLinkedList<T>::Insert(T item, size_t pos)
{
    --pos;
    size_t n = this->Length();
    if (pos > n) {
        if (n == 0) {
            std::cout << "Err: pos = " << pos + 1 << "\n";
            std::cout << "Hint: Available pos is 1" << std::endl;
            return;
        }
        std::cout << "Err: pos = " << pos + 1 << "\n";
        std::cout << "Hint: Available pos is between 1 and " << n + 1 << std::endl;
        return;
    }
    if (pos == 0) {
        InsertFirst(item);
        return;
    }
    if (pos == n) {
        InsertLast(item);
        return;
    }
    std::shared_ptr<TLinkedListItem<T>> new_item(new TLinkedListItem<T>(item));
    std::shared_ptr<TLinkedListItem<T>> cur = first;
    for (size_t i = 0; i < pos; ++i) {
        cur = cur->GetNext();
    }
    std::shared_ptr<TLinkedListItem<T>> cur_prev = cur->GetPrev();
    cur_prev->SetNext(new_item);
    cur->SetPrev(new_item);
    new_item->SetPrev(cur_prev);
    new_item->SetNext(cur);
}

template <class T>
void TLinkedList<T>::RemoveFirst()
{
    if (first == nullptr) {
        std::cout << "Err: List is empty" << std::endl;
        return;
    }
    if (last == first) {
        first = (last = nullptr);
        return;
    }
    std::shared_ptr<TLinkedListItem<T>> to_del = first;
    first = first->GetNext();
    first->SetPrev(nullptr);
}

template <class T>
void TLinkedList<T>::RemoveLast()
{
    if (last == nullptr) {
        std::cout << "Err: List is empty" << std::endl;
        return;
    }
    if (last == first) {
        first = (last = nullptr);
        return;
    }
    std::shared_ptr<TLinkedListItem<T>> to_del = last;
    last = last->GetPrev();
    last->SetNext(nullptr);
}

template <class T>
void TLinkedList<T>::Remove(size_t pos)
{
    --pos;
    size_t n = this->Length();
    if (first == nullptr) {
        std::cout << "Err: List is empty" << std::endl;
        return;
    }
    if (pos > n - 1) {
        if (n == 1) {
            std::cout << "Err: pos = " << pos + 1 << "\n";
            std::cout << "Hint: Available pos is 1" << std::endl;
            return;
        }
        std::cout << "Err: pos = " << pos + 1 << "\n";
        std::cout << "Hint: Available pos is between 1 and " << n << std::endl;
        return;
    }
    if (pos == 0) {
        RemoveFirst();
        return;
    }
    if (pos == n - 1) {
        RemoveLast();
        return;
    }
    std::shared_ptr<TLinkedListItem<T>> to_del = first;
    for (size_t i = 0; i < pos; ++i) {
        to_del = to_del->GetNext();
    }
    std::shared_ptr<TLinkedListItem<T>> cur_prev = to_del->GetPrev();
    std::shared_ptr<TLinkedListItem<T>> cur_next = to_del->GetNext();
    cur_prev->SetNext(cur_next);
    cur_next->SetPrev(cur_prev);
}

template <class T>
bool TLinkedList<T>::Empty() const
{
    return (first == nullptr);
}

template <class T>
size_t TLinkedList<T>::Length() const
{
    size_t res = 0;
    for (std::shared_ptr<TLinkedListItem<T>> i = first; i != nullptr; i = i->GetNext()) {
        ++res;
    }
    return res;
}

template <class T>
TLinkedList<T>& TLinkedList<T>::operator=(const TLinkedList<T> &o)
{
    Clear();
    for (std::shared_ptr<TLinkedListItem<T>> i = o.first; i != nullptr; i = i->GetNext()) {
        InsertLast(i->GetObject());
    }
    return *this;
}

template <class T>
bool TLinkedList<T>::operator==(const TLinkedList<T> &o) const
{
    if (Length() != o.Length()) {
        return false;
    }
    std::shared_ptr<TLinkedListItem<T>> i = first;
    std::shared_ptr<TLinkedListItem<T>> j = o.first;
    while (i != nullptr && j != nullptr) {
        if (i->GetObject() != j->GetObject()) {
            return false;
        }
        i = i->GetNext();
        j = j->GetNext();
    }
    return true;
}

template <class T>
bool TLinkedList<T>::operator!=(const TLinkedList<T> &o) const
{
    if (Length() != o.Length()) {
        return true;
    }
    std::shared_ptr<TLinkedListItem<T>> i = first;
    std::shared_ptr<TLinkedListItem<T>> j = o.first;
    while (i != nullptr && j != nullptr) {
        if (i->GetObject() != j->GetObject()) {
            return true;
        }
        i = i->GetNext();
        j = j->GetNext();
    }
    return false;
}

// prints "S1 -> S2 -> ... -> Sn", S - area of square
template <class T>
std::ostream &operator<<(std::ostream &os, const TLinkedList<T> &l)
{
    if (l.first == nullptr) {
        os << "List is empty" << std::endl;
        return os;
    }
    for (std::shared_ptr<TLinkedListItem<T>> i = l.first; i != nullptr; i = i->GetNext()) {
        if (i->GetNext() != nullptr) {
            os << i->GetObject()->Area() << " -> ";
        } else {
            os << i->GetObject()->Area();
        }
    }
    return os;
}

template <class T>
void TLinkedList<T>::Clear()
{
    while (first != nullptr) {
        RemoveFirst();
    }
}

template <class T>
TLinkedList<T>::~TLinkedList()
{
    while (first != nullptr) {
        RemoveFirst();
    }
}
