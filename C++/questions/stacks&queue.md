## **Phase 3: Stacks and Queues**

### **Topic 3.1: Stack Fundamentals**

**Core Concepts to Master:**
- LIFO principle and stack operations
- Array-based vs Linked List-based implementation
- Stack overflow and underflow handling
- Applications of stacks

**Problem 27: Stack Implementation Using Arrays**
```cpp
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
```

**Problem 28: Stack Implementation Using Linked List**
```cpp
// Node for stack
struct StackNode {
    int data;
    StackNode* next;
    
    StackNode(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
private:
    StackNode* top;
    int count;
    
public:
    LinkedStack();
    ~LinkedStack();
    
    // Basic operations:
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    int size();
    void display();
    void clear();
    
    // Advanced operations:
    void reverse();
    LinkedStack* merge(LinkedStack& other);
    bool isEqual(LinkedStack& other);
    void removeDuplicates();
    int findMax();
    int findMin();
};
```

**Problem 29: Stack Applications - Expression Evaluation**
```cpp
// 1. Check balanced parentheses
bool isBalanced(string expr);

// 2. Check balanced parentheses with different types (), [], {}
bool isBalancedMultiple(string expr);

// 3. Convert infix to postfix
string infixToPostfix(string infix);

// 4. Convert infix to prefix
string infixToPrefix(string infix);

// 5. Convert postfix to infix
string postfixToInfix(string postfix);

// 6. Convert prefix to infix
string prefixToInfix(string prefix);

// 7. Evaluate postfix expression
int evaluatePostfix(string postfix);

// 8. Evaluate prefix expression
int evaluatePrefix(string prefix);

// 9. Evaluate infix expression
int evaluateInfix(string infix);

// Helper functions:
int precedence(char op);
bool isOperator(char c);
bool isOperand(char c);
int performOperation(int a, int b, char op);
```

**Problem 30: Stack Applications - Advanced Problems**
```cpp
// 1. Next Greater Element
vector<int> nextGreaterElement(vector<int>& nums);

// 2. Next Smaller Element
vector<int> nextSmallerElement(vector<int>& nums);

// 3. Previous Greater Element
vector<int> previousGreaterElement(vector<int>& nums);

// 4. Previous Smaller Element
vector<int> previousSmallerElement(vector<int>& nums);

// 5. Largest Rectangle in Histogram
int largestRectangleArea(vector<int>& heights);

// 6. Maximum Rectangle in Binary Matrix
int maximalRectangle(vector<vector<char>>& matrix);

// 7. Stock Span Problem
vector<int> calculateSpan(vector<int>& prices);

// 8. Celebrity Problem
int findCelebrity(vector<vector<int>>& matrix, int n);

// 9. Decode String (nested brackets)
string decodeString(string s);

// 10. Valid Parentheses with wildcards
bool checkValidString(string s);
```

### **Topic 3.2: Advanced Stack Operations**

**Problem 31: Stack Sorting and Manipulation**
```cpp
// 1. Sort stack using recursion (no extra stack)
void sortStackRecursive(stack<int>& st);
void insertSorted(stack<int>& st, int element);

// 2. Sort stack using temporary stack
void sortStackIterative(stack<int>& st);

// 3. Reverse stack using recursion (no extra space)
void reverseStackRecursive(stack<int>& st);
void insertAtBottom(stack<int>& st, int element);

// 4. Remove middle element from stack
void removeMiddle(stack<int>& st);

// 5. Find middle element without removing
int findMiddle(stack<int>& st);

// 6. Clone/Copy stack
stack<int> cloneStack(stack<int>& original);

// 7. Merge two stacks alternately
stack<int> mergeAlternately(stack<int>& st1, stack<int>& st2);
```

**Problem 32: Multiple Stacks Implementation**
```cpp
// 1. Two stacks in one array
class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;
    
public:
    TwoStacks(int n);
    ~TwoStacks();
    
    void push1(int data);
    void push2(int data);
    int pop1();
    int pop2();
    bool isEmpty1();
    bool isEmpty2();
    bool isFull();
    void display1();
    void display2();
};

// 2. k stacks in one array
class KStacks {
private:
    int* arr;      // Array to store elements
    int* top;      // Array to store top of each stack
    int* next;     // Array to store next entry in all stacks
    int free;      // To store beginning of free list
    int capacity;  // Total capacity
    int k;         // Number of stacks
    
public:
    KStacks(int k, int n);
    ~KStacks();
    
    void push(int item, int sn);
    int pop(int sn);
    bool isEmpty(int sn);
    bool isFull();
    void display(int sn);
};

// 3. Stack with getMin operation in O(1)
class SpecialStack {
private:
    stack<int> mainStack;
    int minElement;
    
public:
    void push(int data);
    int pop();
    int top();
    int getMin();
    bool empty();
};
```

### **Topic 3.3: Queue Fundamentals**

**Problem 33: Queue Implementation Using Arrays**
```cpp
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
```

**Problem 34: Queue Implementation Using Linked List**
```cpp
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
```

**Problem 35: Queue Using Stacks**
```cpp
// 1. Queue using two stacks (Method 1: Expensive enqueue)
class QueueUsingStacksV1 {
private:
    stack<int> stack1; // For enqueue
    stack<int> stack2; // For dequeue
    
public:
    void enqueue(int data);
    int dequeue();
    int front();
    bool empty();
    int size();
};

// 2. Queue using two stacks (Method 2: Expensive dequeue)
class QueueUsingStacksV2 {
private:
    stack<int> stack1; // Main stack
    stack<int> stack2; // Helper stack
    
public:
    void enqueue(int data);
    int dequeue();
    int front();
    bool empty();
    int size();
};

// 3. Stack using two queues (Method 1: Expensive push)
class StackUsingQueuesV1 {
private:
    queue<int> queue1; // Main queue
    queue<int> queue2; // Helper queue
    
public:
    void push(int data);
    int pop();
    int top();
    bool empty();
    int size();
};

// 4. Stack using two queues (Method 2: Expensive pop)
class StackUsingQueuesV2 {
private:
    queue<int> queue1; // For push
    queue<int> queue2; // For pop
    
public:
    void push(int data);
    int pop();
    int top();
    bool empty();
    int size();
};
```

