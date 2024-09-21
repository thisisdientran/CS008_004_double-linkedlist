//
// Created by Dave R. Smith on 9/19/24.
//
#ifndef CS8_FALL24_LINKED_LIST_LINKEDLIST_CPP
#define CS8_FALL24_LINKED_LIST_LINKEDLIST_CPP
#include "LinkedList.h"
template<typename T>
LinkedList<T>::LinkedList()
{

}

template<typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &list)
{

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{

}
template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{

}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{

}

template<typename T>
void LinkedList<T>::one_node_pop()
{

}

template<typename T>
void LinkedList<T>::remove(Node<T> *target)
{

}

template<typename T>
void LinkedList<T>::insert_before(Node<T> *target, Node<T> *data)
{

}

template<typename T>
Node<T> *LinkedList<T>::search(const T &target)
{
    return nullptr;
}



template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    return ;
}

template<typename T>
int LinkedList<T>::size() const
{
    return 0;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    push_front(createNode(data));
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{

}

template<typename T>
void LinkedList<T>::pop_front()
{

}

template<typename T>
void LinkedList<T>::pop_back()
{

}

template<typename T>
T &LinkedList<T>::front()
{
    return ;
}

template<typename T>
T &LinkedList<T>::back()
{
    return ;
}

template<typename T>
const T &LinkedList<T>::front() const
{
    return ;
}

template<typename T>
const T &LinkedList<T>::back() const
{
    return ;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return false;
}

template<typename T>
bool LinkedList<T>::contains(const T &data)
{
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T &data)
{

}

template<typename T>
void LinkedList<T>::insert_before(const T &targetData, const T &newData)
{

}

template<typename T>
void LinkedList<T>::insert_after(const T &targetData, const T &newData)
{

}

template<typename U>
LinkedList<U> operator+(const LinkedList<U> &list1, const LinkedList<U> &list2)
{
    return LinkedList<U>();
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data)
{
    return nullptr;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list)
{
    Node<T>* walker = list.head;
    
    while(walker)
    {
        out << walker->data << " ";
        walker = walker->next;
    }
    return out;
}

#endif