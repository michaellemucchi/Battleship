#include "Move.h"

bool BattleShip::Move::is_a_hit(Player& attacked_player) {
    if (attacked_player.get_personal_board().check_position(get_row(), get_col()) != '*') {
        return true;
    } else {
        return false;
    }
}

bool BattleShip::Move::has_been_hit(Player& attacked_player) {
    if (attacked_player.get_personal_board().check_position(get_row(), get_col()) == 'X') {
        return true;
    } else {
        return false;
    }
}

bool BattleShip::Move::is_a_miss(Player& attacked_player) {
    if (attacked_player.get_personal_board().check_position(get_row(), get_col()) == '*') {
        return true;
    } else {
        return false;
    }
}

bool BattleShip::Move::was_a_miss(Player& attacked_player) {
    if (attacked_player.get_personal_board().check_position(get_row(), get_col()) == 'O') {
        return true;
    } else {
        return false;
    }
}

bool BattleShip::Move::destroyed_a_ship(Player& attacked_player) {
    if (attacked_player.get_personal_board().scan_board_for_ship(get_changed_piece())) {
        return false;
    } else {
        return true;
    }
}

void BattleShip::Move::carry_out(Player& curr_player, Player& attacked_player) {
    if (is_a_hit(attacked_player)) {
        this->changed_piece = attacked_player.get_personal_board().check_position(get_row(),get_col());
        curr_player.get_firing_board().edit_board(get_row(), get_col(),'X');
        attacked_player.get_personal_board().edit_board(get_row(), get_col(),'X');
        // change opponents personal board and change own firing board. X
    } else if (is_a_miss(attacked_player)) {
        this->changed_piece = '*';
        curr_player.get_firing_board().edit_board(get_row(), get_col(),'O');
        attacked_player.get_personal_board().edit_board(get_row(), get_col(),'O');
        // change opponents personal board and change own firing board. O
    }
}

