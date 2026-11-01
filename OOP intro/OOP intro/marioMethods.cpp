////marioMethods.cpp
// Example 11a: Mario methods
#include<iostream>
#include<string>
class Character{
    /*
    A class for game characters (in a Mario Bros-style game)
    Attributes: name, lives, coins
    */
   public: std::string name_; int lives_, coins_;
   Character(std:: string n){
        /* Initialize characters with lives = 3, coins = 0 */
        this->name_ = n; this->lives_ = 3; this-> coins_ = 0;
   }   
   void display() const {
        /* Display character information to the console. */
        std::cout << this->name_ << ": " << this->lives_ << " lives, " << this->coins_ << " coins\n";
   }
    // collect_coins() method:
    void collect_coins(int amount){
        coins_ += amount;
    }
    
    
    
    // die() method:
    bool die(){
        this->
        
    }
    
}; 
    
        
/*********/
// Client code: what should this do?
int main(){
    Character m("Mario");
    m.display();
    m.collect_coins(100);
    m.display();
    m.die();
    m.display();
    std::cout << m.die() << "\n"; // 1 life left, should print 1
    std::cout << m.die() << "\n"; // 0 lives left, should print 0 now
}