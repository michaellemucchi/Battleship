#include "Board.h"
#include <iostream>

void BattleShip::Board::auto_fill_in_board() {
    char default_val = '*';
    this->board = std::vector<std::vector<char>>(num_rows, std::vector<char>(num_cols, default_val));
}

void BattleShip::Board::print_the_board() const {
    std::cout << "  ";
    for (int i = 0; i < num_cols; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl; // TOP ROW PRINT

    for (int i = 0; i < num_rows; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < num_cols; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout <<  std::endl; // LAST CHAR IN ROW
    }
}

bool BattleShip::Board::is_on_board(int row_to_place, int col_to_place, std::string direction, int ship_size) {
    if (direction == "h" || direction == "H") {
        for (int j = col_to_place; j < ship_size + col_to_place; j++) {
            if (row_to_place >= 0 && row_to_place < num_rows && j >= 0 && j < num_cols) {
                continue; // just increment, its still in the board
            } else {
                return false;
            }
        }
        return true; // went all the way through

    } else if (direction == "v" || direction == "V") {
        for (int i = row_to_place; i < ship_size + row_to_place; i++) {
            if (i >= 0 && i < num_rows && col_to_place >= 0 && col_to_place < num_cols) {
                continue; // just increment, its still in the board
            } else {
                return false;
            }
        }
        return true; // went all the way through
    } else {
        std::cout << "Surely a glitch" << std::endl;
        return false; // NEVER SHOULD HAPPEN.
    }
}

bool BattleShip::Board::is_not_taken(int row_to_place, int col_to_place, std::string direction, int ship_size) {
    if (direction == "h" || direction == "H") {
        for (int j = col_to_place; j < ship_size + col_to_place; j++) {
            if (board[row_to_place][j] == '*') {
                continue; // just increment, its still a star
            } else {
                return false;
            }
        }
        return true; // went all the way through

    } else if (direction == "v" || direction == "V") {
        for (int i = row_to_place; i < ship_size + row_to_place; i++) {
            if (board[i][col_to_place] == '*') {
                continue; // just increment, its still a star
            } else {
                return false;
            }
        }
        return true; // went all the way through
    } else {
        std::cout << "Surely a glitch" << std::endl;
        return false; // NEVER SHOULD HAPPEN.
    }
}

void BattleShip::Board::put_ship_down(int row_placed, int col_placed, std::string direction, int ship_size, char ship_name) {
    if (direction == "h" || direction == "H") {
        for (int j = col_placed; j < ship_size + col_placed; j++) {
            board[row_placed][j] = ship_name;
        }
    } else if (direction == "v" || direction == "V") {
        for (int i = row_placed; i < ship_size + row_placed; i++) {
            board[i][col_placed] = ship_name;
        }
    }
}

char BattleShip::Board::check_position(int row_placed, int col_placed) const {
    return board[row_placed][col_placed];
}

void BattleShip::Board::edit_board(int row_placed, int col_placed, char change) {
    this->board[row_placed][col_placed] = change;
}

bool BattleShip::Board::scan_board_for_ship(char piece_to_scan) const {
    for (int i = 0; i < get_num_rows(); i++) {
        for (int j = 0; j < get_num_cols(); j++) {
            if (board[i][j] == piece_to_scan) {
                return true;
            }
        }
    }
    return false;
}