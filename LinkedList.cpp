#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

// Append method
template <typename T>
LinkedListNode<T> *LinkedList<T>::append(const T &value)
{
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);
    if (!_head)
    {
        _head = _tail = newNode;
    }
    else
    {
        _tail->next = newNode;
        _tail = newNode;
    }
    _size++;
    return newNode;
}

// Insert at Head method
template <typename T>
void LinkedList<T>::insertAtHead(const T &value)
{
    LinkedListNode<T> *newNode = new LinkedListNode<T>(value);
    newNode->next = _head;
    _head = newNode;
    if (!_tail)
    {
        _tail = newNode;
    }
    _size++;
}

// Remove from Head method
template <typename T>
LinkedListNode<T> *LinkedList<T>::removeFromHead()
{
    if (!_head)
        return nullptr;

    LinkedListNode<T> *removedNode = _head;
    _head = _head->next;
    if (!_head)
    {
        _tail = nullptr;
    }
    _size--;
    return removedNode;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::removeFromTail()
{
    if (!_tail)
        return nullptr;

    LinkedListNode<T> *removedNode = _tail;
    if (_head == _tail)
    {
        _head = _tail = nullptr;
    }
    else
    {
        LinkedListNode<T> *current = _head;
        while (current->next != _tail)
        {
            current = current->next;
        }
        current->next = nullptr;
        _tail = current;
    }
    _size--;
    return removedNode;
}

template <typename T>
bool LinkedList<T>::removeValue(const T &value)
{
    if (!_head)
        return false;

    if (_head->value == value)
    {
        removeFromHead();
        return true;
    }

    LinkedListNode<T> *current = _head;
    while (current->next)
    {
        if (current->next->value == value)
        {
            LinkedListNode<T> *toDelete = current->next;
            current->next = current->next->next;
            if (toDelete == _tail)
            {
                _tail = current;
            }
            delete toDelete;
            _size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Clear method
template <typename T>
void LinkedList<T>::clear()
{
    while (_head)
    {
        LinkedListNode<T> *temp = _head;
        _head = _head->next;
        delete temp;
    }
    _tail = nullptr;
    _size = 0;
}

// Accessor methods
template <typename T>
size_t LinkedList<T>::size() const
{
    return _size;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const
{
    return _head;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const
{
    return _tail;
}

#endif