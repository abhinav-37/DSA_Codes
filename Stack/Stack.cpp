#include <iostream>
#include <string>
using namespace std;

struct stack {
    int size;
    int top;
    int* s;
};

int Push(struct stack* st, int data) {
    int x = -1;
    if (st->top == st->size - 1) {
        return x;
    }
    else {
        st->top++;
        st->s[st->top] = data;
        return 1;
    }
}

int Pop(struct stack* st) {
    int x = -1;
    if (st->top == -1) {
        return x;
    }
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct stack st, int pos) {
    int x = -1;
    if (st.top - pos + 1 == -1) {
        return x;
    }
    else {
        x = st.s[st.top - pos + 1];
        return x;
    }
}

int StackTop(struct stack st) {
    int x = -1;
    if (st.top == -1) {
        return x;
    }
    else {
        x = st.s[st.top];
        return x;
    }
}

int main()
{
    struct stack* p = new struct stack;
    p->top = -1;


    //paranthesis matching
    string para = "(((5+7) +)))";

    int length = para.length();
    p->size = length;
    p->s = new int[length];


    int good = 1;

    for (int i = 0; i < length; i++) {
        char character = para.at(i);
        if (character == '(') {
            Push(p, 1);
        }
        else if (character == ')') {
            good = Pop(p);
            
        }
    }

    if (StackTop(*p) != -1) {
        good = -1;
    }




    if (good == 1) {
        cout << "Matching paran ";
    }
    else {
        cout << "Unmatching paran";
    }
}
