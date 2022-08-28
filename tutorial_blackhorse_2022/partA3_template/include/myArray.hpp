#pragma once

#include <iostream>
#include <string>

template<class T>
class myArray
{
friend std::ostream &operator<<(std::ostream &out, myArray<T> &array)
{
    out << "myArray, size=" << array.size << std::endl;
    for(int i=0; i<array.size; ++i)
    {
        out << array.data[i] << " ";
    }
    return out;
}
public:
    myArray(int capacity)
    {
        this->capacity = capacity;
        this->size     = 0;
        this->data = new T[capacity];
    }
    myArray(const myArray &array)
    {
        if(this->data != NULL)
        {
            delete[] data;
            data = NULL;
        }
        this->capacity = array.capacity;
        this->size     = array.size;
        this->data     = new T[array.capacity];
        for(int i=0; i<array.size; ++i)
        {
            this->data[i] = array.data[i];
        }
    }
    ~myArray()
    {
        if(data != NULL)
        {
            delete[] data;
            data = NULL;
        }
        capacity = 0;
        size     = 0;
    }
    int getCapacity()
    {
        return this->capacity;
    }
    int getSize()
    {
        return this->size;
    }

    void pushBack(const T &d)
    {
        this->data[this->size] = d;
        this->size++;
    }
    T& operator[](int i)
    {
        return this->data[i];
    }
private:
    int capacity;
    int size;
    T *data;
};
// std::ostream &operator<<(std::ostream &out, myArray<> &array)
// {
//     cout << "size=" << this->size << ".";
//     for(int i=0; i<array.size; ++i)
//     {
//         out << array.data[i] << " ";    
//     }
//     return out;
// }

class Person
{

};