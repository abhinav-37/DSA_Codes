#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
} *first;

void Create(int a[], int n) {
    int i;
    struct Node* t, * last;
    first = new struct Node;
    first->data = a[0];
    first->next = NULL;
    last = first;
    
    for (i = 1; i < n; i++) {
        t = new struct Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node* p) {
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}

void displayRecursive(struct Node* p) {
    if (p) {
        cout << p->data;
        displayRecursive(p->next);
    }
}

int Add(struct Node* p) {
    int sum = 0;
    while (p) {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int AddRecursive(struct Node* p) {
    if (p != NULL) {
        return AddRecursive(p->next) + p->data;
    }
    else {
        return 0;
    }
}

int Count(struct Node* p) {
    if (p != NULL) {
        return Count(p->next) + 1;
    }
    else {
        return 0;
    }
}

int MaxValue(struct Node* p) {
    int max = p -> data;
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

struct Node* LSearch(struct Node* p, int value) {
    struct Node* q = NULL;
    while (p) {
        if (p->data == value) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        };
        q = p;
        p = p->next;

    }
    return NULL;
    
}

struct Node* RSearch(struct Node* p, int value) {
    if (p) {
        if (value == p->data) {
            return p;
        }
        else {
            RSearch(p->next, value);

        }

    }
    else {
        return NULL;
    }
}

void Insert(struct Node* p, int data, int position) {
    struct Node* n = new Node;
    n->data = data;
    if (position > Count(first) || position < 0)
        return;
    if (position == 0) {
        n->next = first;
        n->data = data;
        first = n;
    }
    else {
        for (int i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
        
    }

}

void InsertLast(int value) {
    struct Node* last = new Node;
}

void InsertSorted(struct Node* p, int data) {
    struct Node* q = new Node;
    struct Node* nn = NULL;
    nn = new Node;
    nn->data = data;
    nn->next = NULL;
    while (p && p->data < data) {
        q = p;
        p = p->next;
    }
    nn->next = q->next;
    q->next = nn;
}

int DeleteNode(int position) {
    struct Node* p = first;
    struct Node* q = NULL;
    if (position == 0) {
        first = first->next;
        return position;
    }
    for (int i = 0; i < position-2; i++) {
        p = p->next;
    }

    q = p->next;
    p->next = q->next;
    delete q;
    return position;
}

bool CheckSorted(struct Node * p) {
    struct Node *q = p -> next;
    while (q) {
        if (p->data <= q->data) {
            q = q->next;
            p = p->next;
        }
        else {
            return false;
        }
    }

    return true;
}

void DeleteRepeted (){
    struct Node* p = first;
    struct Node* q = first->next;
    
    while (q) {
        if (p->data == q->data) {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else {
            q = q->next;
            p = p->next;
        }
    }

}

void ReversingLinkList(struct Node *p){
    struct Node* r = NULL;
    struct Node* q = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void RReversingLinkList(struct Node* q, struct Node* p) {
    if (p) {
        RReversingLinkList(p, p->next);
        p->next = q;
    }
    else {
        first = q;
        return;
    }
}

int checkLoop(struct Node* f) {
    struct Node* q;
    struct Node* p;

    q = p = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : NULL;

    } while (p && q && p!=q);

    if (p == q)
        return 1;
   else 
       return 0;
}

void DisplayCircular(struct Node* p) {
    static int flag = 0;
    if (p->next == first || flag == 0) {
        flag = 1;
        cout << p->data << " ";
        DisplayCircular(p->next);
    }
    
    else {
        return;
    }

    flag = 0;
}


int main()
{
    int A[] = { 3,4,5,15, 15 };
    Create(A, 5);

    Display(first);

}
