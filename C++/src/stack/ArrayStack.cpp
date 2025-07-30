class ArrayStack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    ArrayStack(int size);
    ~ArrayStack();
    
    // Basic operations to implement:
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    void clear();
    
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