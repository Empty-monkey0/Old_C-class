#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <random>

class BreakAreebasCode : public std::exception {
public:
    const char* what() const noexcept override {
        return "WHY MUST YOU BREAK MY CODE";
    }
};
static const std::vector<std::string> _RANK_ORDER = 
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

class Card {
private:
    static const std::vector<std::string> _rank_order;
    std::string _rank;
    std::string _suit;

public:
    Card(std::string r = "None", std::string s = "None") : _rank(r), _suit(s) {}

    void display() const {
        std::cout << _rank << " of " << _suit << std::endl;
    }

    bool beats(const Card& other) const {
        auto pos_self = std::find(_RANK_ORDER.begin(), _RANK_ORDER.end(), this->_rank);
        auto pos_other = std::find(_RANK_ORDER.begin(), _RANK_ORDER.end(), other._rank);
        if (pos_self == _RANK_ORDER.end() || pos_other == _RANK_ORDER.end()) {
            throw BreakAreebasCode();
        }
        return std::distance(_RANK_ORDER.begin(), pos_self) > std::distance(_RANK_ORDER.begin(), pos_other);
    }
};

static const std::vector<std::string> _RANKS = 
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
static const std::vector<std::string> _SUITS = 
    {"Hearts", "Clubs", "Diamonds", "Spades"};

class Deck {
private:
    int _cards_left;
    std::vector<std::vector<bool>> _drawn; // vector of vectors -- contains 4 vectors, each of 13 bools

public:
    Deck() : _cards_left(52), _drawn(4, std::vector<bool>(13, false)) {}

    Card draw() {
        std::random_device rd1; // Obtain a random number from hardware
        std::random_device rd2; // Obtain a random number from hardware
        std::mt19937 eng1(rd1()); // Seed the generator
        std::mt19937 eng2(rd2()); // Seed the generator
        std::uniform_int_distribution<> distr_suit(0, 3); // Define the range
        std::uniform_int_distribution<> distr_rank(0, 12); // Define the range

        if (_cards_left > 0) {
            _cards_left--;
            int s = distr_suit(eng1);
            int r = distr_rank(eng2);
            while (_drawn[s][r]) {
                s = distr_suit(eng1);
                r = distr_rank(eng2);
            }
            _drawn[s][r] = true;
            return Card(_RANKS[r], _SUITS[s]);
        } else {
            throw BreakAreebasCode();
        }
    }
};


