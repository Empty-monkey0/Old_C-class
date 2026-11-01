/******************************************************************************
 linkedlist.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used (including any AI conversations):
https://chatgpt.com/share/69f38a28-b7ec-83ea-b70f-b41bee0684a9


******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include <iostream> // no other headers should be added

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    // ============== Provided from class (do not modify) ==============
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* runner = head;
        while (runner != nullptr) {
            Node* upcoming = runner->next;
            delete runner;
            runner = upcoming;
        }
    }

    void insert(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* runner = head;
            while (runner->next != nullptr) {
                runner = runner->next;
            }
            runner->next = newNode;
        }
    }

    // ============== Part (a): your code goes here ==============

    int length() const {
        /* YOUR CODE GOES HERE */
        int count = 0;
        Node* runner = head;
        while(runner != nullptr){
            ++ count;
            runner = runner->next;
        }
        return count;
        
    }

    int get(int index) const {
        /* YOUR CODE GOES HERE */
        Node* runner = head;
        for(int i = 0; i < index; ++i){
            runner = runner->next;
        }
        return runner-> data;
        
    }

    void insertAt(int index, int value) {
        /* YOUR CODE GOES HERE */
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if(index == 0){
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = head;
        for(int i = 0; i < index -1; ++i){
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }

    void insertList(const LinkedList& other, int start) {
        /* YOUR CODE GOES HERE */

        int n = other.length();
        for(int i = 0; i < n; ++i){
            insertAt(start + i, other.get(i));
        }
    }

    // friend declaration for operator<< (defined as a free function below)
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

    // ============== Part (b): your code goes here ==============

    
       LinkedList(const LinkedList& other){             // -- copy constructor
            Node* runner = other.head;
            while(runner != nullptr){
                insert(runner -> data);
                runner = runner->next;
            }
        }
       LinkedList& operator=(const LinkedList& other){   //-- copy assignment operator
            if(this == &other){
                return *this;
            }

            Node* runner = head;
            while(runner != nullptr){
                Node* upcoming = runner -> next;
                delete runner;
                runner = upcoming;
            }
            head = nullptr;

            Node* src = other.head;
            while(src != nullptr){
                insert(src->data);
                src = src->next;
            }
            return *this;
        }
};


// operator<< definition (free function, declared above as a friend)
std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    /* YOUR CODE GOES HERE */
    Node* runner = list.head;
    while(runner != nullptr){
        out << runner->data << " -> ";
        runner = runner->next;
    }
    out << "nullptr";
    return out;
}


// ============================================================
// TESTER CODE -- uncomment sections as you implement each part.
// Remove or comment out main() before submitting to Gradescope.
// ============================================================

/*
int main() {
    // --- Part (a) tests ---

    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    std::cout << list << "\n";
    // Expected: 10 -> 20 -> 30 -> 40 -> nullptr

    std::cout << "length: " << list.length() << "\n";
    // Expected: length: 4

    std::cout << "get(2): " << list.get(2) << "\n";
    // Expected: get(2): 30

    list.insertAt(0, 99);
    std::cout << "after insertAt(0, 99): " << list << "\n";
    // Expected: after insertAt(0, 99): 99 -> 10 -> 20 -> 30 -> 40 -> nullptr

    list.insertAt(list.length(), 77);
    std::cout << "after insertAt(end, 77): " << list << "\n";
    // Expected: after insertAt(end, 77): 99 -> 10 -> 20 -> 30 -> 40 -> 77 -> nullptr

    LinkedList other;
    other.insert(7);
    other.insert(8);
    list.insertList(other, 2);
    std::cout << "after insertList(other, 2): " << list << "\n";
    // Expected: after insertList(other, 2): 99 -> 10 -> 7 -> 8 -> 20 -> 30 -> 40 -> 77 -> nullptr

    std::cout << "other (should be unchanged): " << other << "\n";
    // Expected: other (should be unchanged): 7 -> 8 -> nullptr


    // --- Part (b) tests ---

    // LinkedList copy = list;          // uses copy constructor
    // list.insertAt(0, 999);
    // std::cout << "list after modifying:       " << list << "\n";
    // std::cout << "copy (should be unchanged): " << copy << "\n";

    // LinkedList assigned;
    // assigned.insert(1);
    // assigned.insert(2);
    // assigned = copy;                 // uses copy assignment
    // copy.insertAt(0, 0);
    // std::cout << "copy after modifying:           " << copy << "\n";
    // std::cout << "assigned (should be unchanged): " << assigned << "\n";

    return 0;
}
*/
