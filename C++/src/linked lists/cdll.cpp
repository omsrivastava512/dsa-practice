struct DoublyNode {
    int data;
    DoublyNode*next;
    DoublyNode*prev;

    DoublyNode(int val):next(nullptr), prev(nullptr), data(val){};
    DoublyNode(int val, DoublyNode* next, DoublyNode* prev):next(next), prev(prev), data(val){};
};

class CircularDoublyLinkedList {
private:
    DoublyNode* head;
    int size;

    void insertInitialNode(int data){
        if(head || size>0) return;

        DoublyNode*node = new DoublyNode(data);
        node->next = node;
        node->prev = node;
        head = node;
        size = 1;
    }

    void insertAfterNode(DoublyNode *prev, int data, bool isHead){      // ⚠️ Do not make make the boolean arugment defaulted
        if(!prev) return; 
        DoublyNode * node = new DoublyNode(data, prev->next, prev);
        prev->next->prev = node;
        prev->next = node;

        if(isHead) head = node; 
    }
    
public:
    CircularDoublyLinkedList():head(nullptr), size(0){};

    void insertAfterNode(DoublyNode *prev, int data){       // wrapper function to avoid publicly changing the `head`;
       insertAfterNode(prev, data, false);
    }

    // All basic operations
    void insertAtBeginning1(int data){
        DoublyNode *node = new DoublyNode(data);
        if (size==0 || head==nullptr){
            head = node;
            node->next = node;
            node->prev = node;
            size = 1;
            return;
        }   
        node->next = head;          // head node becomes next of new node
        node->prev = head->prev;    // tail node becomes prev of new node

        head->prev->next = node;    // new node becomes `updated next` of tail node
        head->prev = node;          // new node becomes `updated prev` of head node
        head = node;                // head updates to new node
        size++;
    }
    void insertAtBeginning2(int data){
        if (head==nullptr) {
            DoublyNode *node = new DoublyNode(data);
            head = node; 
            node->next = node; 
            node->prev = node;
            size = 1;
            return;           
        }
        DoublyNode *node = new DoublyNode(data, head, head->prev);
        head->prev->next = node;
        head->prev = node;
        head = node;
        size++;
    }

    void insertAtBeginning3(int data){
        if(size==0) insertInitialNode(data);
        else insertAfterNode(head->prev, data, true);
    }

    void insertAtEnd(int data){
        if(size == 0) insertInitialNode(data);
        else insertAfterNode(head->prev, data);
    }

    void deleteFromBeginning();
    void deleteFromEnd();
    void displayForward();
    void displayBackward();
    
    // Advanced operations:
    void reverseCircularDLL();
    DoublyNode* sortCircularDLL();
    void convertToLinear(); // Remove circular property
};