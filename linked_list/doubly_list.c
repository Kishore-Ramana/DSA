#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert_end(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display_forward() {
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_backward() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1.Insert 2.Display Forward 3.Display Backward 4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert_end(x);
                break;
            case 2:
                display_forward();
                break;
            case 3:
                display_backward();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
