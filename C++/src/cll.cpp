struct Node{
    int data;
    Node *next;
    Node(int val):data(val), next(nullptr){};
};

class CircularLinkedList {
    private:
    Node* last; // Points to last node
    int size;
    void insertInitialNode(int data){
        if(size!=0) return;
        Node * node = new Node(data);
        last = node;
        node->next=node;
        size++;
    }

public:
    CircularLinkedList():last(nullptr), size(0){};
    ~CircularLinkedList(){
        clear();
    }
    
    // Operations to implement:
    void insertAfterNode(Node*prev, int data, bool isLast=false){
        if(!prev) return;

        Node *node = new Node(data);
        node->next = prev->next;
        prev->next = node;
        if(isLast) last = node;
        ++size;
    }


    void insertAtBeginning(int data){
        if(size==0) return insertInitialNode(data);

        return insertAfterNode(last, data);
    }

    void insertAtEnd(int data){
        if (size==0) return insertInitialNode(data);

        return insertAfterNode(last, data, true);
    }

    void insertAtPosition(int data, int pos){
        
    }
    
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteByValue(int data);
    
    void display()const;
    Node* searchNode(int data)const;
    int getSize()const;
    

    void clear();
    
    // Special operations:
    void splitIntoTwo(CircularLinkedList& list1, CircularLinkedList& list2);
    bool isCircular();
};
