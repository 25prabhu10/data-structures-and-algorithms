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
    if ((rear + 1) % size == front)
    {
        printf("\nStack-overflow!!!\n\n");
        return;
    }

    rear = (rear + 1) % size;
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

    front = (front + 1) % size;

    x = A[front];
    A[front] = 0;

    return x;
}

void Queue::Display()
{
    int i = front + 1;

    printf("\n\nQueue:\n");

    do
    {
        printf("%d \n", A[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
}

int Queue::isEmpty()
{
    return rear == front;
}

int Queue::isFull()
{
    return (rear + 1) % size == front;
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
    printf("\nPopped: %d\n", queue.Dequeue());

    queue.Display();

    queue.Enqueue(25);
    // queue.Enqueue(10);

    printf("\n\nEnter new Element:\n");
    scanf("%d", &x);
    queue.Enqueue(x);

    queue.Display();

    printf("\nPopped: %d\n", queue.Dequeue());

    queue.Display();
    return 0;
}