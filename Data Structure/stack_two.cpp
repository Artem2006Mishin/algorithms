#include <iostream>
using namespace std;

struct node_t
{
    int data;
    node_t* next;
};

struct custom_stack_t
{
    node_t* head;
    size_t size;
};

void stack_init(custom_stack_t* stack)
{
    stack->head = nullptr;
    stack->size = 0;
}

void stack_push(custom_stack_t* stack, int value)
{
    node_t* node = new node_t;
    node->next = stack->head;
    node->data = value;

    stack->head = node;
    ++stack->size;
}

int stack_top(custom_stack_t* stack)
{
    return stack->head->data;
}

void stack_pop(custom_stack_t* stack)
{
    if (stack->size != 0) {
        node_t* temp = stack->head;
        stack->head = stack->head->next; 
        delete temp;       
        --stack->size;
    }
}

int main()
{
    custom_stack_t stack;
    stack_init(&stack);

    stack_push(&stack, 5);
    stack_push(&stack, 10);
    stack_push(&stack, 15);

    cout << stack_top(&stack) << endl;

    stack_pop(&stack);
    cout << stack_top(&stack) << endl;
}
