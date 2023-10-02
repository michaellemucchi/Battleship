#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Game.h"
#include "Player.h"
#include <algorithm>


int main(int argc, char** argv) {
    std::ifstream inFile;
    inFile.open(argv[1]);
    std::string input;
    inFile >> input;
    int num_rows = std::stoi(input); // label rows

    inFile >> input;
    int num_cols = std::stoi(input); // label cols

    inFile >> input;
    int num_ships = std::stoi(input); // label num ships

    std::vector<BattleShip::Ship> ships; // label for all ships
    char name_of_ship;
    int length_of_ship;
    for (int i = 0; i < num_ships; i++) {
        inFile >> input;
        name_of_ship = input[0]; // takes in string, turns into character
        inFile >> input;
        length_of_ship = std::stoi(input); // takes in string for length, turn into integer.
        BattleShip::Ship ship(name_of_ship, length_of_ship);
        ships.push_back(ship);
    }
    inFile.close();

    std::sort(ships.begin(),ships.end()); // sort ships



    BattleShip::Board attack_board(num_rows, num_cols); // create an instance of the board
    BattleShip::Board own_board(num_rows, num_cols);

    std::vector<BattleShip::Player> players;

    std::string Player_1_Name;
    std::cout << "Player 1 please enter your name: ";
    std::cin >> Player_1_Name;
    players.push_back(BattleShip::Player(own_board, attack_board, ships, Player_1_Name));
    players.at(0).fill_out_board();

    std::string Player_2_Name;
    std::cout << "Player 2 please enter your name: ";
    std::cin >> Player_2_Name;
    players.push_back(BattleShip::Player(own_board, attack_board, ships, Player_2_Name));
    players.at(1).fill_out_board();

    // create an instance of the game, then run the game using one of its functions
    BattleShip::Game the_game(players, ships);  // vector of ships
    the_game.play_game();

    return 0;
}
