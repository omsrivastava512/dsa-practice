// Simple priority queue using array
class SimplePriorityQueue {
private:
    struct Element {
        int data;
        int priority;
    };
    Element* arr;
    int capacity;
    int size;
    
public:
    SimplePriorityQueue(int cap);
    ~SimplePriorityQueue();
    
    void enqueue(int data, int priority);
    int dequeue(); // Remove highest priority element
    int peek();
    bool isEmpty();
    bool isFull();
    void display();
    
    // Different priority implementations:
    int dequeueHighestPriority();
    int dequeueLowestPriority();
    void changePriority(int data, int newPriority);
};

// Priority queue using binary heap
class HeapPriorityQueue {
private:
    struct HeapNode {
        int data;
        int priority;
    };
    HeapNode* heap;
    int capacity;
    int size;
    
    void heapifyUp(int index);
    void heapifyDown(int index);
    void swap(int i, int j);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    
public:
    HeapPriorityQueue(int cap);
    ~HeapPriorityQueue();
    
    void insert(int data, int priority);
    int extractMax();
    int getMax();
    void decreaseKey(int index, int newPriority);
    void increaseKey(int index, int newPriority);
    bool isEmpty();
    void display();
};