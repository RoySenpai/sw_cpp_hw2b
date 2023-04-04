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
#include "game.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player &plr1, Player &plr2) : p1(plr1), p2(plr2), winner(nullptr), cards(new vector<Card>()), lastTurnStats(""), log(""), turn(0), draws(0) {
        if (plr1 == plr2)
            throw invalid_argument("Player 1 and PLayer 2 are the same player!");

        if (plr1.isInGame())
            throw invalid_argument("Player 1 is already in a game!");

        if (plr2.isInGame())
            throw invalid_argument("Player 2 is already in a game!");

        this->p1.setInGame(true);
        this->p2.setInGame(true);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j < 14; j++)
            {
                switch (i)
                {
                    case 0:
                        cards->push_back(Card((Value)j, Clubs));
                        break;

                    case 1:
                        cards->push_back(Card((Value)j, Diamonds));
                        break;

                    case 2:
                        cards->push_back(Card((Value)j, Hearts));
                        break;

                    case 3:
                        cards->push_back(Card((Value)j, Spades));
                        break;
                }
            }
        }

        for (int p = 0; p < 52; ++p)
        {
            int i = rand() % cards->size();

            if (p % 2 == 0)
                p1.addCard(cards->at(i));

            else
                p2.addCard(cards->at(i));

            cards->erase(cards->begin() + i);
        }
    }

    void Game::playTurn()
    {
        if (p1.isInGame() == true && p2.isInGame() == true)
            this->turn++;

        else
            throw logic_error("Game is over!");
    }

    void Game::playAll()
    {
        cout << "playAll" << endl;

        p1.setInGame(false);
        p2.setInGame(false);
    }

    void Game::printStats()
    {
        cout << "Player " << p1.getName() << " status:" << endl;
        cout << "Cards won: " << p1.cardesTaken() << endl;
        cout << "Cards left: " << p1.stacksize() << endl;
        cout << "Win rate: " << p1.cardesTaken() / 26 * 100 << "%" << endl
            << endl;

        cout << "Player " << p2.getName() << " status:" << endl;
        cout << "Cards won: " << p2.cardesTaken() << endl;
        cout << "Cards left: " << p2.stacksize() << endl;
        cout << "Win rate: " << p2.cardesTaken() / 26 * 100 << "%" << endl
            << endl;
    }
}