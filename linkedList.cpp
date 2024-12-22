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

    void insert(int value)
    {
        Node *newNode = new Node{value};

        if (head == nullptr)
        {
            this->head = newNode;
            this->size++;
            return;
        }

        Node *current = this->head;
        while (current)
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

    void remove(int idx)
    {
        if (idx > this->size - 1 || idx < 0)
            return;

        Node *current = this->head;
        if (idx == 0)
        {
            this->head = current->next;
            delete current;
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

    int GetN(int n)
    {
        if (n < 0 || n >= size)
        {
            return NULL;
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

        return NULL;
    }

private:
    Node *head = nullptr;
    int size;
};

int main()
{
    LinkedList linkedList;

    linkedList.insert(10);
    linkedList.insert(20);
    linkedList.insert(30);

    linkedList.remove(1);
    linkedList.printList();

    return 0;
}
