struct DoublyNode {
    int data;
    DoublyNode*next;
    DoublyNode*prev;

    DoublyNode(int val):next(nullptr), prev(nullptr), data(val){};
};


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