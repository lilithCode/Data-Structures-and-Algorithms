#include <iostream>
using namespace std;
class Queue
{
private:
    int rear = -1;
    int front = -1;
    size_t size;
    int *arr;

public:
Queue(size_t s):
size{s}, arr{new int[size]}, rear{-1}, front{-1}{}
    bool isFull()
    {
        return (rear+1)%size==front? 1 : 0;
    }
    bool isEmpty()
    {
        return front == -1 ? 1 : 0;
    }
    void enqueue(int data)
    {
        
        if (isFull())
        {
            std::cout << "Queue Overflow"<<std::endl;
            return;
        }
        rear=(rear+1)%size;
        arr[rear] = data;
        if (front==-1)
        {
            front=0;
        }
    }
    void denqueue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty"<<std::endl;
            return;
        }
        front=(front+1)%size;        
    }
    void display (){
        for (size_t i = front; i <= rear; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        
    }
};
int main()
{
    Queue queue(5);
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.denqueue();

    queue.display();

    return 0;
}