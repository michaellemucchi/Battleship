#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <utility>
#include <vector>
namespace BattleShip {
    class Ship {

    public:
        Ship(char name, int length) : name(name), length(length) {

        }
        char get_name() const {return name;}
        int get_length() const {return length;}
        bool operator< (const Ship& rhs) const {
            return (*this).get_name() < rhs.get_name();
        } //overloaded < operator for ships. sorts by name's ASCII val


    private:
        char name;
        int length;
    };
}

#endif //BATTLESHIP_SHIP_H
