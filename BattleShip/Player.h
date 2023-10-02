#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include "Board.h"
#include "Move.h"
#include "Ship.h"

namespace BattleShip {
    class Move;
    class Player {
    public:
        Player (Board personal_board, Board attack_board, std::vector<Ship> ships, std::string name) : personal_board(personal_board), firing_board(attack_board), ships(ships), name(name) {
        }

        bool valid_move(std::string input);
        bool is_valid_placement(Board personal_board, int row_to_place, int col_to_place, std::string direction, int ship_size);
        void print_personal_board() const {personal_board.print_the_board();}
        void print_firing_board() const {firing_board.print_the_board();}
        const std::string& getName() const {return name;}
        void fill_out_board();
        Board& get_personal_board() {return personal_board;}
        Board& get_firing_board() {return firing_board;}
        Move get_move(Player& curr_player, Player& attacked_player);

    private:
        std::string name;
        Board personal_board;
        Board firing_board;
        std::vector<Ship> ships;

    };
}

#endif //BATTLESHIP_PLAYER_H