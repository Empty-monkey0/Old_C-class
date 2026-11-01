/******************************************************************************
 robot.h
******************************************************************************
 Name: Tauseen Ahmed
******************************************************************************
 Collaborators/outside sources used
(IMPORTANT! Write "NONE" if none were used):



 Reminder: you are to write your own code.
******************************************************************************
 AI conversation links:
All are on robot .cpp file
 Step 2 (debugging tutor, if used):

 Step 3 (code review):

******************************************************************************
 Overall notes (not to replace inline comments):


*/

#include<iostream> // no other headers should be added here

// this file should not contain a main function
// The Robogame class should be defined here (declarations only)

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



