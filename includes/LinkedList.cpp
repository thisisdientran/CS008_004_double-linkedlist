//
// Created by Dave R. Smith on 9/19/24.
//
#ifndef CS8_FALL24_LINKED_LIST_LINKEDLIST_CPP
#define CS8_FALL24_LINKED_LIST_LINKEDLIST_CPP
#include "LinkedList.h"

////////////////////////////////////////////////////////////////////////
// ======== CONSTRUCTORS =================================================
////////////////////////////////////////////////////////////////////////

template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &list)
{
    std::cout << "constructed with a " << list.size() << "-element list\n";
}

////////////////////////////////////////////////////////////////////////
// ======== BIG 3 =================================================
////////////////////////////////////////////////////////////////////////

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    for(Node<T>* w = list.front(); w != NULL; w=w->next)
        push_back(createNode(w->data));
}

// Overload
template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    for(Node<T>* w = list.front(); w != NULL; w=w->next)
        push_back(createNode(w->data));
    return *this;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
    clean_list();
}

////////////////////////////////////////////////////////////////////////
// ======== PRIVATE & PUBLIC ===========================================
////////////////////////////////////////////////////////////////////////
template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{
    if(head == NULL)
        tail = node; //Tail point to new node
    else
        node -> next = head; //Node next point to head
        head -> prev = node; //Current prev head node point to new node
    head = node; //Head point to new node
}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{
    if(head == NULL)
        head = node; //head point to new node
    else
        node -> prev = tail;
        tail -> next = node;
    tail = node; //tail point to new node
}

template<typename T>
void LinkedList<T>::one_node_pop()
{
    Node<T>* target = tail;
    tail = tail -> prev;
    remove(target);
}

template<typename T>
void LinkedList<T>::remove(Node<T> *target)
{
    if(!empty())
        //Ensure not losing head and tail ptr
        if(head == target)
            head = target -> next;
        if(tail == target)
            tail = target -> prev;
        //Secure the ptr of prev and next nodes
        target->prev->next = target->next;
        target->next->prev = target->prev;
        //Safely remove
        delete target;
}

template<typename T>
void LinkedList<T>::insert_before(Node<T> *target, Node<T> *data)
{
    // Ensure headptr not losing
    if(target == head)
        push_front(data);
    else
        data->next = target;
        data->prev = target->prev;
        target->prev->next = data;
        target->prev = data;
}

template<typename T>
void LinkedList<T>::insert_after(Node<T>* target, Node<T>* data){
    // Ensure tailptr not losing
    if(target == tail)
        push_back(data);
    else
        data->prev = target;
        data->next = target->next;
        target->next->prev = data;
        target->next = data;
}


template<typename T>
Node<T> *LinkedList<T>::search(const T &target)
{
    for(Node<T>* w = head; w != NULL;w->next)
        if(w->data == target)
            return w;
    return NULL;
}

template<typename T>
int LinkedList<T>::size() const
{
    int size = 0;
    for(Node<T>*w = head;w!=NULL;w=w->next)
        size++;
    return size;
}

template<typename T>
Node<T>* LinkedList<T>::next() const{
    return next;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    push_front(createNode(data));
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{
    push_back(createNode(data));
}

template<typename T>
void LinkedList<T>::pop_front()
{
    Node<T>* target = head;
    head = head -> next;
    remove(target);
}

template<typename T>
void LinkedList<T>::pop_back()
{
    one_node_pop();
}

template<typename T>
T &LinkedList<T>::front()
{
    return head -> data();
}

template<typename T>
T &LinkedList<T>::back()
{
    return tail -> data();
}

template<typename T>
const T &LinkedList<T>::front() const
{
    front();
}

template<typename T>
const T &LinkedList<T>::back() const
{
    back();
}

template<typename T>
bool LinkedList<T>::empty() const
{
    if(head == NULL)
        return true;
    return false;
}

template<typename T>
bool LinkedList<T>::contains(const T &data)
{
    if(search(data) != NULL)
        return true;
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T &data)
{
    remove(search(data));
}

template<typename T>
void LinkedList<T>::clean_list(){
    while(!empty())
        one_node_pop();
}

template<typename T>
void LinkedList<T>::insert_before(const T &targetData, const T &newData)
{
    insert_before(search(targetData),createNode(newData));
}

template<typename T>
void LinkedList<T>::insert_after(const T &targetData, const T &newData)
{
    insert_after(search(targetData), createNode(newData));
}

template<typename U>
LinkedList<U> operator+(const LinkedList<U> &list1, const LinkedList<U> &list2)
{
    LinkedList<U> finalList(list1);
    for(Node<U>*w=list2.head();w!=NULL;w=w->next)
        finalList.push_back(w);
    return finalList;
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data)
{
    Node<T> * n = new Node<T>;
    n->data = data;
    return n;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list)
{
    Node<T>* walker = list.head;
    out << "[|||] -> ";
    while(walker)
    {
        out << "[" << walker->data << "]";
        walker = walker->next;
    }
    out << "-> [|||]";
    return out;
}

#endif