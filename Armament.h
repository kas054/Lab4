//
// Created by PC on 15.11.2021.
//

#ifndef LAB4_3SEM_ARMAMENT_H
#define LAB4_3SEM_ARMAMENT_H
#include <iostream>
namespace Basic {
    class Armament {
    private:
        std::string type;
        int properties[6] = {0}; //damage, speed, range, max_ammunition, cur_ammunition, cost
    public:
        Armament() {};
        Armament(std::string new_type, int damage, int speed,
                 int range, int max_ammunition, int cost);

        int get_property(int i) const { return properties[i]; }

        std::string get_type() const { return type; }

        void change_property(int i, int new_value);

        void change_type(std::string new_type) { type = new_type; }

        int shoot();

        friend std::ostream &operator<<(std::ostream &, const Armament &);

        friend std::istream &operator>>(std::istream &, Armament &);
    };

    struct Coordinate{
        int x;
        int y;
    };

    struct Capitan{
        std::string name;
        std::string rank;
    };

    std::ostream &operator<<(std::ostream &, const Capitan &);
    std::ostream &operator<<(std::ostream &, const Coordinate &);
}

#endif //LAB4_3SEM_ARMAMENT_H
