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

namespace ariel {
    Game::Game(Player& plr1, Player& plr2): p1(plr1), p2(plr2) {
        if (plr1.getName().empty())
            throw invalid_argument("Player 1 has no name!");

        else if (plr2.getName().empty())
            throw invalid_argument("Player 2 has no name!");

        else if (plr1.getName() == plr2.getName())
            throw invalid_argument("Player 1 and PLayer 2 are the same player!");

        else if (plr1.isInGame() == true)
            throw invalid_argument("Player 1 is already in a game!");

        else if (plr2.isInGame() == true)
            throw invalid_argument("Player 2 is already in a game!");

        else
        {
            this->p1 = plr1;
            this->p2 = plr2;
            this->turn = 0;

            this->p1.setInGame(true);
            this->p2.setInGame(true);

            for (int i = 0; i < 4; i++)
            {
                for (int j = 1; j < 14; j++)
                {
                    switch (i)
                    {
                        case 0:
                            cards.push_back(Card(j, 'C'));
                            break;

                        case 1:
                            cards.push_back(Card(j, 'D'));
                            break;

                        case 2:
                            cards.push_back(Card(j, 'H'));
                            break;

                        case 3:
                            cards.push_back(Card(j, 'S'));
                            break;
                    }
                }
            }

            for (int p = 0; p < 52; ++p)
            {
                int i = rand() % cards.size();

                if (p % 2 == 0)
                    p1.addCard(cards[i]);

                else
                    p2.addCard(cards[i]);

                cards.erase(cards.begin() + i);
            }
        }
    }

    // play a single turn
    void Game::playTurn() {
        if (p1.isInGame() == true && p2.isInGame() == true)
            this->turn++;

        else
            throw logic_error("Game is over!");
    }

    // print the last turn stats.
    void Game::printLastTurn() {
        if (turn > 0)
            cout << "printLastTurn" << endl;

        else
            //throw logic_error("No turns have been played yet!");
            cout << "No turns have been played yet!" << endl;
    }

    //playes the game untill the end
    void Game::playAll() {
        cout << "playAll" << endl;

        p1.setInGame(false);
        p2.setInGame(false);
    }

    // prints the name of the winning player
    void Game::printWiner() {
        if (p1.cardesTaken() == 26 && p1.stacksize() == 52)
            cout << p1.getName() << " wins" << endl;

        else if (p2.cardesTaken() == 26 && p2.stacksize() == 52)
            cout << p2.getName() << " wins" << endl;

        else
            cout << "Game is not finished yet!" << endl;
    }

    // prints all the turns played one line per turn (same format as game.printLastTurn())
    void Game::printLog() {
        cout << "printLog" << endl << endl;
    }

    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    void Game::printStats() {
        cout << "Player " << p1.getName() << " status:" << endl;
        cout << "Cards won: " << p1.cardesTaken() << endl;
        cout << "Cards left: " << p1.stacksize() << endl;
        cout << "Win rate: " << p1.cardesTaken() / 26 * 100 << "%" << endl << endl;

        cout << "Player " << p2.getName() << " status:" << endl;
        cout << "Cards won: " << p2.cardesTaken() << endl;
        cout << "Cards left: " << p2.stacksize() << endl;
        cout << "Win rate: " << p2.cardesTaken() / 26 * 100 << "%" << endl << endl;
    }
}