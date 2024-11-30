#include <iostream>
#define SIZE 100
using namespace std;

class STACK 
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
}; 

STACK::STACK()
{
    top = -1;
}

int STACK::isEmpty()
{
    if (top == -1)
        return 0;
    else
        return 1;
}

int STACK::isFull()
{
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

int STACK::push(int n)
{
    if (isFull()) return -9999;

    ++top;
    num[top] = n;
    return n;
}

int STACK::pop()
{
    int temp;
    if (isEmpty())
        return -9999;
    temp = num[top];
    --top;
    return temp;
}

void STACK::displayItems()
{
    int i;
    cout << "STACK is: ";
    for (i = (top); i >= 0; i--)
        cout << num[i] << " ";
    cout << endl;
}
