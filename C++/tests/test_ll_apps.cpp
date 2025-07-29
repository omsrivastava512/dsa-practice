#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



// Include the header or implementation file if available
// #include "ll_apps.cpp"

// Minimal implementations for testing (since only declarations are provided)
class BrowserHistory {
private:
    struct Page {
        string url;
        Page* prev;
        Page* next;
        Page(const string& u) : url(u), prev(nullptr), next(nullptr) {}
    };
    Page* current;
public:
    BrowserHistory(string homepage) {
        current = new Page(homepage);
    }
    void visit(string url) {
        // Clear forward history when visiting new page
        Page* temp = current->next;
        while (temp) {
            Page* next = temp->next;
            delete temp;
            temp = next;
        }
        current->next = nullptr;
        
        Page* newPage = new Page(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
    string back(int steps) {
        while (steps-- && current->prev) current = current->prev;
        return current->url;
    }
    string forward(int steps) {
        while (steps-- && current->next) current = current->next;
        return current->url;
    }
};

class UndoRedo {
private:
    struct Action {
        string operation;
        string data;
        Action* prev;
        Action* next;
        Action(const string& op, const string& d) : operation(op), data(d), prev(nullptr), next(nullptr) {}
    };
    Action* head = nullptr;
    Action* current = nullptr;
public:
    void execute(string operation, string data) {
        // Clear redo history when executing new action
        if (current && current->next) {
            Action* temp = current->next;
            while (temp) {
                Action* next = temp->next;
                delete temp;
                temp = next;
            }
            current->next = nullptr;
        }
        
        Action* act = new Action(operation, data);
        if (current) {
            current->next = act;
            act->prev = current;
        } else {
            head = act;
        }
        current = act;
    }
    void undo() {
        if (current && current->prev) current = current->prev;
    }
    void redo() {
        if (current && current->next) current = current->next;
    }
    vector<string> getHistory() {
        vector<string> res;
        Action* temp = head;
        while (temp) {
            res.push_back(temp->operation + ":" + temp->data);
            temp = temp->next;
        }
        return res;
    }
    string getCurrentAction() {
        return current ? current->operation + ":" + current->data : "";
    }
};

class Playlist {
private:
    struct Song {
        string title;
        Song* next;
        Song* prev;
        Song(const string& t) : title(t), next(nullptr), prev(nullptr) {}
    };
    Song* head = nullptr;
    Song* current = nullptr;
public:
    void addSong(string title) {
        Song* s = new Song(title);
        if (!head) {
            head = s;
            current = s;
            s->next = s;
            s->prev = s;
        } else {
            Song* tail = head->prev;
            s->next = head;
            s->prev = tail;
            head->prev = s;
            tail->next = s;
        }
    }
    void removeSong(string title) {
        if (!head) return;
        
        Song* temp = head;
        do {
            if (temp->title == title) {
                if (temp->next == temp) { // Only one song
                    head = nullptr;
                    current = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) head = temp->next;
                    if (temp == current) current = temp->next;
                }
                delete temp;
                break;
            }
            temp = temp->next;
        } while (temp != head);
    }
    void playNext() {
        if (current && current->next) current = current->next;
    }
    void playPrevious() {
        if (current && current->prev) current = current->prev;
    }
    void shuffle() {
        if (!head || head->next == head) return;
        current = head;
    }
    string getCurrentSong() {
        return current ? current->title : "";
    }
    int getSize() {
        if (!head) return 0;
        int count = 1;
        Song* temp = head->next;
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class Polynomial {
private:
    struct Term {
        int coefficient;
        int exponent;
        Term* next;
        Term(int c, int e) : coefficient(c), exponent(e), next(nullptr) {}
    };
    Term* head = nullptr;
public:
    void addTerm(int coeff, int exp) {
        if (coeff == 0) return; // Don't add zero coefficients
        
        if (!head || head->exponent < exp) {
            Term* t = new Term(coeff, exp);
            t->next = head;
            head = t;
            return;
        }
        
        Term* temp = head;
        if (temp->exponent == exp) {
            temp->coefficient += coeff;
            if (temp->coefficient == 0) {
                head = temp->next;
                delete temp;
            }
            return;
        }
        
        while (temp->next && temp->next->exponent > exp) {
            temp = temp->next;
        }
        
        if (temp->next && temp->next->exponent == exp) {
            temp->next->coefficient += coeff;
            if (temp->next->coefficient == 0) {
                Term* toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;
            }
        } else {
            Term* t = new Term(coeff, exp);
            t->next = temp->next;
            temp->next = t;
        }
    }
    
    Polynomial add(const Polynomial& other) {
        Polynomial result;
        Term* a = head;
        Term* b = other.head;
        while (a && b) {
            if (a->exponent == b->exponent) {
                int sum = a->coefficient + b->coefficient;
                if (sum != 0) result.addTerm(sum, a->exponent);
                a = a->next; b = b->next;
            } else if (a->exponent > b->exponent) {
                result.addTerm(a->coefficient, a->exponent);
                a = a->next;
            } else {
                result.addTerm(b->coefficient, b->exponent);
                b = b->next;
            }
        }
        while (a) { result.addTerm(a->coefficient, a->exponent); a = a->next; }
        while (b) { result.addTerm(b->coefficient, b->exponent); b = b->next; }
        return result;
    }
    
    Polynomial multiply(const Polynomial& other) {
        Polynomial result;
        for (Term* a = head; a; a = a->next) {
            for (Term* b = other.head; b; b = b->next) {
                result.addTerm(a->coefficient * b->coefficient, a->exponent + b->exponent);
            }
        }
        return result;
    }
    
    void display() {
        if (!head) { cout << "0" << endl; return; }
        Term* temp = head;
        bool first = true;
        while (temp) {
            if (!first && temp->coefficient > 0) cout << " + ";
            else if (temp->coefficient < 0) cout << " - ";
            
            int coeff = abs(temp->coefficient);
            if (temp->exponent == 0) cout << coeff;
            else if (temp->exponent == 1) cout << coeff << "x";
            else cout << coeff << "x^" << temp->exponent;
            
            temp = temp->next;
            first = false;
        }
        cout << endl;
    }
    
    int evaluate(int x) {
        int res = 0;
        Term* temp = head;
        while (temp) {
            res += temp->coefficient * pow(x, temp->exponent);
            temp = temp->next;
        }
        return res;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
    int getDegree() {
        return head ? head->exponent : -1;
    }
};

// Enhanced BrowserHistory Tests
void testBrowserHistoryRigorous() {
    cout << "Testing BrowserHistory rigorously..." << endl;
    
    // Test 1: Basic functionality
    BrowserHistory bh("homepage");
    assert(bh.back(1) == "homepage");
    assert(bh.forward(1) == "homepage");
    
    // Test 2: Multiple visits and navigation
    bh.visit("page1");
    bh.visit("page2");
    bh.visit("page3");
    assert(bh.back(1) == "page2");
    assert(bh.back(2) == "homepage");
    assert(bh.forward(3) == "page3");
    
    // Test 3: Excessive back/forward steps
    assert(bh.back(10) == "homepage");
    assert(bh.forward(10) == "page3");
    
    // Test 4: Visit clears forward history
    bh.back(2);
    assert(bh.back(0) == "page1");
    bh.visit("newpage");
    assert(bh.forward(1) == "newpage");
    
    // Test 5: Empty string URL
    bh.visit("");
    assert(bh.back(0) == "");
    
    // Test 6: Zero steps
    assert(bh.back(0) == "");
    assert(bh.forward(0) == "");
    
    cout << "BrowserHistory rigorous tests passed." << endl;
}

// Enhanced UndoRedo Tests
void testUndoRedoRigorous() {
    cout << "Testing UndoRedo rigorously..." << endl;
    
    UndoRedo ur;
    
    // Test 1: Empty state
    ur.undo();
    ur.redo();
    assert(ur.getHistory().empty());
    
    // Test 2: Single action
    ur.execute("type", "hello");
    assert(ur.getCurrentAction() == "type:hello");
    ur.undo();
    assert(ur.getCurrentAction() == "");
    ur.redo();
    assert(ur.getCurrentAction() == "type:hello");
    
    // Test 3: Multiple actions and navigation
    ur.execute("delete", "h");
    ur.execute("type", "i");
    assert(ur.getHistory().size() == 3);
    ur.undo();
    ur.undo();
    assert(ur.getCurrentAction() == "type:hello");
    
    // Test 4: Execute after undo clears redo
    ur.execute("replace", "world");
    ur.redo(); // Should do nothing
    assert(ur.getCurrentAction() == "replace:world");
    
    // Test 5: Complex sequence
    ur.execute("cut", "text");
    ur.execute("paste", "clipboard");
    ur.undo();
    ur.undo();
    ur.undo();
    assert(ur.getCurrentAction() == "type:hello");
    
    // Test 6: Empty operation/data
    ur.execute("", "");
    assert(ur.getCurrentAction() == ":");
    
    cout << "UndoRedo rigorous tests passed." << endl;
}

// Enhanced Playlist Tests
void testPlaylistRigorous() {
    cout << "Testing Playlist rigorously..." << endl;
    
    Playlist pl;
    
    // Test 1: Empty playlist
    assert(pl.getCurrentSong() == "");
    pl.playNext();
    pl.playPrevious();
    assert(pl.getCurrentSong() == "");
    assert(pl.getSize() == 0);
    
    // Test 2: Single song
    pl.addSong("OnlySong");
    assert(pl.getCurrentSong() == "OnlySong");
    assert(pl.getSize() == 1);
    pl.playNext();
    assert(pl.getCurrentSong() == "OnlySong");
    pl.playPrevious();
    assert(pl.getCurrentSong() == "OnlySong");
    
    // Test 3: Multiple songs circular navigation
    pl.addSong("Song2");
    pl.addSong("Song3");
    assert(pl.getSize() == 3);
    pl.playNext();
    assert(pl.getCurrentSong() == "Song2");
    pl.playNext();
    assert(pl.getCurrentSong() == "Song3");
    pl.playNext();
    assert(pl.getCurrentSong() == "OnlySong");
    
    // Test 4: Remove current song
    pl.removeSong("OnlySong");
    assert(pl.getCurrentSong() == "Song2");
    assert(pl.getSize() == 2);
    
    // Test 5: Remove non-existent song
    pl.removeSong("NonExistent");
    assert(pl.getSize() == 2);
    
    // Test 6: Remove all songs
    pl.removeSong("Song2");
    pl.removeSong("Song3");
    assert(pl.getCurrentSong() == "");
    assert(pl.getSize() == 0);
    
    // Test 7: Empty string song
    pl.addSong("");
    assert(pl.getCurrentSong() == "");
    
    // Test 8: Duplicate songs
    pl.addSong("Duplicate");
    pl.addSong("Duplicate");
    assert(pl.getSize() == 3);
    pl.removeSong("Duplicate");
    assert(pl.getSize() == 2);
    
    cout << "Playlist rigorous tests passed." << endl;
}

// Enhanced Polynomial Tests
void testPolynomialRigorous() {
    cout << "Testing Polynomial rigorously..." << endl;
    
    // Test 1: Empty polynomial
    Polynomial p0;
    assert(p0.isEmpty());
    assert(p0.getDegree() == -1);
    assert(p0.evaluate(5) == 0);
    
    // Test 2: Zero coefficient handling
    Polynomial p1;
    p1.addTerm(0, 5);
    assert(p1.isEmpty());
    p1.addTerm(3, 2);
    p1.addTerm(-3, 2);
    assert(p1.isEmpty());
    
    // Test 3: Constant polynomial
    Polynomial p2;
    p2.addTerm(7, 0);
    assert(p2.evaluate(0) == 7);
    assert(p2.evaluate(100) == 7);
    assert(p2.getDegree() == 0);
    
    // Test 4: Linear polynomial
    Polynomial p3;
    p3.addTerm(2, 1);
    p3.addTerm(3, 0);
    assert(p3.evaluate(0) == 3);
    assert(p3.evaluate(1) == 5);
    assert(p3.evaluate(-1) == 1);
    
    // Test 5: Adding same exponent terms
    Polynomial p4;
    p4.addTerm(5, 3);
    p4.addTerm(3, 3);
    p4.addTerm(-2, 3);
    assert(p4.evaluate(1) == 6);
    
    // Test 6: Complex polynomial operations
    Polynomial p5, p6;
    p5.addTerm(2, 3);
    p5.addTerm(-1, 1);
    p5.addTerm(4, 0);
    p6.addTerm(1, 2);
    p6.addTerm(3, 1);
    p6.addTerm(-2, 0);
    
    Polynomial sum = p5.add(p6);
    assert(sum.evaluate(0) == 2); // 4 + (-2)
    assert(sum.evaluate(1) == 7); // 2 - 1 + 4 + 1 + 3 - 2
    
    // Test 7: Multiplication
    Polynomial prod = p5.multiply(p6);
    assert(prod.evaluate(0) == -8); // 4 * (-2)
    assert(prod.evaluate(1) == 10); // (2-1+4)*(1+3-2)
    
    // Test 8: Negative coefficients
    Polynomial p7;
    p7.addTerm(-5, 2);
    p7.addTerm(-3, 0);
    assert(p7.evaluate(1) == -8);
    assert(p7.evaluate(-1) == -2);
    
    // Test 9: High degree polynomial
    Polynomial p8;
    p8.addTerm(1, 10);
    p8.addTerm(-1, 5);
    p8.addTerm(1, 0);
    assert(p8.evaluate(1) == 1);
    assert(p8.evaluate(0) == 1);
    
    // Test 10: Adding zero polynomial
    Polynomial zero;
    Polynomial p9;
    p9.addTerm(5, 2);
    Polynomial result = p9.add(zero);
    assert(result.evaluate(2) == 20);
    
    cout << "Polynomial rigorous tests passed." << endl;
}

// Stress tests
void stressTests() {
    cout << "Running stress tests..." << endl;
    
    // Browser history with many pages
    BrowserHistory bh("start");
    for (int i = 0; i < 1000; ++i) {
        bh.visit("page" + to_string(i));
    }
    assert(bh.back(500) != "");
    
    // UndoRedo with many actions
    UndoRedo ur;
    for (int i = 0; i < 100; ++i) {
        ur.execute("action", to_string(i));
    }
    for (int i = 0; i < 50; ++i) {
        ur.undo();
    }
    for (int i = 0; i < 25; ++i) {
        ur.redo();
    }
    assert(ur.getHistory().size() == 100);
    
    // Large polynomial
    Polynomial big;
    for (int i = 0; i < 100; ++i) {
        big.addTerm(i % 10 + 1, i);
    }
    assert(big.getDegree() == 99);
    
    cout << "Stress tests passed." << endl;
}

int main() {
    testBrowserHistoryRigorous();
    testUndoRedoRigorous();
    testPlaylistRigorous();
    testPolynomialRigorous();
    stressTests();
    cout << "All rigorous tests passed!" << endl;
    return 0;
}