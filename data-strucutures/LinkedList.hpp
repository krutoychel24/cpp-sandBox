#pragma once

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

struct Node
{
    int value;
    Node *next;
    Node* prev;
};

class LinkedList
{
public:
    LinkedList() :size(0) {};

void insert(int value) // O(1)
{
    Node *newNode = new Node{value, nullptr, tail};

    if (tail == nullptr)    
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode; 
        tail = newNode;       
    }

    size++;
}


void removeLast() //O(1)
{
    if (tail == nullptr)
    {
        return;
    } 

    if (head == tail) 
    { 
        delete tail;
        head = nullptr;
        tail = nullptr;
    } 
    else 
    {
        tail = tail->prev; 
        delete tail->next; 
        tail->next = nullptr; 
    }

    size--;
}

    void removeFirst() // O(1)
    {
        if (head == nullptr)
        {
            return;
        }

        Node* current = head;
        head = head -> next;
        delete current;
        size--;
    }

    void remove(int idx) // O(n)
    {
        if (idx > this->size - 1 || idx < 0)
            return;

        Node *current = this->head;
        if (idx == 0)
        {
            this->head = current->next;
            delete current;
            size--;
            return;
        }

        Node *prev = nullptr;
        int i = 0;

        while (current)
        {
            if (i == idx)
            {
                prev->next = current->next;
                delete current;
                size--;
                return;
            }

            i++;
            prev = current;
            current = current->next;
        }
    }

    void printList()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            std::cout << current->value;
            current = current->next;
            if (current != nullptr)
            {
                std::cout << " > ";
            }
        }
    }   

    int get(int n)
    {
        if (n < 0 || n >= size)
        {
            return 0;
        }

        Node *current = head;
        int i = 0;

        while (current != nullptr)
        {
            if (i == n)
            {
                return current->value;
            }
            current = current->next;
            i++;
        }

        return 0;
    }

    int headElement()
    {
        if (head != nullptr)
        {
            return head->value;
        }
        else
        {
            return NULL;
        }
    }

    int tailElement() // O(1)
    {
        if (tail != nullptr)
        {
            return tail->value;
        }
        else
        {
            return 0;
        }
    }

    int getSize()
    {
        return size;
    }

private:
    Node *head = nullptr;
    Node *tail;
    int size;
};
#endif