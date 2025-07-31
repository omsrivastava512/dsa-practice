// Array-based deque implementation
class ArrayDeque {
private:
    int* arr;
    int front, rear;
    int capacity;
    int count;
    
public:
    ArrayDeque(int size);
    ~ArrayDeque();
    
    // Basic operations:
    void pushFront(int data);
    void pushRear(int data);
    int popFront();
    int popRear();
    int getFront();
    int getRear();
    bool isEmpty();
    bool isFull();
    int size();
    void display();
    
    // Advanced operations:
    void reverse();
    bool isPalindrome();
    void clear();
};

// Linked list-based deque implementation
struct DequeNode {
    int data;
    DequeNode* next;
    DequeNode* prev;
    
    DequeNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedDeque {
private:
    DequeNode* front;
    DequeNode* rear;
    int count;
    
public:
    LinkedDeque();
    ~LinkedDeque();
    
    void pushFront(int data);
    void pushRear(int data);
    int popFront();
    int popRear();
    int getFront();
    int getRear();
    bool isEmpty();
    int size();
    void display();
    void displayReverse();
    
    // Advanced operations:
    void reverse();
    bool search(int key);
    void sort();
    void removeDuplicates();
};