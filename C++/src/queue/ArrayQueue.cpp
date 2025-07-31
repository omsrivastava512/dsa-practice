// Simple queue implementation
class ArrayQueue {
private:
    int* arr;
    int front, rear;
    int capacity;
    int count;
    
public:
    ArrayQueue(int size);
    ~ArrayQueue();
    
    // Basic operations:
    void enqueue(int data);
    int dequeue();
    int frontElement();
    int rearElement();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    void clear();
};

// Circular queue implementation
class CircularQueue {
private:
    int* arr;
    int front, rear;
    int capacity;
    
public:
    CircularQueue(int size);
    ~CircularQueue();
    
    void enqueue(int data);
    int dequeue();
    int frontElement();
    int rearElement();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    
    // Additional operations:
    bool search(int key);
    void reverse();
    CircularQueue* split(); // Split into two queues
};