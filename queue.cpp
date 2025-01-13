#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue
{
private:
    T* data;
    size_t capacity;
    size_t size;
    size_t frontIndex;
    size_t backIndex;

    void Resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[(frontIndex + i) % capacity];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        frontIndex = 0;
        backIndex = size;
    }

public:
    Queue(size_t capacity = 4) 
        : capacity(capacity), size(0), frontIndex(0), backIndex(0)
    {
        data = new T[capacity];
    }

    ~Queue()
    {
        delete[] data;
    }

    void Enqueue(const T& value) // додавання елементу в кінець
    {
        if (size == capacity)
        {
            Resize(capacity * 2);
        }
        data[backIndex] = value;
        backIndex = (backIndex + 1) % capacity;
        size++;
    }

    T& Front() // доступ до першого елемента в черзі
    {
        if (size == 0)
            throw runtime_error(" ");
        return data[frontIndex];
    }

    void Dequeue() // видалення першого елемента
    {
        if (size == 0)
            throw runtime_error(" ");
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }

    size_t GetSize() const
    {
        return size;
    }

    size_t GetCapacity() const
    {
        return capacity;
    }
};

int main()
{
    // Черга для типу int
    Queue<int> intQueue;
    intQueue.Enqueue(10);
    intQueue.Enqueue(12);
    intQueue.Enqueue(15);
    intQueue.Enqueue(1);
    intQueue.Enqueue(1099);

    cout << "Integer queue:" << endl;
    while (intQueue.GetSize() != 0)
    {
        cout << intQueue.Front() << endl;
        intQueue.Dequeue();
    }

    // Черга для типу string
    Queue<string> stringQueue;
    stringQueue.Enqueue("Hello");
    stringQueue.Enqueue("World");
    stringQueue.Enqueue("Queue");

    cout << "\nString queue:" << endl;
    while (stringQueue.GetSize() != 0)
    {
        cout << stringQueue.Front() << endl;
        stringQueue.Dequeue();
    }

    return 0;
}
