#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <string>

namespace BattleShip {
    class Board {
    public:
        Board(int arg1, int arg2) : num_rows(arg1), num_cols(arg2) {
            auto_fill_in_board();
        };
        void auto_fill_in_board();
        void print_the_board() const; // Prints a board
        int get_num_rows() const {return num_rows;}
        int get_num_cols() const {return num_cols;}
        bool is_on_board(int row_to_place, int col_to_place, std::string direction, int ship_size);
        bool is_not_taken(int row_to_place, int col_to_place, std::string direction, int ship_size);
        void put_ship_down(int row_placed, int col_placed, std::string direction, int ship_size, char ship_name);
        char check_position(int row_placed, int col_placed) const;
        void edit_board(int row_placed, int col_placed, char change);
        bool scan_board_for_ship(char piece_to_scan) const;
    private:
        std::vector<std::vector<char>> board;
        int num_rows;
        int num_cols;

    };
}

#endif //BATTLESHIP_BOARD_H