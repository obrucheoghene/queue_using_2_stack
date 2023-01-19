#include "queue.h"

int s1[100];
int s2[100];
int n = 100;
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
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    dequeue();
    enqueue(3);
    enqueue(4);
    display();
}

/**
 * enqueue - Add item to queue
 *
 * Return: Nothing
 */
void enqueue(int x)
{
    printf("Enqueue %d\n", x);
    push1(x);
}

/**
 * dequeue - Remove item from queue
 *
 * Return: Value of item removed
 */
int dequeue()
{   
    int x;

    if (top1 < 0)
    {
        printf("Queue is empty. There nothing to dequeue. \n");
        return (-1);
    }
    while (top1 > -1)
    {
        push2(pop1());
    }
    x = pop2();
    while (top2 > -1)
    {
        push1(pop2());
    }
    printf("Dequeue %d\n", x);
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

    if (top1 == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Items is in Queue: ");
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
