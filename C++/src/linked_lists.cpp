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
    void deleteNextNode(Node* prev){
        if(!prev || !prev->next) return;    // nullchecking
        Node * nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;

        // Update tail if we're deleting the last node
        if(nodeToDelete == tail){   
            tail = prev; // prev node becomes tail node
        }
        delete nodeToDelete;
        size--;
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
    void deleteFromStart(){
        if(isEmpty()) {
            printEmptyMessage();
            return;
        }
        Node * temp = head;
        head = head->next;
        delete temp;
        size--;

        if(size==0) tail = nullptr;

        return;
    }
    void deleteFromEnd(){
        if(isEmpty()) {
            printEmptyMessage();
            return;
        }
        if(size==1){
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }
        delete tail;
        Node * prevToLast = getNodeAt(size-2);
        prevToLast->next =  nullptr;
        tail = prevToLast;
        size--;
    }

    void deleteByValue(int data){
        if(isEmpty()) {
            printEmptyMessage();
            return;
        }
        if(head->data == data){     // if data found on 1st node
            deleteFromStart();
            return;
        }
        Node * curr = head; 
        // Checking if the next node has matching data
        while(curr->next){   // traverse until last node
            if(curr->next->data == data){
                deleteNextNode(curr);  
                return;
            }
            curr = curr->next;
        }
        cout<<"No match found"<<endl;
    } 
    void deleteAtPosition(int pos){
        if(isEmpty()) {
            printEmptyMessage();
            return;
        }
        if(pos==0){
            deleteFromStart();
            return;
        }        
        if(pos==static_cast<int>(size)-1){
            deleteFromEnd();
            return;
        }
        Node * prev = getNodeAt(pos-1);
        deleteNextNode(prev);  
    }

    int findPosition(int data)const{
        Node * curr = head;
        int pos = 0;

        while(curr){
            if(curr->data==data) return pos;
            curr=curr->next;
            pos++;
        }
        return -1;
    }

    bool contains(int data)const{
        return findPosition(data)!=-1;
    }

    void display()const{

        if(isEmpty()){
            printEmptyMessage();
            return;
        }
        Node * curr =  head;
        while(curr){
            cout<<curr->data;
            if(curr->next) cout<<" -> ";
            curr = curr->next;
        }
        cout<<endl;
    }

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

    void removeDuplicatesSorted(){
        Node * curr = head;
        while(curr && curr->next){
            if(curr->data==curr->next->data){
                deleteNextNode(curr);
            }
            else curr= curr->next;
        }
    }   
    void removeDuplicatesUnsorted(){
        Node*curr = head;
        while(curr && curr->next){
            Node*runner = curr;
            while(runner->next){
                if(curr->data == runner->next->data) deleteNextNode(runner);
                else runner = runner->next;
            }
            curr = curr->next;
        }
    }

    void reverseIterativeUsingNewNode(){
      

        Node * curr = head;
        Node * newHead = tail;   // last node
        tail = head;    // first node becomes last
        while(curr!=newHead){  
            Node * newNode = new Node(curr->data);
            newNode->next = newHead->next;
            newHead->next = newNode;
            Node * temp = curr; 
            curr = curr->next;
            delete temp;
        } 

        head = newHead;

    }
  void reverseIterative(){
        Node * newHead = tail;   
        Node * curr = head;
       while(curr!=newHead){  
            Node *next = curr->next;
            curr->next = newHead->next;
            newHead->next = curr;
            curr = next;
        } 
        tail = head;    // first node becomes tail
        head = newHead;
    }

    // Node* reverseRecursive(Node* head)


};


// int main(){
//     SinglyLinkedList list;
//     list.insertAtEnd(10);
//     list.insertAtEnd(10);
//     list.insertAtEnd(20);
//     list.insertAtEnd(20); 
//     list.insertAtEnd(20);
//     list.insertAtEnd(30);
//     list.insertAtEnd(30);
//     list.insertAtEnd(40);
//     list.insertAtEnd(40);
//     list.insertAtEnd(50);
//     list.insertAtEnd(50);
//     list.insertAtEnd(50);
//     list.insertAtEnd(50);
//     list.display();
    
//     list.reverseIterative();
//     list.removeDuplicatesUnsorted();
//     list.display();
//     return 0;
// }