### **Topic 3.4: Deque (Double-ended Queue)**

**Problem 36: Deque Implementation**
```cpp
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
```

### **Topic 3.5: Priority Queue and Advanced Queue Applications**

**Problem 37: Priority Queue Implementation**
```cpp
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
```

**Problem 38: Queue Applications - Advanced Problems**
```cpp
// 1. Generate binary numbers from 1 to n using queue
vector<string> generateBinaryNumbers(int n);

// 2. First non-repeating character in stream
class FirstNonRepeating {
private:
    queue<char> q;
    int charCount[256];
    
public:
    FirstNonRepeating();
    char getFirstNonRepeating(char ch);
    void reset();
};

// 3. Sliding window maximum using deque
vector<int> maxSlidingWindow(vector<int>& nums, int k);

// 4. First negative integer in every window of size k
vector<int> firstNegativeInWindow(vector<int>& arr, int k);

// 5. Reverse first k elements of queue
void reverseFirstK(queue<int>& q, int k);

// 6. Interleave first and second half of queue
void interleaveQueue(queue<int>& q);

// 7. Check if queue can be sorted using stack
bool canBeSortedUsingStack(queue<int>& q);

// 8. Minimum time to rot all oranges (BFS application)
int orangesRotting(vector<vector<int>>& grid);

// 9. Design circular tour problem
int circularTour(vector<pair<int,int>>& petrolPumps);

// 10. LRU Cache using queue and hash map
class LRUCacheQueue {
private:
    struct Node {
        int key, value;
        Node* prev, *next;
    };
    unordered_map<int, Node*> cache;
    Node* head, *tail;
    int capacity;
    
public:
    LRUCacheQueue(int capacity);
    int get(int key);
    void put(int key, int value);
    void addToHead(Node* node);
    void removeNode(Node* node);
    void moveToHead(Node* node);
    Node* popTail();
};
```

**Problem 39: Real-world Applications**
```cpp
// 1. Task Scheduler simulation
class TaskScheduler {
private:
    struct Task {
        int id;
        int priority;
        int executionTime;
        int arrivalTime;
    };
    priority_queue<Task> taskQueue;
    
public:
    void addTask(int id, int priority, int execTime, int arrivalTime);
    void executeTasks();
    void displayWaitingTasks();
    double getAverageWaitTime();
};

// 2. Call Center simulation
class CallCenter {
private:
    queue<int> incomingCalls;
    queue<int> onHoldCalls;
    int availableAgents;
    
public:
    CallCenter(int agents);
    void receiveCall(int callId);
    void answerCall();
    void endCall();
    void putOnHold(int callId);
    void displayStatus();
};

// 3. Print Queue simulation
class PrintQueue {
private:
    struct PrintJob {
        string document;
        int pages;
        int priority;
        string user;
    };
    queue<PrintJob> printJobs;
    
public:
    void addPrintJob(string doc, int pages, int priority, string user);
    void processPrintJob();
    void cancelJob(string user);
    void displayQueue();
    int estimatedWaitTime();
};

// 4. Web crawler using BFS
class WebCrawler {
private:
    queue<string> urlQueue;
    unordered_set<string> visited;
    
public:
    void addURL(string url);
    void crawl();
    bool isVisited(string url);
    vector<string> extractLinks(string url);
    void displayCrawledData();
};
```

**Problem 40: Advanced Data Structure Combinations**
```cpp
// 1. Monotonic Stack applications
class MonotonicStack {
public:
    // Next greater element to right
    vector<int> nextGreaterElements(vector<int>& nums);
    
    // Daily temperatures
    vector<int> dailyTemperatures(vector<int>& temperatures);
    
    // Remove k digits to make smallest number
    string removeKdigits(string num, int k);
    
    // Trapping rain water
    int trap(vector<int>& height);
};

// 2. Monotonic Deque applications
class MonotonicDeque {
public:
    // Sliding window maximum
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
    
    // Shortest subarray with sum at least k
    int shortestSubarray(vector<int>& nums, int k);
    
    // Jump game VI
    int maxResult(vector<int>& nums, int k);
};

// 3. Design browser history with stack
class BrowserHistory {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;
    
public:
    BrowserHistory(string homepage);
    void visit(string url);
    string back(int steps);
    string forward(int steps);
    void clearHistory();
    vector<string> getBackHistory();
    vector<string> getForwardHistory();
};
```

This completes the comprehensive Stacks and Queues section. Key learning outcomes:

1. **Core Concepts**: Understanding LIFO and FIFO principles
2. **Implementation Variants**: Array-based vs. linked list-based implementations
3. **Advanced Applications**: Expression evaluation, monotonic structures, sliding window problems
4. **Real-world Scenarios**: Task scheduling, browser history, call centers
5. **Algorithm Patterns**: Stack for expression parsing, queue for BFS, deque for sliding window

**Before moving to Phase 4 (Trees):**
- Implement all stack and queue variants from scratch
- Master the conversion between different implementations
- Understand space-time trade-offs for each approach
- Practice debugging overflow/underflow conditions

Ready for **Phase 4: Trees and Binary Trees**?