// Node for queue
struct QueueNode {
    int data;
    QueueNode* next;
    
    QueueNode(int val) : data(val), next(nullptr) {}
};

class LinkedQueue {
private:
    QueueNode* front;
    QueueNode* rear;
    int count;
    
public:
    LinkedQueue();
    ~LinkedQueue();
    
    // Basic operations:
    void enqueue(int data);
    int dequeue();
    int frontElement();
    int rearElement();
    bool isEmpty();
    int size();
    void display();
    void clear();
    
    // Advanced operations:
    void reverse();
    LinkedQueue* merge(LinkedQueue& other);
    bool isEqual(LinkedQueue& other);
    void removeDuplicates();
    int findMax();
    int findMin();
    void sort();
};