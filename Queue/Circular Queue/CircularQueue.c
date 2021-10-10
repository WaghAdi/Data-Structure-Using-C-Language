#include <stdio.h>
#define max 5
//structure for queue
struct cirularQueue
{
    int front;
    int rare;
    int arr[max];
};

//initialization of variable
void init(struct cirularQueue *q1)
{
    q1->front = q1->rare = -1;
}

//to cheak weather queue is empty
int isEmpty(struct cirularQueue *q1)
{
    return (q1->front == -1 && q1->rare == -1);
}

//cheak weather queue is full
int isFull(struct cirularQueue *q1)
{
    int temp = (q1->rare + 1) % max;
    return q1->front == temp;
}

//to add element to queue
void enqueue(struct cirularQueue *q1)
{
    if (!isFull(q1))
    {
        int data;
        printf("enter data\n");
        scanf("%d", &data);
        if (q1->front == -1 && q1->rare == -1) //if adding for first then set front and rare to 1
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

//delete element from queue
int dequeue(struct cirularQueue *q1)
{
    if (!isEmpty(q1))
    {
        int data;
        if (q1->front == q1->rare) //set front and rare to -1 after deleting 1 element which is only one in queue
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
    init(&q1); //fun call to initialize variable

    //Menu Driven Code
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