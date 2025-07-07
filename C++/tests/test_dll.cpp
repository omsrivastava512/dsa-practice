#include <iostream>
#include <cassert>
#include <sstream>
#include <functional> 
#include "../dll.cpp"


using namespace std;

// Helper function to capture cout output
string captureOutput(function<void()> func) {
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(old);
    return buffer.str();
}

void testConstructorAndSize() {
    DoublyLinkedList dll;
    assert(dll.getSize() == 0);
    cout << "Constructor and getSize test passed" << endl;
}

void testInsertAtBeginning() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(30);
    
    assert(dll.getSize() == 3);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 30 <-> 20 <-> 10\n");
    
    cout << "Insert at beginning test passed" << endl;
}

void testInsertAtEnd() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    assert(dll.getSize() == 3);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 20 <-> 30\n");
    
    cout << "Insert at end test passed" << endl;
}

void testInsertAtPosition() {
    DoublyLinkedList dll;
    dll.insertAtPosition(10, 0);  // Insert at beginning
    dll.insertAtPosition(30, 1);  // Insert at end
    dll.insertAtPosition(20, 1);  // Insert in middle
    
    assert(dll.getSize() == 3);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 20 <-> 30\n");
    
    cout << "Insert at position test passed" << endl;
}

void testDisplayBackward() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    string output = captureOutput([&]() { dll.displayBackward(); });
    assert(output == "Backward: 30 <-> 20 <-> 10\n");
    
    cout << "Display backward test passed" << endl;
}

void testDeleteFromBeginning() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    dll.deleteFromBeginning();
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 20 <-> 30\n");
    
    cout << "Delete from beginning test passed" << endl;
}

void testDeleteFromEnd() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    dll.deleteFromEnd();
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 20\n");
    
    cout << "Delete from end test passed" << endl;
}

void testDeleteAtPosition() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    dll.deleteAtPosition(1);  // Delete middle element
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 30\n");
    
    cout << "Delete at position test passed" << endl;
}

void testDeleteByValue() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    dll.deleteByValue(20);
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 30\n");
    
    cout << "Delete by value test passed" << endl;
}

void testSearchNode() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    DoublyNode* node = dll.searchNode(20);
    assert(node != nullptr);
    assert(node->data == 20);
    
    DoublyNode* notFound = dll.searchNode(99);
    assert(notFound == nullptr);
    
    cout << "Search node test passed" << endl;
}

void testGetNode() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    DoublyNode* node = dll.getNode(1);
    assert(node != nullptr);
    assert(node->data == 20);
    
    DoublyNode* invalid = dll.getNode(-1);
    assert(invalid == nullptr);
    
    cout << "Get node test passed" << endl;
}

void testClear() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    dll.clear();
    assert(dll.getSize() == 0);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "List is empty\n");
    
    cout << "Clear test passed" << endl;
}

void testEmptyListOperations() {
    DoublyLinkedList dll;
    
    // Test operations on empty list
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    dll.deleteAtPosition(0);
    
    assert(dll.getSize() == 0);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "List is empty\n");
    
    cout << "Empty list operations test passed" << endl;
}

void testSingleElementOperations() {
    DoublyLinkedList dll;
    dll.insertAtEnd(42);
    
    assert(dll.getSize() == 1);
    
    // Test forward and backward display with single element
    string forward = captureOutput([&]() { dll.displayForward(); });
    assert(forward == "Forward: 42\n");
    
    string backward = captureOutput([&]() { dll.displayBackward(); });
    assert(backward == "Backward: 42\n");
    
    // Test search and get operations
    assert(dll.searchNode(42) != nullptr);
    assert(dll.getNode(0) != nullptr);
    assert(dll.getNode(0)->data == 42);
    
    // Delete the single element
    dll.deleteFromBeginning();
    assert(dll.getSize() == 0);
    
    cout << "Single element operations test passed" << endl;
}

void testInsertAtPositionEdgeCases() {
    DoublyLinkedList dll;
    
    // Insert at position 0 in empty list
    dll.insertAtPosition(10, 0);
    assert(dll.getSize() == 1);
    
    // Insert at end position
    dll.insertAtPosition(20, 1);
    assert(dll.getSize() == 2);
    
    // Insert beyond valid range (should be ignored)
    dll.insertAtPosition(99, 10);
    assert(dll.getSize() == 2);
    
    // Insert at negative position (should be ignored)
    dll.insertAtPosition(99, -1);
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 20\n");
    
    cout << "Insert at position edge cases test passed" << endl;
}

void testDeleteAtPositionEdgeCases() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    // Delete at invalid negative position
    dll.deleteAtPosition(-1);
    assert(dll.getSize() == 3);
    
    // Delete at position beyond size
    dll.deleteAtPosition(5);
    assert(dll.getSize() == 3);
    
    // Delete at boundary positions
    dll.deleteAtPosition(0);  // Delete first
    assert(dll.getSize() == 2);
    
    dll.deleteAtPosition(1);  // Delete last (now at position 1)
    assert(dll.getSize() == 1);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 20\n");
    
    cout << "Delete at position edge cases test passed" << endl;
}

