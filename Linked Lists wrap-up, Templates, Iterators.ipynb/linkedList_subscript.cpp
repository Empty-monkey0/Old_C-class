////linkedList_subscript.cpp
// Example 4a (You try!) - overload operator[] to read by position
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
    int operator[](int i){
        Node* current = head;
        for(int k = 0; k < i;++k){
            current = current->next;
        }
        return current->data;

    }
};

int main(){
    LinkedList list;
    list.insert(10); list.insert(20); list.insert(30); list.insert(40);
    std::cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << "\n";
    // once your operator[] is working, try uncommenting the next line:
    // list[2] = 5;
    return 0;
}