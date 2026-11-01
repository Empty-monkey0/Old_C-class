/******************************************************************************
 robot.cpp
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):



 Reminder: you are to write your own code.
******************************************************************************
 AI conversation links:
https://chatgpt.com/share/69b87073-0ed0-8001-aee8-0066bd734f0f
 Step 2 (debugging tutor, if used):

 Step 3 (code review):
https://chatgpt.com/share/69b88163-4dac-8001-92cc-0827adfe7acd
******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream>
#include "robot.h" // write the class declaration in the header file; implement the methods here
// No global variables

#include <random>

// this file should not contain a main function, only the method implementations

// randrange() is a standalone helper function (not a class method).
// You can call it from your method implementations.
// returns a random integer between a and b inclusive, with each integer equally likely
int randrange(int a, int b){
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(a, b); // Define the range
    return distr(eng); // returns a random integer between a and b inclusive
}

    Robogame::Robogame(){
        robot_[0] = randrange(0,5);
        robot_[1] = randrange(0,5);
        prize_[0] = randrange(0,5);
        prize_[1] = randrange(0,5);


    }
     // Accessors
    int Robogame::get_robot_row() const {
        return robot_[0];
    }
    int Robogame::get_robot_col() const {
        return robot_[1];
    }
    int Robogame::get_prize_row() const {
        return prize_[0];
    }
    int Robogame::get_prize_col() const {
        return prize_[1];
    }


    //Set section
    void Robogame::set_robot(int i, int j){
        robot_[0] = i;
        robot_[1] = j;
    }

    void Robogame::set_prize(int i, int j){
        prize_[0] = i;
        prize_[1] = j;
    }

// Display section
    void Robogame::display() const {
        bool robot_on_grid = !off_grid();

        for(int row = 0; row < 6; ++row){
            for(int col = 0; col < 6; ++col){

                const bool is_prize = (row == prize_[0] && col ==prize_[1]);
                const bool is_robot = robot_on_grid && (row == robot_[0] && col == robot_[1]);
                if(is_robot && is_prize){
                    std::cout << 'C';

                }
                else if(is_robot){
                    std::cout << 'R';

                }
                else if(is_prize){
                    std::cout << 'P';

                }
                else{
                    std::cout << '.';

                }
            }
            std::cout << '\n';
        }
    } 

//WIn cond
    bool Robogame::win() const {
        return(robot_[0] == prize_[0] && robot_[1] == prize_[1]);

    }

//Off-grid
    bool Robogame::off_grid() const{

        return(robot_[0] < 0 || robot_[0] > 5 || 
                robot_[1] < 0 || robot_[1] > 5);
    }


//steps section
    void Robogame::step(){
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0,0, -1, 1};
        const int dir = randrange(0,3);
        robot_[0] += dr[dir];
        robot_[1] += dc[dir];

    }


