#include <iostream>
using namespace std;
// Node for stack
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node*next) : data(val), next(next) {}
};

class LinkedStack {
private:
    Node* top;
    int count;

    
public:
    LinkedStack(): top(nullptr), count(0){}
    ~LinkedStack(){
        clear();
    }
    
    // Basic operations:
    void push(int data){
        if(!top){
            top = new Node(data);
        }
        else {
            top = new Node(data, top);
        }
        count++;
    }
    int pop(){
        if(!top){
            cout<<"Underflow";
            return INT16_MIN;
        }
        int data = top->data;
        Node * currentTop = top;
        top = top->next;
        delete currentTop;
        count--;
        return data;
    }
    int peek()const{
        if(!top){
            cout<<"Underflow";
            return INT16_MIN;
        }
        return top->data;
    }
    bool isEmpty()const{ return top == nullptr;}
    int size()const {return count;}

    void display()const{
        if(!top){
            cout<<"Stack Empty"<<endl;
            return;
        }
        Node*curr = top;
        while (curr)
        {
            cout<<curr->data<<" ";
        }
        cout<<endl;
    }
    void clear(){
        while (!isEmpty())
        {
            pop();
        }
    }
    
    // Advanced operations:
    void reverse();
    LinkedStack* merge(LinkedStack& other);
    bool isEqual(LinkedStack& other);
    void removeDuplicates();
    int findMax();
    int findMin();
};