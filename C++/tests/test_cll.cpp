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

void testEdgeCasesEmpty() {
    CircularLinkedList cll;
    
    // Test operations on empty list
    cll.deleteFromBeginning();
    assert(cll.getSize() == 0);
    
    cll.deleteFromEnd();
    assert(cll.getSize() == 0);
    
    cll.deleteByValue(10);
    assert(cll.getSize() == 0);
    
    // Test invalid position insertions
    cll.insertAtPosition(10, -1);
    assert(cll.getSize() == 0);
    
    cll.insertAtPosition(10, 5);
    assert(cll.getSize() == 0);
    
    cout << "Edge cases empty list test passed." << endl;
}

void testSingleNodeOperations() {
    CircularLinkedList cll;
    
    // Insert single node and test operations
    cll.insertAtBeginning(42);
    assert(cll.getSize() == 1);
    assert(cll.isCircular() == true);
    
    // Delete single node from beginning
    cll.deleteFromBeginning();
    assert(cll.getSize() == 0);
    
    // Insert and delete from end
    cll.insertAtEnd(42);
    assert(cll.getSize() == 1);
    cll.deleteFromEnd();
    assert(cll.getSize() == 0);
    
    // Insert and delete by value
    cll.insertAtPosition(42, 0);
    assert(cll.getSize() == 1);
    cll.deleteByValue(42);
    assert(cll.getSize() == 0);
    
    cout << "Single node operations test passed." << endl;
}

void testInsertAtPositionExtensive() {
    CircularLinkedList cll;
    
    // Test inserting at position 0 (beginning)
    cll.insertAtPosition(10, 0);
    assert(cll.getSize() == 1);
    
    // Test inserting at end position
    cll.insertAtPosition(30, 1);
    assert(cll.getSize() == 2);
    
    // Test inserting in middle
    cll.insertAtPosition(20, 1);
    assert(cll.getSize() == 3);
    
    // Test invalid positions
    int originalSize = cll.getSize();
    cll.insertAtPosition(99, -1);
    assert(cll.getSize() == originalSize);
    
    cll.insertAtPosition(99, 100);
    assert(cll.getSize() == originalSize);
    
    cout << "Insert at position extensive test passed." << endl;
}

void testDeleteByValueExtensive() {
    CircularLinkedList cll;
    
    // Test delete from empty list
    cll.deleteByValue(999);
    assert(cll.getSize() == 0);
    
    // Insert multiple values
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    
    // Delete from beginning
    cll.deleteByValue(10);
    assert(cll.getSize() == 3);
    
    // Delete from middle
    cll.deleteByValue(30);
    assert(cll.getSize() == 2);
    
    // Delete from end
    cll.deleteByValue(40);
    assert(cll.getSize() == 1);
    
    // Try to delete non-existent value
    cll.deleteByValue(999);
    assert(cll.getSize() == 1);
    
    cout << "Delete by value extensive test passed." << endl;
}

void testSearchNodeExtensive() {
    CircularLinkedList cll;
    
    // Search in empty list
    assert(cll.searchNode(10) == nullptr);
    
    // Add elements and search
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    
    // Search existing elements
    Node* node1 = cll.searchNode(10);
    assert(node1 != nullptr);
    
    Node* node2 = cll.searchNode(20);
    assert(node2 != nullptr);
    
    Node* node3 = cll.searchNode(30);
    assert(node3 != nullptr);
    
    // Search non-existing element
    assert(cll.searchNode(99) == nullptr);
    
    cout << "Search node extensive test passed." << endl;
}

void testCircularityMaintenance() {
    CircularLinkedList cll;
    
    // Test with single element
    cll.insertAtEnd(10);
    assert(cll.isCircular() == true);
    
    // Test with multiple elements
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    assert(cll.isCircular() == true);
    
    // Test after deletions
    cll.deleteFromBeginning();
    assert(cll.isCircular() == true);
    
    cll.deleteFromEnd();
    assert(cll.isCircular() == true);
    
    cll.deleteByValue(30);
    assert(cll.isCircular() == true);
    
    // Test after clearing
    cll.clear();
    assert(cll.isCircular() == true);
    
    cout << "Circularity maintenance test passed." << endl;
}

void testMixedOperations() {
    CircularLinkedList cll;
    
    // Complex sequence of operations
    cll.insertAtBeginning(5);
    cll.insertAtEnd(10);
    cll.insertAtPosition(7, 1);
    cll.insertAtBeginning(3);
    cll.insertAtEnd(15);
    
    assert(cll.getSize() == 5);
    assert(cll.isCircular() == true);
    
    // Delete operations
    cll.deleteByValue(7);
    cll.deleteFromBeginning();
    cll.deleteFromEnd();
    
    assert(cll.getSize() == 2);
    assert(cll.isCircular() == true);
    
    // Search remaining elements
    assert(cll.searchNode(5) != nullptr);
    assert(cll.searchNode(10) != nullptr);
    assert(cll.searchNode(7) == nullptr);
    
    cout << "Mixed operations test passed." << endl;
}

void testLargeList() {
    CircularLinkedList cll;
    
    // Insert 100 elements
    for(int i = 0; i < 100; i++) {
        cll.insertAtEnd(i);
    }
    assert(cll.getSize() == 100);
    assert(cll.isCircular() == true);
    
    // Delete every 10th element
    for(int i = 90; i >= 0; i -= 10) {
        cll.deleteByValue(i);
    }
    assert(cll.getSize() == 90);
    assert(cll.isCircular() == true);
    
    // Clear all
    cll.clear();
    assert(cll.getSize() == 0);
    
    cout << "Large list test passed." << endl;
}

void testDestructorAndMemoryManagement() {
    // Test that destructor properly cleans up
    {
        CircularLinkedList cll;
        cll.insertAtEnd(1);
        cll.insertAtEnd(2);
        cll.insertAtEnd(3);
        // Destructor should be called here automatically
    }
    
    // Test multiple clear operations
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.clear();
    cll.clear(); // Should handle empty list
    assert(cll.getSize() == 0);
    
    cout << "Destructor and memory management test passed." << endl;
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
    cout << "Simple tests passed!" << endl;

    testEdgeCasesEmpty();
    testSingleNodeOperations();
    testInsertAtPositionExtensive();
    testDeleteByValueExtensive();
    testSearchNodeExtensive();
    testCircularityMaintenance();
    testMixedOperations();
    testLargeList();
    testDestructorAndMemoryManagement();
    cout << "Advanced tests passed!" << endl;
    
    cout << "All tests passed!" << endl;
    return 0;
}