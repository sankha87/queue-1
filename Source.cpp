// C program for array implementation of queue 
#include <limits.h> 
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> 

struct Queue 
{
	int front, rear, size;
	int capacity;
	int *array;
};

struct Queue* createQueue(int cap)		// function to create a queue of given capacity. It initializes size of queue as 0 
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->capacity = cap;
	q->front = q->size = 0;

	q->rear = cap - 1;		// This is important, see the enqueue 
	q->array = (int*)malloc(q->capacity * sizeof(int));
	return q;
}

int isFull(struct Queue *q)		// Queue is full when size becomes equal to the capacity 
{
	return (q->size == q->capacity);
}

int isEmpty(struct Queue *q)		// Queue is empty when size is 0 
{
	return (q->size == 0);
}

void enqueue(struct Queue *q, int item)		// Function to add an item to the queue. It changes rear and size 
{
	if (isFull(q))
	{
		printf("\nQueue is Full \n");
		return;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = item;
	q->size = q->size + 1;
	printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* q)		// Function to remove an item from queue. It changes front and size 
{
	if (isEmpty(q))
		return INT_MIN;
	int item = q->array[q->front];
	q->front = (q->front + 1)% q->capacity;
	q->size = q->size - 1;
	return item;
}

int front(struct Queue* q)		// Function to get front of queue 
{
	if (isEmpty(q))
		return INT_MIN;
	return q->array[q->front];
}

int rear(struct Queue* q)		// Function to get rear of queue 
{
	if (isEmpty(q))
		return INT_MIN;
	return q->array[q->rear];
}

int main()
{
	struct Queue *queue = createQueue(5);

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	enqueue(queue, 10);

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	enqueue(queue, 50);
	enqueue(queue, 60);

	printf("\n%d dequeued from queue\n\n", dequeue(queue));

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	enqueue(queue, 60);
	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	_getch();
}
