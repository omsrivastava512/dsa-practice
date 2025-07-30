#include <iostream>
#include <stack>
using namespace std;

class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    ArrayStack(int cap): arr(new int[cap]), capacity(cap), top(-1){}
    ~ArrayStack(){
        delete[] arr;
    }
    
    // Basic operations to implement:
    void push(int data){
        if(isFull()){
            cout<<"Overflow!"<<endl;
            return;
        }
        arr[++top] = data;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return INT16_MIN;
        }
        return arr[top--];
    }
    int peek()const{
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return INT16_MIN;
        }
        return arr[top];
    }
    bool isEmpty()const{ return top==-1;}
    bool isFull()const{ return top==capacity-1; }
    int size()const{return top+1;}

    void display()const{
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        for(int i = 0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void clear(){
        top = -1;
    }
    
    // Advanced operations:
    int getMin(); // Get minimum element in O(1)
    void reverse(); // Reverse stack elements
    void sort(); // Sort stack elements
    ArrayStack* copy(); // Create a copy of stack
};

// Helper class for getMin() operation
class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
    
public:
    void push(int data);
    int pop();
    int top();
    int getMin();
    bool empty();
};



// Learnings: delete[] releases the array allocated using new[] such as new int[]
// delete[] arr; // ✅ tells C++: call element destructors, then free entire block
// delete arr;   // ❌ wrong for arrays: only first element is destroyed, UB
// delete arr[]; // ❌ invalid syntax: compiler error
