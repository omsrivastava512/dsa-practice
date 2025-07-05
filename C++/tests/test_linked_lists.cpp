#include <iostream>
#include <cassert>
#include <sstream>
#include <functional> 
#include "../linked_lists.cpp"

using namespace std;

// Helper function to capture cout output
string captureOutput(function<void()> func) {
    stringstream buffer;
    streambuf* orig = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(orig);
    return buffer.str();
}

void testConstructorAndBasicOperations() {
    SinglyLinkedList list;
    assert(list.getSize() == 0);
    
    // Test empty list display
    string output = captureOutput([&]() { list.display(); });
    assert(output == "List is empty!\n");
    
    cout << "Constructor and basic operations tests passed!" << endl;
}

void testInsertions() {
    SinglyLinkedList list;
    
    // Test insertAtStart
    list.insertAtStart(10);
    list.insertAtStart(20);
    assert(list.getSize() == 2);
    
    // Test insertAtEnd
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    assert(list.getSize() == 4);
    
    // Test insertAtPosition - Fixed parameter order: (data, pos)
    list.insertAtPosition(25, 2);
    assert(list.getSize() == 5);
    
    // Test display - Added newline expectation
    string output = captureOutput([&]() { list.display(); });
    assert(output == "20 -> 10 -> 25 -> 30 -> 40\n");
    
    cout << "Insertion tests passed!" << endl;
}

void testDeletions() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    // Test deleteFromStart
    list.deleteFromStart();
    assert(list.getSize() == 3);
    
    // Test deleteFromEnd
    list.deleteFromEnd();
    assert(list.getSize() == 2);
    
    // Test deleteByValue
    list.deleteByValue(20);
    assert(list.getSize() == 1);
    
    // Test deleteAtPosition
    list.insertAtEnd(50);
    list.deleteAtPosition(0);
    assert(list.getSize() == 1);
    
    cout << "Deletion tests passed!" << endl;
}

void testSearchOperations() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    // Test findPosition
    assert(list.findPosition(20) == 1);
    assert(list.findPosition(99) == -1);
    
    // Test contains
    assert(list.contains(30) == true);
    assert(list.contains(99) == false);
    
    cout << "Search operation tests passed!" << endl;
}

void testEdgeCases() {
    SinglyLinkedList list;
    
    // Test operations on empty list
    string output = captureOutput([&]() { list.deleteFromStart(); });
    assert(output == "List is empty!\n");
    
    output = captureOutput([&]() { list.deleteFromEnd(); });
    assert(output == "List is empty!\n");
    
    output = captureOutput([&]() { list.deleteByValue(10); });
    assert(output == "List is empty!\n");
    
    // Test single element operations
    list.insertAtStart(100);
    list.deleteFromEnd();
    assert(list.getSize() == 0);
    
    // Test invalid position - these will print error messages
    list.insertAtEnd(10);
    output = captureOutput([&]() { 
        Node* result = list.getNodeAt(-1); 
        assert(result == nullptr);
    });
    
    output = captureOutput([&]() { 
        Node* result = list.getNodeAt(5); 
        assert(result == nullptr);
    });
    
    cout << "Edge case tests passed!" << endl;
}

void testClear() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    
    list.clear();
    assert(list.getSize() == 0);
    
    string output = captureOutput([&]() { list.display(); });
    assert(output == "List is empty!\n");
    
    cout << "Clear test passed!" << endl;
}



