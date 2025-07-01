#include <iostream>
#include <cassert>
#include <sstream>
#include <cstdio>
using namespace std;

// Include the ArrayOperations class here (copy from array.cpp without main function)
class ArrayOperations {
private:
    int* arr;
    int size;
    int capacity;
    void resize(int newCapacity){
        int *newArr = (int*) realloc(arr, newCapacity * sizeof(int));
        if(!newArr) return;
        capacity = newCapacity;
        arr = newArr;
    }
public:
    ArrayOperations(int initialCapacity){
        size = 0;
        capacity = initialCapacity;
        arr = (int*) calloc(capacity, sizeof(int));
    }
    ~ArrayOperations(){
        free(arr);
    }

    void insertAt(int index,int value){
        if(index<0 || index >size){  
            cout<<"Invalid index for insertion"<<endl;
            return;
        }
        while(size==capacity) resize(capacity+5);
        
        for(int i = size; i>index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = value;
        size++;
    }
    
    void deleteAt(int index){
        if(index<0 || index >=size){
            cout<< "Invalid index for deletion.";
            return;
        }
        for(int i = index; i<size; i++) arr[i] = arr[i+1];
        size--;
    }

    int search(int value) {
        for(int i = 0; i<size; i++){
            if(arr[i]==value) return i;
        }
        return -1;
    }

    void display(){
        cout<< "Array["<<size<<"]: ";
        for(int i =0; i<size; i++) cout<<arr[i]<<" ";
    }
    
    int get(int index){
        if(index<0|| index>=size) {
            cout<<"Index out of bound";
            return -1;
        }
        return arr[index];
    }
    
    void set(int index, int value){
        if(index<0 || index>=size){
            cout<<"Index out of bound";
            return;
        }
        arr[index] = value;
    }
    
    void push(int value){
        insertAt(size, value);
    }
    
    int pop(){
        if(size==0){
            cout<<"Array Empty";
            return -1;
        }
        int val = arr[size-1];
        deleteAt(size-1);
        return val;
    }
    
    int getSize() { return size; }
    int getCapacity() { return capacity; }
};

void testConstructor() {
    ArrayOperations arr(10);
    assert(arr.getSize() == 0);
    assert(arr.getCapacity() == 10);
    cout << "Constructor test passed" << endl;
}

void testInsertAt() {
    ArrayOperations arr(5);
    
    // Test normal insertion
    arr.insertAt(0, 10);
    assert(arr.get(0) == 10);
    assert(arr.getSize() == 1);
    
    arr.insertAt(1, 20);
    arr.insertAt(0, 5);
    assert(arr.get(0) == 5);
    assert(arr.get(1) == 10);
    assert(arr.get(2) == 20);
    
    // Test capacity expansion
    arr.insertAt(3, 30);
    arr.insertAt(4, 40);
    arr.insertAt(5, 50); // Should trigger resize
    assert(arr.getSize() == 6);
    
    cout << "InsertAt test passed" << endl;
}

void testDeleteAt() {
    ArrayOperations arr(5);
    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    arr.insertAt(2, 30);
    
    arr.deleteAt(1);
    assert(arr.get(0) == 10);
    assert(arr.get(1) == 30);
    assert(arr.getSize() == 2);
    
    cout << "DeleteAt test passed" << endl;
}

void testSearch() {
    ArrayOperations arr(5);
    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    arr.insertAt(2, 30);
    
    assert(arr.search(20) == 1);
    assert(arr.search(40) == -1);
    
    cout << "Search test passed" << endl;
}

void testGetSet() {
    ArrayOperations arr(5);
    arr.insertAt(0, 10);
    arr.insertAt(1, 20);
    
    assert(arr.get(0) == 10);
    arr.set(0, 15);
    assert(arr.get(0) == 15);
    
    cout << "Get/Set test passed" << endl;
}

void testPushPop() {
    ArrayOperations arr(3);
    
    arr.push(10);
    arr.push(20);
    arr.push(30);
    
    assert(arr.getSize() == 3);
    assert(arr.pop() == 30);
    assert(arr.pop() == 20);
    assert(arr.getSize() == 1);
    
    cout << "Push/Pop test passed" << endl;
}

int main() {
    testConstructor();
    testInsertAt();
    testDeleteAt();
    testSearch();
    testGetSet();
    testPushPop();
    
    cout << "All tests passed!" << endl;
    return 0;
}