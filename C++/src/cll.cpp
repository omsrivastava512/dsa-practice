#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int val):data(val), next(nullptr){};
};

class CircularLinkedList {
    private:
    Node* last; // Points to last node
    int size;
    
    /**
     * Checks whether the postition is non-negative and less than size of the list.
     * The check-range is exclusive of size and thus any attempts to insert initial node and 
     * insert at the end must be catered seperately before validating using this function.
     */
    bool validatePosition(int pos)const{
        return !(pos<0  || pos>=size); 
    }

    void insertInitialNode(int data){
        if(size!=0) return;
        Node * node = new Node(data);
        last = node;
        node->next=node;
        size++;
    }
     

    void deleteFinalNode(){
        if(size!=1) return;
        delete last;
        last = nullptr;
        size = 0;
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
        return insertAfterNode(last, data, true);
    }

    void insertAtPosition(int data, int pos){
        if(pos==0) return insertAtBeginning(data);
        if(pos==size) return insertAtEnd(data);

        if (!validatePosition(pos)) return;
        
        Node*curr = last->next;
        for(int i = 1; i<pos; i++ ) curr = curr->next;
        insertAfterNode(curr, data);
    }
    
    void deleteAfterNode(Node*prev){
        if(!prev) return;

        if(size==1) return deleteFinalNode();

        Node*temp = prev->next;
        prev->next = temp->next;
        if(temp==last) last = prev; 
        delete temp;
        size--;
    }
    
  
    void deleteFromBeginning(){
        deleteAfterNode(last);
    }

    void deleteFromEnd(){
        if(size==0) return;
        if(size==1) return deleteFinalNode();
        
        Node*curr = last->next;
        while(curr->next!=last) curr = curr->next;
        deleteAfterNode(curr);
    }

    void deleteByValue(int data){
        if(size==0) return;

        Node*curr = last;
        for(int i = 0; i<size; i++){
            if(curr->next->data==data) return deleteAfterNode(curr);
            curr=curr->next;
        }
        cout<<"Data does not exist in the list.";
    }
    
    void display()const{
        if(size==0){
            cout<<"List is empty.";
            return;
        } 

        Node*curr = last->next;
        for(int i = 0; i<size; i++){
            cout<<curr->data;
            if(curr!=last) cout<<" -> ";
        }
        cout<<endl;
            
        
    }

    Node* searchNode(int data)const{
        if(size==0) return nullptr;

        Node*curr = last;
        for(int i = 0; i<size; i++){
            if(curr->next->data==data) return (curr);
            curr=curr->next;
        }
        return nullptr;
    }

    int getSize()const{return size;}
    

    void clear(){
        while(size>0) deleteAfterNode(last);
    }
    
     
    bool isCircular(){
        if(size == 0) return true;

        Node* curr = last->next;
        for (int i = 0; i < size; i++) {
            curr = curr->next;
        }
        return curr == last->next; // Should return to start        
    }
};
