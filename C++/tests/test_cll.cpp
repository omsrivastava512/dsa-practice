#include <iostream>
#include <cassert>
#include "../src/cll.cpp"
using namespace std;

void testConstructorAndSize() {
    CircularLinkedList cll;
    assert(cll.getSize() == 0);
    cout << "Constructor and size test passed." << endl;
}

void testInsertAtBeginning() {
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    assert(cll.getSize() == 1);
    
    cll.insertAtBeginning(20);
    assert(cll.getSize() == 2);
    cout << "Insert at beginning test passed." << endl;
}

void testInsertAtEnd() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    assert(cll.getSize() == 3);
    cout << "Insert at end test passed." << endl;
}

void testInsertAtPosition() {
    CircularLinkedList cll;
    cll.insertAtPosition(10, 0);
    cll.insertAtPosition(30, 1);
    cll.insertAtPosition(20, 1);
    assert(cll.getSize() == 3);
    cout << "Insert at position test passed." << endl;
}

void testDeleteFromBeginning() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.deleteFromBeginning();
    assert(cll.getSize() == 1);
    cout << "Delete from beginning test passed." << endl;
}

void testDeleteFromEnd() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.deleteFromEnd();
    assert(cll.getSize() == 1);
    cout << "Delete from end test passed." << endl;
}

void testDeleteByValue() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.deleteByValue(20);
    assert(cll.getSize() == 2);
    cout << "Delete by value test passed." << endl;
}

void testSearchNode() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    Node* found = cll.searchNode(20);
    assert(found != nullptr);
    
    Node* notFound = cll.searchNode(99);
    assert(notFound == nullptr);
    cout << "Search node test passed." << endl;
}

void testIsCircular() {
    CircularLinkedList cll;
    assert(cll.isCircular() == true);
    
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    assert(cll.isCircular() == true);
    cout << "Is circular test passed." << endl;
}

void testClear() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.clear();
    assert(cll.getSize() == 0);
    cout << "Clear test passed." << endl;
}

void testDisplay() {
    CircularLinkedList cll;
    cout << "Empty list display: ";
    cll.display();
    
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cout << "Non-empty list display: ";
    cll.display();
}

int main() {
    testConstructorAndSize();
    testInsertAtBeginning();
    testInsertAtEnd();
    testInsertAtPosition();
    testDeleteFromBeginning();
    testDeleteFromEnd();
    testDeleteByValue();
    testSearchNode();
    testIsCircular();
    testClear();
    testDisplay();
    
    cout << "All tests passed!" << endl;
    return 0;
}