void testRemoveDuplicatesSorted() {
    SinglyLinkedList list;
    
    // Test empty list
    list.removeDuplicatesSorted();
    assert(list.getSize() == 0);
    
    // Test single element
    list.insertAtEnd(10);
    list.removeDuplicatesSorted();
    assert(list.getSize() == 1);
    
    // Test no duplicates
    list.clear();
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.removeDuplicatesSorted();
    assert(list.getSize() == 3);
    string output = captureOutput([&]() { list.display(); });
    assert(output == "10 -> 20 -> 30\n");
    
    // Test with duplicates
    list.clear();
    list.insertAtEnd(10);
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.removeDuplicatesSorted();
    assert(list.getSize() == 3);
    output = captureOutput([&]() { list.display(); });
    assert(output == "10 -> 20 -> 30\n");
    
    // Test all same elements
    list.clear();
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.removeDuplicatesSorted();
    assert(list.getSize() == 1);
    output = captureOutput([&]() { list.display(); });
    assert(output == "5\n");
    
    cout << "Remove duplicates sorted tests passed!" << endl;
}

void testRemoveDuplicatesUnsorted() {
    SinglyLinkedList list;
    
    // Test empty list
    list.removeDuplicatesUnsorted();
    assert(list.getSize() == 0);
    
    // Test single element
    list.insertAtEnd(10);
    list.removeDuplicatesUnsorted();
    assert(list.getSize() == 1);
    
    // Test no duplicates
    list.clear();
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.removeDuplicatesUnsorted();
    assert(list.getSize() == 3);
    string output = captureOutput([&]() { list.display(); });
    assert(output == "10 -> 20 -> 30\n");
    
    // Test with unsorted duplicates
    list.clear();
    list.insertAtEnd(30);
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.removeDuplicatesUnsorted();
    assert(list.getSize() == 3);
    output = captureOutput([&]() { list.display(); });
    assert(output == "30 -> 10 -> 20\n");
    
    // Test all same elements
    list.clear();
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.insertAtEnd(5);
    list.removeDuplicatesUnsorted();
    assert(list.getSize() == 1);
    output = captureOutput([&]() { list.display(); });
    assert(output == "5\n");
    
    cout << "Remove duplicates unsorted tests passed!" << endl;
}

void testReverseIterativeUsingNewNode() {
    SinglyLinkedList list;
    
    // Test empty list
    list.reverseIterativeUsingNewNode();
    assert(list.getSize() == 0);
    
    // Test single element
    list.insertAtEnd(10);
    list.reverseIterativeUsingNewNode();
    assert(list.getSize() == 1);
    string output = captureOutput([&]() { list.display(); });
    assert(output == "10\n");
    
    // Test multiple elements
    list.clear();
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    list.reverseIterativeUsingNewNode();
    
    // Verify reversed order
    output = captureOutput([&]() { list.display(); });
    assert(output == "40 -> 30 -> 20 -> 10\n");
    assert(list.getSize() == 4);
    
    cout << "Reverse iterative using new node tests passed!" << endl;
}

void testReverseIterative() {
    SinglyLinkedList list;
    
    // Test empty list
    list.reverseIterative();
    assert(list.getSize() == 0);
    cout << "Empty passed!" << endl;
    
    // Test single element
    list.insertAtEnd(10);
    list.reverseIterative();
    assert(list.getSize() == 1);
    string output = captureOutput([&]() { list.display(); });
    assert(output == "10\n");
    cout << "Single passed!" << endl;
    
    // Test multiple elements
    list.clear();
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    cout << "Multi passed!" << endl;
    
    output = captureOutput([&]() { list.display(); });
    assert(output == "10 -> 20 -> 30 -> 40\n");
    
    list.reverseIterative();
    
    // Verify reversed order
    output = captureOutput([&]() { list.display(); });
    assert(output == "40 -> 30 -> 20 -> 10\n");
    assert(list.getSize() == 4);
    cout << "Rev passed!" << endl;
    
    cout << "Reverse iterative tests passed!" << endl;
}



int main() {
    testConstructorAndBasicOperations();
    testInsertions();
    testDeletions();
    testSearchOperations();
    testEdgeCases();
    testClear();
    testRemoveDuplicatesSorted();
    testRemoveDuplicatesUnsorted();
    // testReverseIterativeUsingNewNode();
    testReverseIterative();
    
    cout << "All tests passed successfully!" << endl;
    return 0;
}
