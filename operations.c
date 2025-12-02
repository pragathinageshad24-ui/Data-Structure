#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} *NODE;

/* ---------- Function to create a node ---------- */
NODE createNode(int val) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

/* ---------- Insert at beginning ---------- */
NODE insertBeg(NODE head, int val) {
    NODE newNode = createNode(val);
    newNode->next = head;
    return newNode;
}

/* ---------- Insert at end ---------- */
NODE insertEnd(NODE head, int val) {
    NODE newNode = createNode(val);

    if (head == NULL)
        return newNode;

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* ---------- Insert at position ---------- */
NODE insertPos(NODE head, int val, int pos) {
    NODE newNode = createNode(val);

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    NODE temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

/* ---------- Delete at beginning ---------- */
NODE deleteBeg(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    NODE temp = head;
    head = head->next;
    free(temp);

    return head;
}

/* ---------- Delete at end ---------- */
NODE deleteEnd(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    NODE temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    NODE last = temp->next;
    temp->next = NULL;
    free(last);

    return head;
}

/* ---------- Delete at position ---------- */
NODE deletePos(NODE head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (pos == 1)
        return deleteBeg(head);

    NODE temp = head;

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    NODE delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);

    return head;
}

/* ---------- Display list ---------- */
void display(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    NODE temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- Count nodes ---------- */
int count(NODE head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

/* ---------- Search element ---------- */
int search(NODE head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

/* ---------- Concatenate two lists ---------- */
NODE concat(NODE first, NODE second) {
    if (first == NULL)
        return second;

    NODE temp = first;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = second;
    return first;
}

/* ---------- MAIN MENU ---------- */
int main() {
    NODE first = NULL, second = NULL;
    int choice, val, pos;

    while (1) {
        printf("\n----- SINGLY LINKED LIST MENU -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Count nodes\n");
        printf("9. Search element\n");
        printf("10. Concatenate with second list\n");
        printf("11. Exit\n");
        printf("------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            first = insertBeg(first, val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            first = insertEnd(first, val);
            break;

        case 3:
            printf("Enter value and position: ");
            scanf("%d %d", &val, &pos);
            first = insertPos(first, val, pos);
            break;

        case 4:
            first = deleteBeg(first);
            break;

        case 5:
            first = deleteEnd(first);
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            first = deletePos(first, pos);
            break;

        case 7:
            display(first);
            break;

        case 8:
            printf("Node count = %d\n", count(first));
            break;

        case 9:
            printf("Enter element to search: ");
            scanf("%d", &val);
            pos = search(first, val);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Found at position %d\n", pos);
            break;

        case 10:
            printf("Creating second list with values (40, 50, 60)...\n");
            second = insertEnd(second, 40);
            second = insertEnd(second, 50);
            second = insertEnd(second, 60);

            printf("Second List: ");
            display(second);

            first = concat(first, second);

            printf("Concatenated List: ");
            display(first);
            break;

        case 11:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
