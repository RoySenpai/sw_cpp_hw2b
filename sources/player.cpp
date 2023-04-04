/*
 *  Software Systems CPP Course Assignment 2
 *  Copyright (C) 2023  Roy Simanovich
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "player.hpp"

namespace ariel {
    Player::Player(string name = "Default Player"): name(name), inGame(false), hand(new vector<Card>()), taken(new vector<Card>()) {};

    Player::Player(const Player& other): name(other.name), inGame(other.inGame), hand(new vector<Card>()), taken(new vector<Card>()) {
        for (int i = 0; i < other.stacksize(); ++i)
            this->hand->push_back(other.getCard(i));

        for (int i = 0; i < other.cardesTaken(); ++i)
            this->taken->push_back(other.getTaken(i));
    }

    Player::~Player() {
        delete this->hand;
        delete this->taken;
    }

    bool Player::hasCard(Card card) const {
        for (int i = 0; i < this->stacksize(); ++i)
        {
            Card t = this->getCard(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return true;
        }

        return false;
    }

    bool Player::hasTaken(Card card) const {
        for (int i = 0; i < this->cardesTaken(); ++i)
        {
            Card t = this->getTaken(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return true;
        }

        return false;
    }

    int Player::getCardIndex(Card card) const {
        for (int i = 0; i < this->stacksize(); ++i)
        {
            Card t = this->getCard(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return i;
        }

        throw out_of_range("Player doesn't have this card!");
    }

    int Player::getTakenIndex(Card card) const {
        for (int i = 0; i < this->cardesTaken(); ++i)
        {
            Card t = this->getTaken(i);

            if (t.getSuit() == card.getSuit() && t.getValue() == card.getValue())
                return i;
        }

        throw out_of_range("Player hasn't taken this card!");
    }

    void Player::addCard(Card card) { 
        if (this->inGame)
            throw logic_error("Player is already in a game!");
        
        if (this->stacksize() >= 26)
            throw logic_error("Player's hand is full! (26 cards)");

        if (this->hasCard(card))
            throw invalid_argument("Player already has this card!");

        this->hand->push_back(card); 
    }

    void Player::addTaken(Card card) {
        if (!this->inGame)
            throw logic_error("Player isn't in a game!");

        if (this->hasTaken(card))
            throw invalid_argument("Player already has this card!");

        this->taken->push_back(card);
    }

    void Player::removeCard(Card card) {
        if (!this->inGame)
            throw logic_error("Player isn't in a game!");

        if (!this->hasCard(card))
            throw invalid_argument("Player doesn't have this card!");

        this->hand->erase(this->hand->begin() + this->getCardIndex(card));
    }

    void Player::removeTaken(Card card) {
        if (!this->inGame)
            throw logic_error("Player isn't in a game!");

        if (!this->hasTaken(card))
            throw invalid_argument("Player hasn't taken this card!");

        this->taken->erase(this->taken->begin() + this->getTakenIndex(card));
    }

    string Player::getHand() const {
        string str = "";

        for (int i = 0; i < this->stacksize(); i++)
            str += (this->getCard(i)).toString() + " ";

        return str;
    }
}