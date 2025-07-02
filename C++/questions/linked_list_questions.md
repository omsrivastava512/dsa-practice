## **Phase 2: Linked Lists**

### **Topic 2.1: Singly Linked List Fundamentals**

**Core Concepts to Master:**
- Node structure and memory allocation
- Basic operations: insertion, deletion, traversal
- Memory management and pointer manipulation

**Problem 14: Basic Singly Linked List Implementation**
```cpp
// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class with all basic operations
class SinglyLinkedList {
private:
    Node* head;
    int size;
    
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    
    // Basic operations to implement:
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int pos);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteByValue(int data);
    void deleteAtPosition(int pos);
    bool search(int data);
    void display();
    void displayReverse(); // using recursion
    int getSize();
    bool isEmpty();
    void clear();
};
```

**Problem 15: Linked List Traversal Patterns**
```cpp
// 1. Print all elements iteratively
void printList(Node* head);

// 2. Print all elements recursively
void printListRecursive(Node* head);

// 3. Print in reverse order using recursion
void printReverse(Node* head);

// 4. Find length iteratively
int lengthIterative(Node* head);

// 5. Find length recursively
int lengthRecursive(Node* head);

// 6. Find nth node from beginning
Node* getNthNode(Node* head, int n);

// 7. Find nth node from end (single traversal)
Node* getNthFromEnd(Node* head, int n);

// 8. Get middle element (slow-fast pointer technique)
Node* getMiddle(Node* head);
```

**Problem 16: Linked List Search and Access**
```cpp
// 1. Search element iteratively
bool searchIterative(Node* head, int key);

// 2. Search element recursively
bool searchRecursive(Node* head, int key);

// 3. Find all occurrences of a value
vector<int> findAllOccurrences(Node* head, int key);

// 4. Find maximum element
int findMax(Node* head);

// 5. Find minimum element
int findMin(Node* head);

// 6. Count occurrences of given element
int countOccurrences(Node* head, int key);
```

### **Topic 2.2: Advanced Singly Linked List Operations**

**Problem 17: List Manipulation and Reversal**
```cpp
// 1. Reverse linked list iteratively
Node* reverseIterative(Node* head);

// 2. Reverse linked list recursively
Node* reverseRecursive(Node* head);

// 3. Reverse in groups of k
Node* reverseInGroups(Node* head, int k);

// 4. Reverse alternate k nodes
Node* reverseAlternateK(Node* head, int k);

// 5. Reverse from position m to n
Node* reverseBetween(Node* head, int m, int n);

// 6. Palindrome check using reversal
bool isPalindromeReverse(Node* head);

// 7. Palindrome check using stack simulation
bool isPalindromeStack(Node* head);
```

**Problem 18: Two Pointer Techniques**
```cpp
// 1. Detect cycle in linked list (Floyd's algorithm)
bool hasCycle(Node* head);

// 2. Find start of cycle
Node* detectCycleStart(Node* head);

// 3. Remove cycle if exists
void removeCycle(Node* head);

// 4. Find intersection point of two lists
Node* findIntersection(Node* head1, Node* head2);

// 5. Check if two lists are identical
bool areIdentical(Node* head1, Node* head2);

// 6. Merge point of two sorted lists
Node* findMergePoint(Node* head1, Node* head2);
```

**Problem 19: Linked List Sorting and Merging**
```cpp
// 1. Merge two sorted linked lists
Node* mergeTwoSorted(Node* head1, Node* head2);

// 2. Merge k sorted linked lists
Node* mergeKSorted(vector<Node*>& lists);

// 3. Sort linked list using merge sort
Node* mergeSort(Node* head);
Node* merge(Node* left, Node* right);
Node* getMiddleForSort(Node* head);

// 4. Sort using bubble sort
Node* bubbleSort(Node* head);

// 5. Sort using insertion sort
Node* insertionSort(Node* head);

// 6. Remove duplicates from sorted list
Node* removeDuplicatesSorted(Node* head);

// 7. Remove duplicates from unsorted list
Node* removeDuplicatesSorted(Node* head);
Node* removeDuplicatesUnsorted(Node* head);
```

### **Topic 2.3: Doubly Linked List**

**Problem 20: Doubly Linked List Implementation**
```cpp
// Node structure for doubly linked list
struct DoublyNode {
    int data;
    DoublyNode* next;
    DoublyNode* prev;
    
    DoublyNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;
    int size;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    // Operations to implement:
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int pos);
    void insertAfterNode(DoublyNode* node, int data);
    void insertBeforeNode(DoublyNode* node, int data);
    
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteByValue(int data);
    void deleteAtPosition(int pos);
    void deleteNode(DoublyNode* node);
    
    void displayForward();
    void displayBackward();
    bool search(int data);
    DoublyNode* getNode(int pos);
    int getSize();
};
```

**Problem 21: Doubly Linked List Advanced Operations**
```cpp
// 1. Reverse doubly linked list
DoublyNode* reverseDLL(DoublyNode* head);

// 2. Sort doubly linked list
DoublyNode* sortDLL(DoublyNode* head);

// 3. Remove duplicates from sorted DLL
DoublyNode* removeDuplicatesDLL(DoublyNode* head);

// 4. Find pairs with given sum in sorted DLL
vector<pair<int,int>> findPairsWithSum(DoublyNode* head, int sum);

// 5. Convert binary tree to DLL
DoublyNode* treeToDoublyList(TreeNode* root);

// 6. Clone a DLL with random pointers
DoublyNode* cloneDLLWithRandom(DoublyNode* head);
```

