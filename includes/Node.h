//
// Created by Dave R. Smith on 9/19/24.
//

#ifndef CS8_FALL24_LINKED_LIST_NODE_H
#define CS8_FALL24_LINKED_LIST_NODE_H
template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr, *prev = nullptr;
};
#endif //CS8_FALL24_LINKED_LIST_NODE_H
