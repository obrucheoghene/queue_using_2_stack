#include "queue.h"

int s1[5];
int s2[5];
int n = 5;
int top1 = -1;
int top2 = -1;
int count = 0;

/**
 * main - Implements queue using two stacks
 *
 * Return: Always 0
 */
int main(void)
{
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    enque(5);
    display();

    deque();
    deque();
    display();
}

/**
 * enque - Add item to queue
 *
 * Return: Nothing
 */
void enque(int x)
{
    push1(x);
}

/**
 * deque - Remove item from queue
 *
 * Return: Value of item removed
 */
int deque()
{   
    int x;
    while (top1 != -1)
    {
        push2(pop1());
    }
    x = pop2();
    while (top2 != -1)
    {
        push1(pop2());
    }
    
    return (x);
}

/**
 * display - Print all items in queue
 *
 * Return: Nothing
 */
void display()
{
    int i = 0;

    while (i <= top1)
    {
        printf("%d ", s1[i]);
        i++;
    }
    printf("\n");
}

/**
 * pop1 - Removes the top item on stack1
 *
 * Return: Value of item
 */
int pop1()
{
    return (s1[top1--]);
}

/**
 * push1 - Adds item to the top of stack1
 *
 * Return: Nothing
 */
void push1(int x)
{
    if (top1 == (n - 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        top1++;
        s1[top1] = x;
    }
}

/**
 * pop2 - Removes the top item on stack2
 *
 * Return: Value of item
 */
int pop2()
{
    return (s2[top2--]);
}

/**
 * push2 - Adds item to the top of stack2
 *
 * Return: Nothing
 */
void push2(int x)
{
    if (top2 == (n - 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        top2++;
        s2[top2] = x;
    }
}
