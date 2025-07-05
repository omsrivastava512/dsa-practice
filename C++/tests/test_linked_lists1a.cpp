/************************************************************
 *  Rigorous test-suite for SinglyLinkedList
 ***********************************************************/
#include <iostream>
#include <sstream>
#include <functional> 
#include <cassert>
#include <vector>
#include <stdexcept>

using namespace std;

/* --------------  ORIGINAL CLASS DEFINITION  -------------- */
struct Node {
    int data;
    Node* next;
    explicit Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node *head, *tail;
    size_t size;

    bool validatePosition(int pos) const {
        if (pos < 0 || pos >= static_cast<int>(size)) {
            cout << "Invalid position input." << endl;
            return false;
        }
        return true;
    }
    void printEmptyMessage() const { cout << "List is empty!" << endl; }
    void deleteNextNode(Node* prev) {
        if (!prev || !prev->next) return;
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        if (toDelete == tail) tail = prev;
        delete toDelete;
        --size;
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~SinglyLinkedList() { clear(); }

    bool isEmpty() const { return size == 0; }

    Node* getNodeAt(int pos) const {
        if (!validatePosition(pos)) return nullptr;
        Node* curr = head;
        for (int i = 0; i < pos; ++i) curr = curr->next;
        return curr;
    }

    /* ---------  Insertions  --------- */
    void insertAtStart(int data) {
        Node* n = new Node(data);
        n->next = head;
        head = n;
        if (!tail) tail = n;
        ++size;
    }
    void insertAtEnd(int data) {
        Node* n = new Node(data);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
        ++size;
    }
    void insertAtPosition(int data, int pos) {
        if (pos == 0) { insertAtStart(data); return; }
        if (pos == static_cast<int>(size)) { insertAtEnd(data); return; }
        Node* prev = getNodeAt(pos - 1);
        if (!prev) return;
        Node* n = new Node(data);
        n->next = prev->next;
        prev->next = n;
        ++size;
    }

    /* ---------  Deletions  --------- */
    void deleteFromStart() {
        if (isEmpty()) { printEmptyMessage(); return; }
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
        if (!head) tail = nullptr;
    }
    void deleteFromEnd() {
        if (isEmpty()) { printEmptyMessage(); return; }
        if (size == 1) { delete head; head = tail = nullptr; --size; return; }
        Node* prev = getNodeAt(size - 2);
        delete tail;
        tail = prev;
        tail->next = nullptr;
        --size;
    }
    void deleteAtPosition(int pos) {
        if (isEmpty()) { printEmptyMessage(); return; }
        if (pos == 0) { deleteFromStart(); return; }
        if (pos == static_cast<int>(size) - 1) { deleteFromEnd(); return; }
        Node* prev = getNodeAt(pos - 1);
        deleteNextNode(prev);
    }
    void deleteByValue(int data) {
        if (isEmpty()) { printEmptyMessage(); return; }
        if (head->data == data) { deleteFromStart(); return; }
        for (Node* curr = head; curr->next; curr = curr->next) {
            if (curr->next->data == data) { deleteNextNode(curr); return; }
        }
        cout << "No match found" << endl;
    }

    /* ---------  Utilities  --------- */
    int findPosition(int data) const {
        Node* curr = head;
        int idx = 0;
        while (curr) {
            if (curr->data == data) return idx;
            curr = curr->next;
            ++idx;
        }
        return -1;
    }
    bool contains(int data) const { return findPosition(data) != -1; }
    size_t getSize() const { return size; }

    void display() const {
        if (isEmpty()) { printEmptyMessage(); return; }
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            if (curr->next) cout << " -> ";
            curr = curr->next;
        }
        cout << endl;
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = tail = nullptr;
        size = 0;
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
            Node*curr2 = curr;
            while(curr2->next){
                if(curr->data == curr2->next->data) deleteNextNode(curr2);
                else curr2 = curr2->next;
            }
            curr = curr->next;
        }
    }

    static Node* reverseIterativeUsingNewNode(Node*head, Node*tail){
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
        return head;

    }
    static Node* reverseIterative(Node * head, Node*tail){
        Node * newHead = tail;   // last node becomes new head
        tail = head;    // first node becomes tail
        Node * curr = head;
        while(curr!=newHead){  
            Node * reversedNextNode = newHead->next;
            newHead->next = curr;   
            Node * nextNode = curr->next; 
            curr->next = reversedNextNode;

            curr = nextNode;
        } 
        return head = newHead;
    }

    // Node* reverseRecursive(Node* head)


    /* ----------  Helper for tests  ---------- */
    string toString() const {
        ostringstream oss;
        Node* curr = head;
        while (curr) {
            oss << curr->data;
            if (curr->next) oss << " -> ";
            curr = curr->next;
        }
        return oss.str();
    }
};