void testDeleteByValueEdgeCases() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(20);  // Duplicate value

    
    // Delete first occurrence of duplicate value
    dll.deleteByValue(20);
    assert(dll.getSize() == 3);

    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 10 <-> 30 <-> 20\n");
    
    
    // Try to delete non-existent value
    dll.deleteByValue(99);
    assert(dll.getSize() == 3);
    
    cout << "Delete by value edge cases test passed" << endl;
}

void testLargeListOperations() {
    DoublyLinkedList dll;
    const int size = 1000;
    
    // Insert large number of elements
    for (int i = 0; i < size; ++i) {
        dll.insertAtEnd(i);
    }
    assert(dll.getSize() == size);
    
    // Test getNode optimization (closer to tail)
    DoublyNode* node = dll.getNode(800);
    assert(node != nullptr);
    assert(node->data == 800);
    
    // Test getNode optimization (closer to head)
    node = dll.getNode(200);
    assert(node != nullptr);
    assert(node->data == 200);
    
    // Test insertAtPosition in middle of large list
    dll.insertAtPosition(9999, 500);
    assert(dll.getSize() == size + 1);
    assert(dll.getNode(500)->data == 9999);
    
    cout << "Large list operations test passed" << endl;
}

void testDestructorAndMemoryManagement() {
    {
        DoublyLinkedList dll;
        for (int i = 0; i < 100; ++i) {
            dll.insertAtEnd(i);
        }
        // Destructor should be called automatically when dll goes out of scope
    }
    
    // Create another list to ensure no memory issues
    DoublyLinkedList dll2;
    dll2.insertAtEnd(42);
    assert(dll2.getSize() == 1);
    
    cout << "Destructor and memory management test passed" << endl;
}

void testMultipleClearOperations() {
    DoublyLinkedList dll;
    
    // Clear empty list
    dll.clear();
    assert(dll.getSize() == 0);
    
    // Add elements and clear
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.clear();
    assert(dll.getSize() == 0);
    
    // Add elements again after clear
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 30 <-> 40\n");
    
    cout << "Multiple clear operations test passed" << endl;
}

void testSearchNodeEdgeCases() {
    DoublyLinkedList dll;
    
    // Search in empty list
    assert(dll.searchNode(10) == nullptr);
    
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    
    // Search for first element
    DoublyNode* node = dll.searchNode(10);
    assert(node != nullptr);
    assert(node->data == 10);
    assert(node->prev == nullptr);
    
    // Search for last element
    node = dll.searchNode(30);
    assert(node != nullptr);
    assert(node->data == 30);
    assert(node->next == nullptr);
    
    // Search for non-existent element
    assert(dll.searchNode(99) == nullptr);
    
    cout << "Search node edge cases test passed" << endl;
}

void testGetNodeEdgeCases() {
    DoublyLinkedList dll;
    
    // Get node from empty list
    assert(dll.getNode(0) == nullptr);
    
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtEnd(40);
    dll.insertAtEnd(50);
    
    // Test boundary positions
    DoublyNode* first = dll.getNode(0);
    assert(first != nullptr);
    assert(first->data == 10);
    
    DoublyNode* last = dll.getNode(4);
    assert(last != nullptr);
    assert(last->data == 50);
    
    // Test invalid positions
    assert(dll.getNode(-1) == nullptr);
    assert(dll.getNode(5) == nullptr);
    
    cout << "Get node edge cases test passed" << endl;
}

void testAlternatingInsertDelete() {
    DoublyLinkedList dll;
    
    // Alternating insert and delete operations
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.deleteFromBeginning();
    dll.insertAtPosition(30, 0);
    dll.deleteFromEnd();
    dll.insertAtEnd(40);
    
    assert(dll.getSize() == 2);
    
    string output = captureOutput([&]() { dll.displayForward(); });
    assert(output == "Forward: 30 <-> 40\n");
    
    
    // cout << output << endl;
    cout << "Alternating insert delete test passed" << endl;
}

int main() {
    cout << "Running Doubly Linked List Tests..." << endl << endl;
    
    testConstructorAndSize();
    testInsertAtBeginning();
    testInsertAtEnd();
    testInsertAtPosition();
    testDisplayBackward();
    testDeleteFromBeginning();
    testDeleteFromEnd();
    testDeleteAtPosition();
    testDeleteByValue();
    testSearchNode();
    testGetNode();
    testClear();
    testEmptyListOperations();
    testSingleElementOperations();
    testInsertAtPositionEdgeCases();
    testDeleteAtPositionEdgeCases();
    testDeleteByValueEdgeCases();
    testLargeListOperations();
    testDestructorAndMemoryManagement();
    testMultipleClearOperations();
    testSearchNodeEdgeCases();
    testGetNodeEdgeCases();
    testAlternatingInsertDelete();
    
    cout << endl << "All tests passed!" << endl<<endl;
    return 0;
}
