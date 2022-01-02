#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *A;

public:
    Queue();
    Queue(int);
    ~Queue();

    void Enqueue(int);
    int Dequeue();
    void Display();
    int isEmpty();
    int isFull();
};

Queue::Queue()
{
    size = 10;
    front = -1;
    rear = -1;
    A = new int[this->size];
}

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    A = new int[size];
}

Queue::~Queue()
{
    delete[] A;
}

void Queue::Enqueue(int x)
{
    if (front == size)
    {
        printf("\nStack-overflow!!!\n\n");
        return;
    }

    rear++;
    A[rear] = x;
}

int Queue::Dequeue()
{
    int x;

    if (front == rear)
    {
        printf("\nStack-underflow!!!\n\n");
        return -1;
    }

    front++;

    x = A[front];
    A[front] = 0;

    return x;
}

void Queue::Display()
{
    int i;

    printf("\n\nQueue:\n");

    for (i = front + 1; i <= rear; i++)
        printf("%d \n", A[i]);
}

int Queue::isEmpty()
{
    return rear == front;
}

int Queue::isFull()
{
    return rear == size - 1;
}

int main()
{
    int i, x, n;

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    Queue queue(n);

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);

    printf("\nqueue is Full: %d\n", queue.isFull());
    printf("queue is Empty: %d\n\n", queue.isEmpty());

    printf("Enter Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        queue.Enqueue(x);
    }

    queue.Display();

    printf("\nPopped: %d\n", queue.Dequeue());

    queue.Display();

    printf("\n\nEnter new Element:\n");
    scanf("%d", &x);
    queue.Enqueue(x);

    queue.Display();

    printf("\nPopped: %d\n", queue.Dequeue());

    queue.Display();
    return 0;
}