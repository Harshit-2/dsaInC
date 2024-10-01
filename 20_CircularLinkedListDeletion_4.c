#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteTheValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = p->next;
    int i = 0;
    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    free(q);
    return head;
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

    head->data = 11;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 14;
    fourth->next = head;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    head = deleteTheValue(head, 13);
    printf("\nLinked list after deletion\n");
    linkedListTraversal(head);
    return 0;
}
