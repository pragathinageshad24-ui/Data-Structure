#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *NODE;

NODE createNode(int val)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
NODE concat(NODE first, NODE second)
{
    NODE cur;

    if (first == NULL) {
        return second;
    }

    cur = first;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = second;

    return first;
}


void display(NODE head)
{
    NODE temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    NODE first = NULL, second = NULL;

    first = createNode(1);
    first->next = createNode(2);
    first->next->next = createNode(3);

    second = createNode(4);
    second->next = createNode(5);

    printf("First List: ");
    display(first);

    printf("Second List: ");
    display(second);

    first = concat(first, second);

    printf("Concatenated List: ");
    display(first);

    return 0;
}
