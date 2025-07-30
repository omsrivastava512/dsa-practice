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