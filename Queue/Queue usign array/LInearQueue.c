#include <stdio.h>

#define max 20
//structure for queue
struct queue
{
    int arr[max];
    int front;
    int rare;
};

//to initialize variable front and rare
void init(struct queue *queue)
{
    queue->front = queue->rare = -1;
}
// function to cheak queue is empty or not
int isEmpty(struct queue *queue)
{
    return queue->front == queue->rare;
}

// function to cheak queue is full or not
int isFull(struct queue *queue)
{
    return queue->rare == max - 1;
}
//fucntio to add data to queue
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
//function to remove data from stack
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
    struct queue q1; //variable of queue
    int choice;
    init(&q1); //initializing fun call
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