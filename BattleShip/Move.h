#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H
#include "Player.h"
namespace BattleShip {

    class Player;
    class Move {

    public:
        Move(int row, int col) : row_to_attack(row), col_to_attack(col) {}
        bool is_a_hit(Player& attacked_player);
        bool has_been_hit(Player& attacked_player);
        bool is_a_miss(Player& attacked_player);
        bool was_a_miss(Player& attacked_player);
        bool destroyed_a_ship(Player& attacked_player);
        void carry_out(Player& curr_player, Player& attacked_player);
        int get_row() const {return row_to_attack;}
        int get_col() const {return col_to_attack;}
        char get_changed_piece() const {return changed_piece;}
    private:
        int row_to_attack;
        int col_to_attack;
        char changed_piece;
    };
}

#endif //BATTLESHIP_MOVE_H