### **Topic 2.4: Circular Linked List**

**Problem 22: Circular Singly Linked List**
```cpp
// Circular Linked List implementation
class CircularLinkedList {
private:
    Node* last; // Points to last node
    int size;
    
public:
    CircularLinkedList();
    ~CircularLinkedList();
    
    // Operations to implement:
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int pos);
    
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteByValue(int data);
    
    void display();
    bool search(int data);
    int getSize();
    bool isEmpty();
    
    // Special operations:
    void splitIntoTwo(CircularLinkedList& list1, CircularLinkedList& list2);
    bool isCircular();
    Node* josephusProblem(int k); // Josephus problem solution
};
```

**Problem 23: Circular Doubly Linked List**
```cpp
// Circular Doubly Linked List
class CircularDoublyLinkedList {
private:
    DoublyNode* head;
    int size;
    
public:
    // All basic operations
    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void deleteFromBeginning();
    void deleteFromEnd();
    void displayForward();
    void displayBackward();
    
    // Advanced operations:
    void reverseCircularDLL();
    DoublyNode* sortCircularDLL();
    void convertToLinear(); // Remove circular property
};
```

### **Topic 2.5: Complex Linked List Problems**

**Problem 24: Advanced Problem Solving**
```cpp
// 1. Clone linked list with random pointers
struct RandomNode {
    int data;
    RandomNode* next;
    RandomNode* random;
};
RandomNode* cloneListWithRandom(RandomNode* head);

// 2. LRU Cache implementation using DLL
class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev, *next;
    };
    unordered_map<int, Node*> cache;
    Node* head, *tail;
    int capacity;
    
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void addNode(Node* node);
    void removeNode(Node* node);
    void moveToHead(Node* node);
    Node* popTail();
};

// 3. Flatten multilevel linked list
struct MultilevelNode {
    int val;
    MultilevelNode* prev;
    MultilevelNode* next;
    MultilevelNode* child;
};
MultilevelNode* flatten(MultilevelNode* head);

// 4. Add two numbers represented as linked lists
Node* addTwoNumbers(Node* l1, Node* l2);

// 5. Subtract two numbers represented as linked lists
Node* subtractTwoNumbers(Node* l1, Node* l2);

// 6. Multiply two numbers represented as linked lists
Node* multiplyTwoNumbers(Node* l1, Node* l2);
```

**Problem 25: Linked List Applications**
```cpp
// 1. Design a browser history system
class BrowserHistory {
private:
    struct Page {
        string url;
        Page* prev;
        Page* next;
    };
    Page* current;
    
public:
    BrowserHistory(string homepage);
    void visit(string url);
    string back(int steps);
    string forward(int steps);
};

// 2. Design undo-redo functionality
class UndoRedo {
private:
    struct Action {
        string operation;
        string data;
        Action* prev;
        Action* next;
    };
    Action* current;
    
public:
    void execute(string operation, string data);
    void undo();
    void redo();
    vector<string> getHistory();
};

// 3. Music playlist with shuffle
class Playlist {
private:
    struct Song {
        string title;
        Song* next;
        Song* prev;
    };
    Song* current;
    Song* head;
    
public:
    void addSong(string title);
    void removeSong(string title);
    void playNext();
    void playPrevious();
    void shuffle();
    string getCurrentSong();
};

// 4. Polynomial representation and operations
class Polynomial {
private:
    struct Term {
        int coefficient;
        int exponent;
        Term* next;
    };
    Term* head;
    
public:
    void addTerm(int coeff, int exp);
    Polynomial add(const Polynomial& other);
    Polynomial multiply(const Polynomial& other);
    void display();
    int evaluate(int x);
};
```

**Problem 26: Memory Management in Linked Lists**
```cpp
// 1. Memory pool for linked list nodes
class NodePool {
private:
    struct PoolNode {
        Node data;
        PoolNode* next;
        bool inUse;
    };
    PoolNode* pool;
    PoolNode* freeList;
    int poolSize;
    
public:
    NodePool(int size);
    ~NodePool();
    Node* allocateNode();
    void deallocateNode(Node* node);
    int getAvailableNodes();
};

// 2. Garbage collection simulation for linked lists
class GarbageCollector {
private:
    vector<Node*> allocatedNodes;
    vector<Node*> rootNodes;
    
public:
    Node* allocateNode(int data);
    void addRoot(Node* root);
    void markAndSweep();
    void printAllocatedNodes();
    int getMemoryUsage();
};

// 3. Reference counting for automatic memory management
class RefCountedNode {
private:
    int data;
    RefCountedNode* next;
    int refCount;
    
public:
    RefCountedNode(int val);
    void addRef();
    void release();
    RefCountedNode* getNext();
    void setNext(RefCountedNode* node);
};
```

This completes the comprehensive Linked Lists section. Key learning outcomes:

1. **Memory Management**: Direct pointer manipulation and memory allocation/deallocation
2. **Algorithm Patterns**: Two-pointer technique, fast-slow pointers, cycle detection
3. **Problem Solving**: Complex data structure implementations and real-world applications
4. **Performance Analysis**: Understanding time/space complexity of linked list operations

**Before moving to Phase 3 (Stacks and Queues):**
- Implement all problems from scratch
- Focus on proper memory management (avoid memory leaks)
- Understand when to use each type of linked list
- Practice debugging pointer-related issues

Ready for **Phase 3: Stacks and Queues**?