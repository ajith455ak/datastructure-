#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct HashTable {
    int size;
    struct Node** table;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct HashTable* createHashTable(int size) {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->table = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}
void insert(struct HashTable* hashTable, int key, int value) {
    int index = key % hashTable->size;
    struct Node* newNode = createNode(value);
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        struct Node* currentNode = hashTable->table[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}
int search(struct HashTable* hashTable, int key) {
    int index = key % hashTable->size;
    struct Node* currentNode = hashTable->table[index];
    while (currentNode != NULL) {
        if (currentNode->data == key) {
            return currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return -1;
}
void display(struct HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        printf("Index %d: ", i);
        struct Node* currentNode = hashTable->table[i];
        while (currentNode != NULL) {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}
int main() {
    struct HashTable* hashTable = createHashTable(10);
    insert(hashTable, 5, 10);
    insert(hashTable, 65, 20);
    insert(hashTable, 25, 30);
    insert(hashTable, 35, 40);
    insert(hashTable, 45, 52);
    display(hashTable);
    int key = 25;
    int result = search(hashTable, key);
    if (result != -1) {
        printf("Key %d found in the hash table.\n", key);
    } else {
        printf("Key %d not found in the hash table.\n", key);
    }
    return 0;
}

