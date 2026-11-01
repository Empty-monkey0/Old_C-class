#include "areebas_card_v1.h"
#include <iostream>
#include <algorithm>
#include <random>

// Implement BreakAreebasCode's what() method
const char* BreakAreebasCode::what() const noexcept {
    return "WHY MUST YOU BREAK MY CODE";
}

static const std::vector<std::string> _RANK_ORDER = 
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

// Implement Card constructor
Card::Card(std::string r, std::string s) : _rank(r), _suit(s) {}

// Implement Card display function
void Card::display() const {
    std::cout << this->_rank << " of " << this->_suit << std::endl;
}

// Implement Card beats function
bool Card::beats(const Card& other) const {
    auto pos_self = std::find(_RANK_ORDER.begin(), _RANK_ORDER.end(), this->_rank);
    auto pos_other = std::find(_RANK_ORDER.begin(), _RANK_ORDER.end(), other._rank);
    if (pos_self == _RANK_ORDER.end() || pos_other == _RANK_ORDER.end()) {
        throw BreakAreebasCode();
    }
    return std::distance(_RANK_ORDER.begin(), pos_self) > std::distance(_RANK_ORDER.begin(), pos_other);
}


static const std::vector<std::string> _RANKS = 
    {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
static const std::vector<std::string> _SUITS = 
    {"Hearts", "Clubs", "Diamonds", "Spades"};

// Implement Deck constructor
Deck::Deck() : _cards_left(52) {
    for (const auto& r : _RANKS) {
        for (const auto& s : _SUITS) {
            _cards.emplace_back(r, s); // emplace_back creates the object in place instead of copying an object
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_cards.begin(), _cards.end(), g);
}

// Implement Deck draw function
Card Deck::draw() {
    if (_cards_left > 0) {
        _cards_left--;
        Card card = _cards.back();
        _cards.pop_back();
        return card;
    } else {
        throw BreakAreebasCode();
    }
}
