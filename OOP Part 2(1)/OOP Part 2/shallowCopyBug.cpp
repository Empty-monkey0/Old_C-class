////shallowCopyBug.cpp
// Example 5b: Copying a Character -- what goes wrong?
#include<iostream>
#include<string>
class Character{
   public:
   std::string name_;
   int lives_, coins_;
   int* history_;
   int history_count_;

   Character(std::string n){
        this->name_ = n; this->lives_ = 3; this->coins_ = 0;
        this->history_ = new int[10];
        for(int i = 0; i < 10; i++) this->history_[i] = 0;
        this->history_count_ = 0;
   }
   void collect_coins(int num_coins){
       this->coins_ += num_coins;
       this->history_[this->history_count_] = num_coins;
       this->history_count_++;
   }
   void show_history() const {
       std::cout << this->name_ << "'s coin history: ";
       for(int i = 0; i < this->history_count_; i++){
           std::cout << this->history_[i] << " ";
       }
       std::cout << "\n";
   }
   void display() const {
        std::cout << this->name_ << ": " << this->lives_ << " lives, " << this->coins_ << " coins\n";
   }
   ~Character(){
        std::cout << "Destructor for " << this->name_ << ", history_ at " << this->history_ << "\n";
        delete[] this->history_;
   }
};
int main(){
    Character m("Mario");
    m.collect_coins(10);
    m.collect_coins(25);

    Character m2 = m;  // default copy
    m2.name_ = "Wario";
    m2.collect_coins(99);

    // Do they share the same history_ pointer?
    std::cout << "m.history_ address:  " << m.history_ << "\n";
    std::cout << "m2.history_ address: " << m2.history_ << "\n";

    m.show_history();
    m2.show_history();  // uh oh...
    // when main ends, both destructors delete[] the SAME memory -- crash!

}

// You try (comment out the main above and uncomment the one below)
// int main(){
//      Character m("Mario");
//      m.collect_coins(10);
//      m.collect_coins(25);
//      Character m2 = m;
//      m2.collect_coins(99);
//      m.show_history();
//      m2.show_history();
// }

// Which values are shared between m and m2? Which are independent? 
// Hint: coins_ and history_count_ are ints, but history_ is a pointer.)