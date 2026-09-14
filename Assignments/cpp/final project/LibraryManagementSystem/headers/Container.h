#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <string>
using namespace std;

namespace LibrarySystem {
template <class T>
class Container {
    T* arr;
    int size;
    int capacity;

    void grow() {
        capacity = capacity * 2;
        T* temp = new T[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = arr[i];
        delete[] arr;
        arr = temp;
    }

public:
    Container() {
        size = 0;
        capacity = 5;
        arr = new T[capacity];
    }

    Container(const Container& c) {
        size = c.size;
        capacity = c.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = c.arr[i];
    }

    Container& operator=(const Container& c) {
        if (this != &c) {
            delete[] arr;
            size = c.size;
            capacity = c.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++)
                arr[i] = c.arr[i];
        }
        return *this;
    }

    ~Container() {
        delete[] arr;
    }

    void add(T value) {
        if (size == capacity)
            grow();
        arr[size] = value;
        size++;
    }

    void remove(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++)
                arr[i] = arr[i + 1];
            size--;
        }
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        return arr[index];
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    T* find(int id) {
        for (int i = 0; i < size; i++) {
            if (arr[i].getId() == id)
                return &arr[i];
        }
        return nullptr;
    }

    T* find(string name) {
        for (int i = 0; i < size; i++) {
            if (arr[i].getName() == name)
                return &arr[i];
        }
        return nullptr;
    }
};
}
#endif
