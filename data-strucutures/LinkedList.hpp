#pragma once

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

struct Node
{
    int value;
    Node *next;
};

class LinkedList
{
public:
    LinkedList() : size(0) {};

    void insert(int value) // O(n) -> O(1)
    {
        Node *newNode = new Node{value};

        if (head == nullptr)
        {
            this->head = newNode;
            this->size++;
            return;
        }

        Node *current = this->head;
        while (current != nullptr)
        {
            if (current->next == nullptr)
            {
                current->next = newNode;
                this->size++;
                return;
            }

            current = current->next;
        }
    }

    void removeLast() // O(n) -> O(1)
    {
        int lastElementIndex = size - 1; // O(1)
        remove(lastElementIndex); // O(n)
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

    int tailElement() // O(n) -> O(1)
    {
        Node *current = head;

        if (current == nullptr)
        {
            return NULL;
        }

        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->value;
    }

    int getSize()
    {
        return size;
    }

private:
    Node *head = nullptr;
    int size;
};
#endif