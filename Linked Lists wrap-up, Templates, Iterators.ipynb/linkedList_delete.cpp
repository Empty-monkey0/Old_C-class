////linkedList_delete.cpp
// Example 2a (You try!) - finish the deleteNode method
#include <iostream>

struct Node { int data; Node* next; };

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList(){
        Node* current = head;
        while (current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
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

    // your code:
    void deleteNode(int n){
        //what if first element's data is = n
        // What if we reach the end and didnt find n
        if(head != nullptr){
            Node* runner = head;
            Node* nextNode = head->next; // we check if it is a nullptr and it can be a nullptr
            while(nextNode->data != n && nextNode->next != nullptr){ // deleting by value not by index and can appear multiple times
               runner = nextNode;
                nextNode = nextNode->next;
            }
            if(nextNode->data == n){
                //we've reached the corerct nde to delete and need to rewire
                runner->next = nextNode->next;
                delete nextNode;
            }
        }

    }
};

int main(){
    LinkedList list;
    list.insert(10); list.insert(20); list.insert(30); list.insert(40);
    list.display();              // 10->20->30->40->nullptr
    list.deleteNode(20);
    list.display();              // 10->30->40->nullptr
    list.deleteNode(10);
    list.display();
    return 0;
}