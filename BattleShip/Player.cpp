#include <iostream>
#include "Player.h"
#include "Validation.h"

void BattleShip::Player::fill_out_board() {
    for(int i = 0; i < ships.size(); i++) {
        personal_board.print_the_board();
        bool valid_placement;
        do {
            std::string direction_input;
            std::string correct_direction;
            std::string input_placement;
            std::string row_to_place;
            std::string col_to_place;

            std::cout << getName() << ", do you want to place " << ships.at(i).get_name() << " horizontally or vertically?" << std::endl << "Enter h for horizontal or v for vertical" << std::endl << "Your choice: ";
            std::cin >> std::ws;
            std::getline(std::cin, direction_input);
            for (int i = 0; i < direction_input.size(); i++) {
                if (direction_input.at(i) == ' ') {
                    continue;
                }
                correct_direction += direction_input.at(i);
            }


            if (!valid_move(correct_direction)) {
                valid_placement = false;
                continue;
            }
            std::cout << getName() << ", enter the row and column you want to place " << ships.at(i).get_name() << ", which is " << ships.at(i).get_length() << " long, at with a space in between row and col: ";
            std::cin >> std::ws;
            std::getline(std::cin, input_placement);
            if (!is_a_number_or_whitespace(input_placement)) {
                valid_placement = false;
                continue;
            }

            bool space_found = false;
            for (int i = 0; i < input_placement.size(); i++) {
                if (input_placement.at(i) == ' ') {
                    space_found = true;
                    continue;
                }
                if (!space_found) {
                    row_to_place+= input_placement.at(i);
                } else {
                    col_to_place+= input_placement.at(i);
                }
            }

            int row_placed = std::stoi(row_to_place);
            int col_placed = std::stoi(col_to_place);
            int ship_size = ships.at(i).get_length();
            char ship_name = ships.at(i).get_name();
            if (is_valid_placement(personal_board, row_placed, col_placed, correct_direction, ship_size)) { // validating ship placement
                personal_board.put_ship_down(row_placed, col_placed, correct_direction, ship_size, ship_name);
                valid_placement = true;
            } else {
                valid_placement = false;
                continue; // if not a valid placement
            }

        } while(!valid_placement);
    }
    personal_board.print_the_board();
}

bool BattleShip::Player::is_valid_placement(Board personal_board, int row_placed, int col_placed, std::string direction, int ship_size) {

    // make sure points are on the board, and that nothing has taken its spot already, and that all vals placed are on board
    if (personal_board.is_on_board(row_placed, col_placed, direction, ship_size)) {
        if (personal_board.is_not_taken(row_placed, col_placed, direction, ship_size)) {
            return true;
        } else {
            return false;
        }
    }
}

bool BattleShip::Player::valid_move(std::string input) {
    if (input == "h" || input == "H" || input == "v" || input == "V") {
        return true;
    } else {
        return false;
    }
}


BattleShip::Move BattleShip::Player::get_move(Player& curr_player, Player& attacked_player) {
    bool good_attack_input;
    int attack_row;
    int attack_col;
    do {
        std::string input_attack;
        std::string row_to_attack;
        std::string col_to_attack;
        std::cout << getName() << ", where would you like to fire?" << std::endl << "Enter your attack coordinate in the form row col: ";
        std::cin >> std::ws;
        std::getline(std::cin, input_attack);
        if (!is_a_number_or_whitespace(input_attack)) {
            good_attack_input = false;
            continue;
        }

    /*    // remove leading whitespace
        for (int i = 0; i < input_attack.size(); i++) {
            if (input_attack.at(i) != ' ') {
                break;
            }

            while (input_attack.at(i) == ' ') {
                input_attack.erase(i);
            }
        }
        */

        //parse the getline into respective variables
        bool space_found = false;
        for (int i = 0; i < input_attack.size(); i++) {
            if (input_attack.at(i) == ' ') {
                space_found = true;
                continue;
            }
            if (!space_found) {
                row_to_attack+= input_attack.at(i);
            } else {
                col_to_attack+= input_attack.at(i);
            }
        }

        attack_row = std::stoi(row_to_attack);
        attack_col = std::stoi(col_to_attack);

        if (attack_row < 0 || attack_row >= attacked_player.get_personal_board().get_num_rows() || attack_col < 0 || attack_col >= attacked_player.get_personal_board().get_num_cols()) { // if attack is on the board
            good_attack_input = false;
            continue;
        }
        if (attacked_player.get_personal_board().check_position(attack_row, attack_col) == 'X' || attacked_player.get_personal_board().check_position(attack_row, attack_col) == 'O') { // see if this has been attacked already
            good_attack_input = false;
            continue;
        }
        good_attack_input = true;

    } while (!good_attack_input);

    return Move(attack_row, attack_col);
}
