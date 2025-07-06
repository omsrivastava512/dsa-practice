#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

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
    size_t size;

    void insertInitialNode(int data){
        if(size!=0) return;
        DoublyNode *newNode = new DoublyNode(data);
        head = newNode;
        tail = newNode;
        size++;
        return;
    }
    

    void insertAfterNode(DoublyNode*prev, int data){
        if(!prev) return;

        DoublyNode *newNode = new DoublyNode(data);
        newNode->prev = prev;
        newNode->next = prev->next;
        prev->next = newNode;
        ++size;

        if(tail==prev) tail = newNode;
    }
    void insertBeforeNode(DoublyNode*next, int data){
        if(!next) return;

        DoublyNode *newNode = new DoublyNode(data);
        newNode->next = next;
        newNode->prev = next->prev;
        next->prev = newNode;
        size++;

        if(head==next) head = newNode;
    }
    
    /**
     * Checks whether the postition is non-negative and less than size of the list.
     * The check-range is exclusive of size and thus any attempts to insert at the 
     * end must be catered seperately before validating using this function.
     */
    bool validatePosition(int pos)const{
        return !(pos<0  || pos>=static_cast<int>(size)); 
    }

public:
    DoublyLinkedList():head(nullptr), tail(nullptr), size(0){}
    ~DoublyLinkedList(){
        // clear();
    }
    
    // Operations to implement:
    void insertAtBeginning(int data){
        if(size==0) return insertInitialNode(data);
        insertBeforeNode(head, data);
    }

    void insertAtEnd(int data){
        if(size==0) return insertInitialNode(data);
        insertAfterNode(tail, data);        
    }

    void insertAtPosition(int data, int pos){
        if(pos==0) return insertAtBeginning(data);
        if(pos==static_cast<int>(size)) return insertAtEnd(data);
        
        if(!validatePosition(pos)) return;

        if(pos>static_cast<int>(size/2)){     // closer to the tail
            DoublyNode *curr = tail;
            for(int i = size-2; i>pos; i-- ) curr = curr->prev;
            
            return insertBeforeNode(curr, data);
        }
        else{
            DoublyNode * curr = head;
            for(int i = 1; i<pos; i++) curr=curr->next; 
            return insertAfterNode(curr, data);
        }
    }
    
  
    
};
