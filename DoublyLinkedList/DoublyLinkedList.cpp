#include <iostream>

using namespace std;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
} * first = NULL;

void Create(int elements[], int size) {
    first = new struct Node;
    first->data = elements[0];
    first->prev = NULL;
    first->next = NULL;
    struct Node* last = first;
    struct Node* p = NULL;
    for (int i = 1; i < size; i++) {
        p = new struct Node;
        p->data = elements[i];
        p->next = NULL;
        p->prev = last;
        last->next = p;
        last = p;
    }

}

void Display(struct Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(struct Node* p) {
    if (p) {
        cout << p->data << " ";
        RDisplay(p->next);
    }
    else {
        return;
    }
}

int Length(struct Node* p) {
    int count = 0;
    while (p) {
        count += 1;
        p = p->next;
    }
    return count;
}

void Insert(struct Node* p, int position, int data){
    struct Node* newNode = new struct Node;
    newNode->data = data;
    if (position == 0) {
        newNode->prev = NULL;
        newNode->next = first;
        first = newNode;
    }
    else {
        for (int i = 0; i < position - 1; i++) {
            p = p->next;
        }

        newNode->next = p->next;
        newNode->prev = p;
        p->next = newNode;
    };
}

void Delete(struct Node* p, int position) {
    if (position == 0) {
        first = first->next;
        delete first->prev;
    }
    else {
        for (int i = 1; i < position; i++) {
            p = p->next;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

void RReverse(struct Node* p, struct Node *q) {
    if (p) {
        cout << p << "  ";
        RReverse(p = p->next, p);
        p->next = p->prev;
        p->prev = p->next;
    }
    else {
        first = q;
    }
}

int main()
{
    int elements[5] = { 3,5,4,6,8 };
    int size = 5;
    Create(elements, size);
    //Insert(first, 3, 68);
    //Delete(first, 2);
    RReverse(first, NULL);
    RDisplay(first);
}
