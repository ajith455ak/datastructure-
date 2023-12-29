#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertAtBeginning(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 55);
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 24);
    printf("Linked List: ");
    printList(head);    
    return 0;
}

