#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H
#include <vector>
#include "Player.h"
#include <memory>
#include "Move.h"

namespace BattleShip {
    class Game {
    public:
        Game(std::vector<Player>& players, const std::vector<Ship>& ships) : active_players(players), ships(ships) {} // setup game constructor

        void play_game();
        bool is_game_over(int& curr_player);
        void declare_results(const int& curr_player) const;
        void change_to_next_player(int& curr_player);
        void print_current_game_status(const int& curr_player) const;
        void announce_turn_results(Move& move, Player& player1, Player& attacked_player, int& curr_player) const;

    private:
        std::vector<Player> active_players;
        std::vector<Ship> ships;
    };
}

#endif // BATTLESHIP_GAME_H

