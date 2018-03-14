//Реализовать очередь с динамическим зацикленным буфером.


#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;

class Queue {
public:
    explicit Queue(int size);
    ~Queue() { delete[] array; }
    void grow(); // функция увелечние буфера в 2 раза
    void Enqueue(int a);
    int Dequeue();
    
private:
    int* array;
    int head;
    int tail;
    int bufferSize;
    int count;
};

void Queue::grow()
{
    int newBufferSize = bufferSize * 2;
    int* newArray = new int[newBufferSize + 1];
    for ( int i = 0; i <= count; ++i ) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    bufferSize = newBufferSize;
    head = newBufferSize + 1;
}

Queue::Queue(int size): bufferSize(size), tail(0), count(0)
{
    head = bufferSize + 1;
    array = new int[bufferSize + 1];
}

void Queue::Enqueue(int element)
{
    if ( tail + 1 == head ) {
        grow();
    }
    array[tail++] = element;
    tail = tail % (bufferSize + 1);
    count++;
}

int Queue::Dequeue()
{
    if ( head % (bufferSize + 1) == tail )
        
    {
        return -1;
    }
    head = head % (bufferSize + 1);
    int deleted_element = array[head++];
    
    count--;
    return deleted_element;
}

int main()
{
    Queue object(8);
    int OperationCounter = 0;
    cin >> OperationCounter;
    assert( OperationCounter <= 1000000 && OperationCounter > 0 );
    int value = 0, operation = 0;
    
    for ( int i = 0; i < OperationCounter; ++i ) {
        cin >> operation >> value;
        switch (operation) {
            case 2: {
                if ( object.Dequeue() != value ) {
                    cout << "NO";
                    return 0;
                }
                break;
            }
            case 3: {
                object.Enqueue(value);
                break;
            }
        }
    }
    cout << "YES";
    
    return 0;
}
