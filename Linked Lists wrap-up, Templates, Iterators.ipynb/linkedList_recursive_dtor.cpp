////linkedList_recursive_dtor.cpp
// Example 3a (You try!) - recursive destructor helper
#include <iostream>

struct Node { int data; Node* next; };

class LinkedList {
private:
    Node* head;

    // Recursively deletes node n and everything after it
    void deleteAll(Node* n){
        if(n == nullptr){ 
            return; 
            }
        deleteAll(n->next);
        delete n;


    }

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        deleteAll(head);
    }

    void insert(int n){
        if (head != nullptr){
            Node* current = head;
            while (current->next != nullptr) current = current->next;
            Node* last = new Node; last->data = n; last->next = nullptr;
            current->next = last;
        } else {
            head = new Node; head->data = n; head->next = nullptr;
        }
    }
    void display() const {
        Node* current = head;
        while (current != nullptr){ std::cout << current->data << "->"; current = current->next; }
        std::cout << "nullptr\n";
    }
};

int main(){
    LinkedList list;
    list.insert(10); list.insert(20); list.insert(30);
    list.display();
    return 0;
}