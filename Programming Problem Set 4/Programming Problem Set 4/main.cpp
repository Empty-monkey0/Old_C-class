/******************************************************************************
 main.cpp
******************************************************************************
 Name:Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):



 Reminder: you are to write your own code.
******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include <iostream>
#include "robot.h"
/*
class Robogame{
    private:
    int robot_[2];
    int prize_[2];
    public:
    Robogame();

    int get_robot_row() const;
    int get_robot_col() const;
    int get_prize_col() const;
    int get_prize_row() const;

    void set_robot(int i, int j);
    void set_prize(int i, int j);
    void display() const;
    bool win() const;
    bool off_grid() const;
    void step();

};
*/

// After testing your class with the tester code below, comment out the test code.
// Then write your code for the simulation.
// Only your code for the simulation should be submitted.

int main(){

/*
 Uncomment this code after you write the constructor and getters
*/

// Robogame test_game;
// std::cout << test_game.get_prize_row() << ", " << test_game.get_prize_col() << " and ";
// std::cout << test_game.get_robot_row() << ", " << test_game.get_robot_col() << " ";
// std::cout << "(should be 2 pairs of integers, different for each run)\n";

/*
 Uncomment this code after you write set_robot() and set_prize()
*/


// test_game.set_robot(2,3);
// test_game.set_prize(3,4);
// std::cout << test_game.get_robot_row() << ", " << test_game.get_robot_col() << " and ";
// std::cout << test_game.get_prize_row() << ", " << test_game.get_prize_col() << " ";
// std::cout << "(should be 2, 3 and 3, 4)\n";

/*
 Uncomment this code after you write display()
*/


// std::cout << "You should see a grid below with one R and one P:\n";
// test_game.display();

/*
 Uncomment this code after you write win()
*/


// std::cout << test_game.win() << " (should be 0)\n";
// test_game.set_robot(1,4);
// test_game.set_prize(1,4);
// std::cout << test_game.win() << " (should be 1)\n";

/*
 Uncomment this code after you write off_grid()
*/


// std::cout << test_game.off_grid() << " (should be 0)\n";
// test_game.set_robot(-1,2);
// std::cout << test_game.off_grid() << " (should be 1)\n";

/*
 Uncomment this code after you write step()
*/


// test_game.set_robot(3,3);
// test_game.display();
// std::cout << "Robot should move one square in a random direction each time:\n";
// test_game.step();
// test_game.display();
// std::cout << "\n";
// test_game.step();
// test_game.display();

/**** Write your simulation code below ****/
    const int total_games = 50000;
    int wins = 0;
    for(int i = 0; i < total_games; i++){
        Robogame game;

        while(!game.win() && !game.off_grid()){
            game.step();
        }

        if(game.win()){
            wins++;

        }
    }
    std::cout << "Games won: " << wins << " out of " << total_games << "\n";
    std::cout << "Win rate: " << (double)wins / total_games * 100 << "%\n";

    return 0; 
}
