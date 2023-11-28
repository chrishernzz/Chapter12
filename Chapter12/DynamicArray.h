#pragma once
#include <algorithm>
#include <iostream>
using namespace std;

// The DynamicArray class is a template class that represents a dynamic array, 
// which is an array that can grow in size as needed. 
// It provides a versatile and dynamic storage solution for elements of any valid data type
template <typename T>
class DynamicArray{
private:
    T* data;
    int size;
    int capacity;

public:
    //Constructors
    DynamicArray();
    DynamicArray(int initialCapacity);
    ~DynamicArray();

    //Accessors
    int getSize() const;

    //Mutator
    void setSize(int newSize);

    //Public member functions
    void clear();
    void insert(const T& item);
    bool serial_search(const T& item, int& index);
    bool binary_search(const T& item, int first, int last, int& index);

    bool remove(const T& item);
    void sort_array();

    //Overload operators
    bool operator<(const DynamicArray<T>& other) const;
    T& operator[](int index);
    const T& operator[](size_t index) const;

    friend ostream& operator<<(ostream& out, const DynamicArray<T>& array);
};


