#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include<stdexcept>


template<typename T>
class List
{
public:
    List();
    ~List();
    
    List<T>& operator=(const List<T>& other);
    void clearall();
    void push_back(T data);
    int GetSize()
    {
        return size;
    }
    T& operator[](const int index);
private:

    class Node
    {
        public:
        Node* pnext;
        T data;
        Node(T data = T(), Node* pnext = nullptr) : data(data), pnext(pnext) {}

    };
    int size;
    Node*head;

};

template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clearall();
}

template <typename T>
void List<T>::clearall()
{
    while(head != nullptr) 
    {
        Node * tmp = head;
        head = head->pnext;
        delete tmp;
    }
    size = 0;
}

template <typename T>
void List<T>::push_back(T data)
{
    if(head == nullptr) 
    {
        head = new Node(data);
    }
    else
    {
        Node *current = head;
        while (current->pnext != nullptr)
        {
            current = current->pnext;
        }
        current->pnext = new Node(data);
        
    }
    size++;
}

template <typename T>
T &List<T>::operator[](const int index)
{
    int count = 0;
    Node*current = this->head;
    if(index < 0 || index >= size) 
    {
        throw std::out_of_range("Index out of range");
    }
     while (current!=nullptr) 
        {
            if(count == index) 
            {
                return current->data;
            }
            current = current->pnext;
            count++;    
        }
    throw std::out_of_range("Index out of range");
        
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this == &other) return *this;  
    

    clearall();
    
    Node* current = other.head;
    while (current != nullptr)
    {
        push_back(current->data);
        current = current->pnext;
    }
    
    return *this;
}

#endif