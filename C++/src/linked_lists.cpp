#include <iostream>

using namespace std;


struct Node{
    int data;
    Node * next;

    explicit Node(int val):data(val), next(nullptr) {}
};


class SinglyLinkedList{
    private:
    Node * head;
    Node * tail;
    size_t size; 

    Node* createNode(int data) {
        try {
            return new Node(data);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation failed: " << e.what() << std::endl;
            return nullptr;
        }
    }
    
    /**
     * @param int pos - postion you you want to validate for your operation
     * @param char op - operation you want to perform [i|d]
     */
    bool validatePosition(int pos)const{
        if(pos < 0 || pos>=static_cast<int>(size)){
            cout<<"Invalid position input."<<endl;
            return false;
        }
        return true;
    }

    bool isEmpty() const{
        bool isEmpty = size==0;
        return isEmpty;
    }
    void printEmptyMessage() const {
        cout << "List is empty!" << endl;
    }
   
    
    public:
    // constructor
    SinglyLinkedList(): head(nullptr), tail(nullptr), size(0){} 
    // destructor
    ~SinglyLinkedList(){
       clear();
    }
    Node * getHead(){
        return head;
    }
    Node* getTail(){
        return tail;
    }
    Node * getNodeAt(int pos)const{
        if(!validatePosition(pos)){
            return nullptr;
        }
        Node * curr = head;
        for(int i = 0; i<pos; i++){     
            curr = curr->next;
        }
        return curr;
    }

    // Insertions
    void insertAtStart(int data){
        Node* newNode = createNode(data);  // new returns a pointer
        newNode->next = head;
        head = newNode;

        if(tail==nullptr){  // First node
            tail = newNode;
        }
        ++size;
    }

    void insertAtEnd(int data){
        Node * newNode = createNode(data);
        if(!head){   // Empty List Case
            head = tail =  newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAtPosition(int data, int pos){
        if(pos == 0){   // Insert at beginning
            insertAtStart(data);
            return;
        }
        if(pos==static_cast<int>(size)){
            insertAtEnd(data);
            return;
        }
        
        Node  * newNode = createNode(data);
        Node * prev = getNodeAt(pos-1); // the node prev to the current node at the position
        newNode->next = prev->next;
        prev->next = newNode;
    
        size++;
    }


    // Deletion
    

    size_t getSize()const {return size;}

    void clear(){
        if(isEmpty()){
            printEmptyMessage();
            return;
        }
        Node* curr = head;
        while(curr){
            Node * next = curr->next;
            delete curr;
            curr = next;
            size--;
        } 

        head = nullptr;
        size=0;       
    }

   
    // Node* reverseRecursive(Node* head)


};


int main(){
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(20); 
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(50);
    list.insertAtEnd(50);
    list.insertAtEnd(50);
   
    return 0;
}


