#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *head, struct Node *fourth)
{
    printf("Doubly Linked List forward traversal\n");
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("\nDoubly Linked List backward traversal\n");
    struct Node *p = fourth;
    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->prev;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 101;
    head->prev = NULL;
    head->next = second;

    second->data = 102;
    second->prev = head;
    second->next = third;

    third->data = 103;
    third->prev = second;
    third->next = fourth;

    fourth->data = 104;
    fourth->prev = third;
    fourth->next = NULL;

    linkedListTraversal(head, fourth);

    return 0;
}
