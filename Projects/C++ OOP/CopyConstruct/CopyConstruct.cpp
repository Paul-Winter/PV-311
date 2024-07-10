#include <iostream>

class DynArray
{
    int* arr;
    int size;

public:
    DynArray(int size) : arr{ new int[size] {} }, size{ size }
    {
        std::cout << "DynArray constructed for " << size << " elements, for " << this << "\n";
    }
    DynArray() : DynArray(5) {}
    DynArray(const DynArray& object) : arr{ new int[object.size]}, size{object.size}
    {
        for (int i{ 0 }; i < size; ++i)
        {
            arr[i] = object.arr[i];
        };
        std::cout << "DynArray copy constructed for " << size << " elements, for " << this << "\n";
    }

    int getElem(int id) { return arr[id]; }
    void setElem(int id, int value) {
        arr[id] = value;
    }
    void print();
    void randomize();

    ~DynArray()
    {
        std::cout << "Try to free memory from DynArray for " << arr << " pointer\n";
        delete[] arr;
        std::cout << "DynArr destructed for " << size << " elements, for " << this << "\n";
    }
};

int main()
{
    DynArray arr1{ 10 };
    arr1.randomize();
    std::cout << "arr1 elements: ";
    arr1.print();

    DynArray arr2{ arr1 };
    std::cout << "arr2 elements: ";
    arr2.print();

    return 0;
}

void DynArray::print()
{
    for (int i{ 0 }; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

void DynArray::randomize()
{
    for (int i{ 0 }; i < size; ++i)
    {
        arr[i] = rand() % 10;
    }
}