/* --------------  TEST FRAMEWORK  -------------- */
int tests_run = 0;
int tests_pass = 0;

#define EXPECT_EQ(a, b) \
    do { \
        ++tests_run; \
        if ((a) == (b)) { ++tests_pass; } \
        else { cerr << "FAIL in " << __LINE__ << ": " << (a) << " != " << (b) << '\n'; } \
    } while (0)

#define EXPECT_TRUE(cond)  EXPECT_EQ(!!(cond), true)
#define EXPECT_FALSE(cond) EXPECT_EQ(!!(cond), false)

void test_insert_empty() {
    SinglyLinkedList ll;
    ll.insertAtStart(7);
    EXPECT_EQ(ll.toString(), "7");
    EXPECT_EQ(ll.getSize(), 1u);
}

void test_insert_end_empty() {
    SinglyLinkedList ll;
    ll.insertAtEnd(99);
    EXPECT_EQ(ll.toString(), "99");
    EXPECT_EQ(ll.getSize(), 1u);
}

void test_insert_bad_pos() {
    SinglyLinkedList ll;
    ll.insertAtPosition(5, -3);  // silent fail
    ll.insertAtPosition(5, 1);   // silent fail
    EXPECT_TRUE(ll.isEmpty());
}

void test_insert_middle() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    ll.insertAtPosition(42, 3);
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3 -> 42 -> 4 -> 5");
}

void test_insert_at_size() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    ll.insertAtPosition(99, 5);
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3 -> 4 -> 5 -> 99");
}

void test_delete_empty() {
    SinglyLinkedList ll;
    ll.deleteFromStart();
    ll.deleteFromEnd();
    ll.deleteAtPosition(0);
    ll.deleteByValue(10);
    EXPECT_TRUE(ll.isEmpty());
}

void test_delete_single_start() {
    SinglyLinkedList ll;
    ll.insertAtStart(42);
    ll.deleteFromStart();
    EXPECT_TRUE(ll.isEmpty());
}

void test_delete_single_end() {
    SinglyLinkedList ll;
    ll.insertAtStart(42);
    ll.deleteFromEnd();
    EXPECT_TRUE(ll.isEmpty());
}

void test_delete_single_pos() {
    SinglyLinkedList ll;
    ll.insertAtStart(42);
    ll.deleteAtPosition(0);
    EXPECT_TRUE(ll.isEmpty());
}

void test_delete_single_value() {
    SinglyLinkedList ll;
    ll.insertAtStart(42);
    ll.deleteByValue(42);
    EXPECT_TRUE(ll.isEmpty());
}

void test_delete_last_end() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 3; ++i) ll.insertAtEnd(i);
    ll.deleteFromEnd();
    EXPECT_EQ(ll.toString(), "1 -> 2");
}

void test_delete_by_value_not_found() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 3; ++i) ll.insertAtEnd(i);
    ll.deleteByValue(99);  // prints "No match found"
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3");
}

void test_delete_middle_pos() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    ll.deleteAtPosition(2);
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 4 -> 5");
}

void test_contains_find() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    EXPECT_TRUE(ll.contains(3));
    EXPECT_EQ(ll.findPosition(3), 2);
    EXPECT_FALSE(ll.contains(42));
    EXPECT_EQ(ll.findPosition(42), -1);
}

void test_clear() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 100; ++i) ll.insertAtEnd(i);
    ll.clear();
    EXPECT_TRUE(ll.isEmpty());
    EXPECT_EQ(ll.getSize(), 0u);
}

