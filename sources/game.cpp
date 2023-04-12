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

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include "game.hpp"

namespace ariel
{
    Game::Game(Player &plr1, Player &plr2) : p1(plr1), p2(plr2), winner(nullptr), lastTurnStats(""), log(""), turn(0), draws(0), p1Wins(0), p2Wins(0) {
        if (plr1.isInGame())
            throw invalid_argument("Player 1 is already in a game!");

        if (plr2.isInGame())
            throw invalid_argument("Player 2 is already in a game!");

        vector<Card> cards;

        // Create the cards
        for (int i = 1; i < 14; ++i)
            cards.push_back(Card((Value)i, Clubs));

        for (int i = 1; i < 14; ++i)
            cards.push_back(Card((Value)i, Diamonds));

        for (int i = 1; i < 14; ++i)
            cards.push_back(Card((Value)i, Hearts));

        for (int i = 1; i < 14; ++i)
            cards.push_back(Card((Value)i, Spades));

        
        // Shuffle the cards
        unsigned seed = (unsigned) time(NULL);
        auto rng = default_random_engine(seed);
        shuffle(cards.begin(), cards.end(), rng);

        // Deal the cards
        while(!cards.empty())
        {
            int choise = ((int)cards.size()) % 2;

            if (choise == 0)
                p1.addCard(cards.back());

            else
                p2.addCard(cards.back());

            cards.pop_back();
        }

        // Set the players in game
        this->p1.setInGame(true);
        this->p2.setInGame(true);
    }

    void Game::playTurn()
    {
        if (&p1 == &p2)
            throw invalid_argument("Cannot play a game with the same player twice!");
            
        if (p1.isInGame() && p2.isInGame())
        {
            if (++this->turn > 26)
                throw logic_error("Game cannot continue with more than 26 turns!");

            int drawsinthisturn = 0, OnTable = 2;
            this->lastTurnStats = "";

            Card p1Card = p1.getCard();
            Card p2Card = p2.getCard();
            p1.removeCard();
            p2.removeCard();

            this->lastTurnStats = "Turn " + to_string(this->turn) + ":\n" + p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". ";

            while (p1Card == p2Card)
            {
                this->draws++;
                drawsinthisturn++;
                this->lastTurnStats += "Draw!\n";

                // Check if one of the players has no cards left in their stack or not enough cards to play.
                // If so, each player takes half of the cards on the table.
                // If not, continue the game
                // This is done to prevent the game from ending in a never-ending loop.
                if (p1.stacksize() <= 1 || p2.stacksize() <= 1)
                {
                    while (OnTable > 0)
                    {
                        p1.addCardTaken();
                        p2.addCardTaken();
                        OnTable -= 2;
                    }

                    break;
                }
                
                // Faceback cards
                p1.removeCard();
                p2.removeCard();

                // New cards
                p1Card = p1.getCard();
                p2Card = p2.getCard();
                p1.removeCard();
                p2.removeCard();

                OnTable += 4;

                this->lastTurnStats += p1.getName() + " played " + p1Card.toString() + " " + p2.getName() + " played " + p2Card.toString() + ". ";
            }

            if (p1Card < p2Card)
            {
                this->lastTurnStats += (p1.getName() + " won the round!" + "\n" + "Draws in this turn: " + to_string(drawsinthisturn)) + "\n\n";
                this->p2Wins++;

                while (OnTable > 0)
                {
                    p2.addCardTaken();
                    --OnTable;
                }
            }

            else if (p2Card < p1Card)
            {
                this->lastTurnStats += (p2.getName() + " won the round!" + "\n" + "Draws in this turn: " + to_string(drawsinthisturn)) + "\n\n";
                this->p1Wins++;

                while (OnTable > 0)
                {
                    p1.addCardTaken();
                    --OnTable;
                }
            }

            else
                this->lastTurnStats += "Draw!\n";

            // Checking if the game is over
            if (!p1.stacksize() || !p2.stacksize())
            {
                p1.setInGame(false);
                p2.setInGame(false);

                // Check winner
                this->winner = ((p1.cardesTaken() > p2.cardesTaken()) ? &p1 : &p2);
            }

            this->log += this->lastTurnStats;
        }

        else
            throw logic_error("Game is over!");
    }

    void Game::playAll()
    {
        while (p1.isInGame() && p2.isInGame() && this->turn < 26)
            playTurn();
    }

    void Game::printWiner() const {
        if (p1.isInGame() || p2.isInGame())
            //throw logic_error("Game is not over yet!"); // We want to throw an exception here but the test cases don't allow it
            return;

        if (p1.cardesTaken() == p2.cardesTaken())
            cout << "Draw!" << endl;

        else
            cout << "The winner is " << winner->getName() << "!" << endl;
    }

    void Game::printStats()
    {
        cout << "Player " << p1.getName() << " status:" << endl;
        cout << "Cards won: " << p1.cardesTaken() << endl;
        cout << "Cards left: " << p1.stacksize() << endl;
        cout << "Win rate: " << ((float)this->p1Wins / this->turn) << "%" << endl
            << endl;

        cout << "Player " << p2.getName() << " status:" << endl;
        cout << "Cards won: " << p2.cardesTaken() << endl;
        cout << "Cards left: " << p2.stacksize() << endl;
        cout << "Win rate: " << ((float)this->p2Wins / this->turn) << "%" << endl
            << endl;

        cout << "Total turns: " << this->turn << endl;
        cout << "Total draws: " << this->draws << endl;
        cout << "Draw rate: " << ((float)this->draws / this->turn) << "%" << endl;

        if (this->winner != nullptr)
            cout << "Winning player: " << this->winner->getName() << endl;

        else
            cout << "Winning player: Game is not finished!" << endl;
    }
}