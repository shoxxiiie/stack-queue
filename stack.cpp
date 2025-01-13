#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Stack(size_t capacity = 4) : capacity(capacity), size(0)
    {
        data = new T[capacity];
    }

    ~Stack()
    {
        delete[] data;
    }

    void Resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void Push(const T& value) 
    {
        if (size == capacity)
        {
            Resize(capacity * 2);
        }
        data[size++] = value;
    }

    T& Peek() 
    {
        if (size == 0)
            throw runtime_error(" ");
        return data[size - 1];
    }

    void Pop() 
    {
        if (size == 0)
            throw runtime_error(" ");
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
    Stack<int> intStack;
    intStack.Push(1);
    intStack.Push(2);
    intStack.Push(3);

    cout << "Integer stack:" << endl;
    while (intStack.GetSize() > 0)
    {
        cout << intStack.Peek() << endl;
        intStack.Pop();
    }

    Stack<string> stringStack;
    stringStack.Push("Hello");
    stringStack.Push("World");
    stringStack.Push("!");

    cout << "\nString stack:" << endl;
    while (stringStack.GetSize() > 0)
    {
        cout << stringStack.Peek() << endl;
        stringStack.Pop();
    }

    return 0;
}
