#include <stdio.h>
#define max 20

struct queue
{
    int arr[max];
    int front;
    int rare;
};

void init(struct queue *queue)
{
    queue->front = queue->rare = -1;
}

int isEmpty(struct queue *queue)
{
    return queue->front == queue->rare;
}
int isFull(struct queue *queue)
{
    return queue->rare == max - 1;
}

void enqueue(struct queue *queue)
{
    int data;
    printf("enter data you want to add\n");
    scanf("%d", &data);
    if (!isFull(queue))
    {
        (queue->rare)++;
        queue->arr[queue->rare] = data;
    }
    else
    {
        printf("Queue is full\n");
    }
}
int dequeue(struct queue *queue)
{

    if (!isEmpty(queue))
    {
        int data;
        (queue->front)++;
        data = queue->arr[queue->front];
        return data;
    }
    else
    {
        printf("Queue Is Empty\n");
    }
}

void main()
{
    struct queue q1;
    int choice;
    init(&q1);
    do
    {
        printf("1 Enqueue\n");
        printf("2 Dequeue\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q1);
            break;
        case 2:
            printf("%d\n", dequeue(&q1));
            break;
        case 0:
            printf("Thank you!!\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 0);
}