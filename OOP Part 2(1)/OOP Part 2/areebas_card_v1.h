#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <random>

class BreakAreebasCode : public std::exception {
public:
    const char* what() const noexcept override;
};

class Card {
public:
    std::string _rank;
    std::string _suit;

    Card(std::string r = "None", std::string s = "None");
    void display() const;
    bool beats(const Card& other) const;
};

class Deck {
public:
    int _cards_left;
    std::vector<Card> _cards;

    Deck();
    Card draw();
};

