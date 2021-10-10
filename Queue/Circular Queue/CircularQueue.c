#include <stdio.h>
#define max 5
struct cirularQueue
{
    int front;
    int rare;
    int arr[max];
};

void init(struct cirularQueue *q1)
{
    q1->front = q1->rare = -1;
}

int isEmpty(struct cirularQueue *q1)
{
    return (q1->front == -1 && q1->rare == -1);
}
int isFull(struct cirularQueue *q1)
{
    int temp = (q1->rare + 1) % max;
    return q1->front == temp;
}

void enqueue(struct cirularQueue *q1)
{
    if (!isFull(q1))
    {
        int data;
        printf("enter data\n");
        scanf("%d", &data);
        if (q1->front == -1 && q1->rare == -1)
        {
            q1->front = q1->rare = 1;
            q1->arr[q1->rare] = data;
        }
        else
        {
            int incr = (q1->rare + 1) % max;
            q1->rare = incr;
            q1->arr[q1->rare] = data;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}

int dequeue(struct cirularQueue *q1)
{
    if (!isEmpty(q1))
    {
        int data;
        if (q1->front == q1->rare)
        {
            data = q1->arr[q1->front];
            q1->front = q1->rare = -1;
        }
        else
        {
            int incr = (q1->front + 1) % max;
            data = q1->arr[q1->front];
            q1->front = incr;
        }
        return data;
    }
    else
    {
        printf("Queue is Empty\n");
    }
}

void main()
{
    struct cirularQueue q1;
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