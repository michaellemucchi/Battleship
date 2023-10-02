#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Move.h"

void BattleShip::Game::play_game() {
    int curr_player = 0;
    do {
        print_current_game_status(curr_player);
        int other_player = (curr_player + 1) % 2;
        Move move = active_players.at(curr_player).get_move(active_players.at(curr_player), active_players.at(other_player));
        move.carry_out(active_players.at(curr_player), active_players.at(other_player));
        announce_turn_results(move, active_players.at(curr_player), active_players.at(other_player), curr_player);
        change_to_next_player(curr_player);
    } while(not is_game_over(curr_player));
    declare_results(curr_player);
}

bool BattleShip::Game::is_game_over(int& curr_player) {
    for (int i = 0; i < ships.size(); i++) { // go through each ship, check opponents board, if ship not there continue, else return false
        if (active_players.at(curr_player).get_personal_board().scan_board_for_ship(ships.at(i).get_name())) {
            return false;
        }
    }
    return true;
}

void BattleShip::Game::change_to_next_player(int& curr_player) {
    /*
      Change to the next player. Wraps around if past the actual number of players.
    */
    curr_player = (curr_player + 1) % 2;
}

void BattleShip::Game::print_current_game_status(const int& curr_player) const {
    /*
      Print the player's firing board
      Print the player's personal board
    */
    std::cout << active_players.at(curr_player).getName() << "'s Firing Board" << std::endl;
    active_players.at(curr_player).print_firing_board();
    std::cout << std::endl;
    std::cout << std::endl << active_players.at(curr_player).getName() << "'s Placement Board" << std::endl;
    active_players.at(curr_player).print_personal_board();
}

void BattleShip::Game::announce_turn_results(Move& move, Player& player1, Player& attacked_player, int& curr_player) const {
    /*
      Print what happened as a result of the turn.
      1. Hit opponent's X ship
      2. Miss
      3. Destroyed opponent's X ship.
    */
    if (move.has_been_hit(attacked_player) && move.destroyed_a_ship(attacked_player)) {
        print_current_game_status(curr_player);
    }
    if (move.has_been_hit(attacked_player)) {
        std::cout << player1.getName() << " hit " << attacked_player.getName() << "'s " << move.get_changed_piece() << "!" << std::endl;
    } else if (move.was_a_miss(attacked_player)) {
        std::cout << "Missed." << std::endl << std::endl;
    } else {
        std::cout << "error with announcing results" << std::endl;
    }
    if (move.destroyed_a_ship(attacked_player)) { // if changed_piece is not on opponents board
        std::cout << player1.getName() << " destroyed " << attacked_player.getName() << "'s " << move.get_changed_piece() << "!" << std::endl << std::endl; // Print that it destroyed an opponent's ship
    }
}

void BattleShip::Game::declare_results(const int& curr_player) const {
    int winner = (curr_player + 1) % 2;
    std::cout << active_players.at(winner).getName() << " won the game!" << std::endl;
}