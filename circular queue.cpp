#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;
void initializeQueue(CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isFull(CircularQueue *queue) {
    if ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1)) {
        return 1;
    } else {
        return 0;
    }
}
int isEmpty(CircularQueue *queue) {
    if (queue->front == -1) {
        return 1;
    } else {
        return 0;
    }
}
void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = item;
        printf("%d enqueued successfully.\n", item);
    }
}
void dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", queue->data[queue->front]);
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
    }
}
void displayQueue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Queue: ");
        while (i != queue->rear) {
            printf("%d ", queue->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->data[i]);
    }
}
int main() {
    CircularQueue queue;
    initializeQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    displayQueue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    displayQueue(&queue);
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    displayQueue(&queue);
    return 0;
}

