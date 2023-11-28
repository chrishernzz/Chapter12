#include "DynamicArray.h"

//**************************** Constructors ***************************//

 // Default constructor
 // Postcondition: An empty DynamicArray is created.
template <typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), size(0), capacity(0) {}

// Argument constructor
// Precondition: initialCapacity must be greater than or equal to 0.
// Postcondition: A DynamicArray with the specified initial capacity is created.
template <typename T>
DynamicArray<T>::DynamicArray(int initialCapacity) : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

// Destructor
// Postcondition: The DynamicArray is destroyed, and its memory is deallocated.
template <typename T>
DynamicArray<T>::~DynamicArray(){
    delete[] data;
}
//**************************** Accessors *********************************//
// Get the current size of the DynamicArray
template <typename T>
int DynamicArray<T>::getSize() const{
    return size;
}
//**************************** Mutator *********************************//
// Set the size of the DynamicArray
template <typename T>
void DynamicArray<T>::setSize(int newSize){
    size = newSize;
}
//**************************** Public Member Function **************************//
// Precondition: NA
// Postcondition: Clear the DynamicArray
template <typename T>
void DynamicArray<T>::clear()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

// Insert an item at the end of the DynamicArray
// Precondition: A valid data type item variable
// Postcondition: The item is added to the DynamicArray.
template <typename T>
void DynamicArray<T>::insert(const T& item){
    if (size >= capacity){
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i){
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = item;
}

// Search for an item in the DynamicArray
// Precondition: count must be less than the size of the DynamicArray.
// Postcondition: Returns true if the item is found at the specified count, otherwise, returns false.
template <typename T>
bool DynamicArray<T>::serial_search(const T& item, int& index){
    if (index < size) {
        if (item == data[index]){
            return true;
        }
        index++;
        serial_search(item, index);
    }
    else{
        return false;
    }
}

// Binary Search for an item in the DynamicArray using recursion
// Precondition: A sorted DynamicArray, valid first and last indices
// Postcondition: Returns true if the item is found, otherwise, returns false.
template <typename T>
bool DynamicArray<T>::binary_search(const T& item, int first, int last, int& index){
    if (first > last){
        return false; // Item not found
    }

    int middle = first + (last - first) / 2;

    if (data[middle] == item){
        index = middle;
        return true; // Item found
    }
    else if (data[middle] > item){
        return binary_search(item, first, middle - 1, index); // Search the left half
    }
    else{
        return binary_search(item, middle + 1, last, index); // Search the right half
    }
}


// Remove an item from the DynamicArray
// Precondition: A valid data type item variable
// Postcondition: If the item is found, it is removed, and the size is updated.
template <typename T>
bool DynamicArray<T>::remove(const T& item){
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (data[i] == item) {
            index = i;
            break;
        }
    }
    if (index != -1){
        for (int i = index; i < size - 1; ++i){
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
    return false;
}

// Sort the DynamicArray in ascending order
// Precondition: NA
// Postcondition: The DynamicArray is sorted in ascending order.
template <typename T>
void DynamicArray<T>::sort_array(){
    sort(data, data + size);
}

//************************** Overloading Operator ***********************//

// Compare two DynamicArrays based on their sizes
// Precondition: A DynamicArray object
// Postcondition: The DynamicArray is sorted in ascending order.
template <typename T>
bool DynamicArray<T>::operator<(const DynamicArray<T>& other) const{
    return size < other.size;
}

// Access an item by index
// Precondition: The index must be within the bounds of the DynamicArray.
// Postcondition: Returns a reference to the item at the specified index.
template <typename T>
T& DynamicArray<T>::operator[](int index){
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

// Access a constant item by index
// Precondition: The index must be within the bounds of the DynamicArray.
// Postcondition: Returns a constant reference to the item at the specified index.
template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const{
    if (index >= 0 && index < size) {
        return data[index];
    }
    throw out_of_range("Index out of bounds");
}

// Output the DynamicArray
// Precondition: An ostream object, A DynamicArray object
// Postcondition: The DynamicArray is output to the provided ostream.
template <typename T>
ostream& operator<<(ostream& out, const DynamicArray<T>& array){
    for (int i = 0; i < array.size; ++i) {
        out << array.data[i] << " ";
    }
    return out;
}
