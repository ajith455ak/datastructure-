#include <stdio.h>
#define SIZE 10
int hash(int key)
{
    return key % SIZE;
}
int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
}
void insert(int H[], int key)
{
    int index = hash(key);
    if (H[index] != 0)
    {
        index = probe(H, key);
    }
    H[index] = key;
}
void display(int H[])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\n");
}
int main()
{
    int hashtable[SIZE] = {0};
    insert(hashtable, 12);
    insert(hashtable, 25);
    insert(hashtable, 35);
    insert(hashtable, 26);
    insert(hashtable, 42);
    display(hashtable);
    return 0;
}

