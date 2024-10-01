#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueueF(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->prev = NULL;
        n->next = f;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            n->next = f;
            f->prev = n;
            f = n;
        }
    }
}

void enqueueR(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        n->prev = r;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            n->prev = r;
            r = n;
        }
    }
}

int dequeueF()
{
    int val = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        f->prev = NULL;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int dequeueR()
{
    int val = -1;
    struct Node *ptr = r;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        r = r->prev;
        r->next = NULL;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    enqueueR(11);
    enqueueR(12);
    enqueueR(13);
    enqueueF(14);
    enqueueF(15);
    enqueueF(16);
    
    linkedListTraversal(f);

    printf("Dequeuing element from Front --> %d\n", dequeueF());
    printf("Dequeuing element from Front --> %d\n", dequeueF());
    printf("Dequeuing element from Rear --> %d\n", dequeueR());
    printf("Dequeuing element from Rear --> %d\n", dequeueR());

    linkedListTraversal(f);
    return 0;
}