void test_large_insert_delete() {
    SinglyLinkedList ll;
    const int N = 10000;
    for (int i = 0; i < N; ++i) ll.insertAtEnd(i);
    EXPECT_EQ(ll.getSize(), static_cast<size_t>(N));
    for (int i = 0; i < N; ++i) ll.deleteFromStart();
    EXPECT_TRUE(ll.isEmpty());
}

/* --------------  RUNNER  -------------- */
int main() {
    test_insert_empty();
    test_insert_end_empty();
    test_insert_bad_pos();
    test_insert_middle();
    test_insert_at_size();
    test_delete_empty();
    test_delete_single_start();
    test_delete_single_end();
    test_delete_single_pos();
    test_delete_single_value();
    test_delete_last_end();
    test_delete_by_value_not_found();
    test_delete_middle_pos();
    test_contains_find();
    test_clear();
    test_large_insert_delete();

    cout << "========================================\n";
    cout << "Tests run : " << tests_run << "\n";
    cout << "Tests pass: " << tests_pass << "\n";
    if (tests_pass == tests_run) cout << "ALL TESTS PASSED\n";
    else                         cout << "SOME TESTS FAILED\n";
    return 0;
}   


void test_remove_duplicates_sorted_empty() {
    SinglyLinkedList ll;
    ll.removeDuplicatesSorted();
    EXPECT_TRUE(ll.isEmpty());
}

void test_remove_duplicates_sorted_single() {
    SinglyLinkedList ll;
    ll.insertAtEnd(42);
    ll.removeDuplicatesSorted();
    EXPECT_EQ(ll.toString(), "42");
    EXPECT_EQ(ll.getSize(), 1u);
}

void test_remove_duplicates_sorted_no_duplicates() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    ll.removeDuplicatesSorted();
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3 -> 4 -> 5");
    EXPECT_EQ(ll.getSize(), 5u);
}

void test_remove_duplicates_sorted_all_same() {
    SinglyLinkedList ll;
    for (int i = 0; i < 5; ++i) ll.insertAtEnd(7);
    ll.removeDuplicatesSorted();
    EXPECT_EQ(ll.toString(), "7");
    EXPECT_EQ(ll.getSize(), 1u);
}

void test_remove_duplicates_sorted_consecutive() {
    SinglyLinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(1);
    ll.insertAtEnd(2);
    ll.insertAtEnd(2);
    ll.insertAtEnd(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(4);
    ll.removeDuplicatesSorted();
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3 -> 4");
    EXPECT_EQ(ll.getSize(), 4u);
}

void test_remove_duplicates_unsorted_empty() {
    SinglyLinkedList ll;
    ll.removeDuplicatesUnsorted();
    EXPECT_TRUE(ll.isEmpty());
}

void test_remove_duplicates_unsorted_single() {
    SinglyLinkedList ll;
    ll.insertAtEnd(42);
    ll.removeDuplicatesUnsorted();
    EXPECT_EQ(ll.toString(), "42");
    EXPECT_EQ(ll.getSize(), 1u);
}

void test_remove_duplicates_unsorted_no_duplicates() {
    SinglyLinkedList ll;
    for (int i = 1; i <= 5; ++i) ll.insertAtEnd(i);
    ll.removeDuplicatesUnsorted();
    EXPECT_EQ(ll.toString(), "1 -> 2 -> 3 -> 4 -> 5");
    EXPECT_EQ(ll.getSize(), 5u);
}

void test_remove_duplicates_unsorted_scattered() {
    SinglyLinkedList ll;
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(2);
    ll.insertAtEnd(1);
    ll.insertAtEnd(3);
    ll.insertAtEnd(2);
    ll.removeDuplicatesUnsorted();
    EXPECT_EQ(ll.toString(), "1 -> 3 -> 2");
    EXPECT_EQ(ll.getSize(), 3u);
}

void test_remove_duplicates_unsorted_all_same() {
    SinglyLinkedList ll;
    for (int i = 0; i < 5; ++i) ll.insertAtEnd(7);
    ll.removeDuplicatesUnsorted();
    EXPECT_EQ(ll.toString(), "7");
    EXPECT_EQ(ll.getSize(), 1u);
}
